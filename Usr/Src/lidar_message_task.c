#include "lidar_message_task.h"
#include "usart.h"
#include "stm32h7xx_hal_uart_ex.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "RTOS.h"
#include "camera_trigger_task.h"

OS_TASK* lidar_message_taskid;
char rx_buffer[GPSBUFSIZE + GPS_BUF_OFFSET];
GPS_t GPS;
char Lidar_GPRMC[GPSBUFSIZE];
uint8_t comma_index[12];
char utc[7];
char date[7];

static OS_TIMER Timer_Fake_PPS;
static OS_TIMER Timer_Trig_Cam;
static OS_TIMER Timer_Check;

volatile OS_U64 Time_Since_PPS_us;
volatile OS_U64 Time_PPS_IN_us;
volatile OS_U64 Time_Trig_Cam;
volatile OS_U64 Time_Trig_LidIMU;
volatile OS_U64 Time_GPS_Send;
volatile OS_U64 Time_Lidar_IMU_Reset; 

uint32_t Set_Occupation = 50000;
uint32_t Message_interval = 60000;
uint32_t Camera_Period = 20000;
uint64_t Since_UTC = 0;

uint8_t Lidar_IMU_Tri_Flag = 0;
uint8_t Camera_Tri_Flag = 0;
uint8_t Prepare_send_data = 0;
uint8_t Usart_Data_Freshed = 0;
uint8_t enable_auto_send = 0;

static void Timer_Check_CB(void)
{
  OS_U64 Timer_Time = OS_TIME_Get_us();

  if(Lidar_IMU_Tri_Flag)
  {
    if((Timer_Time - Time_Trig_LidIMU) > Set_Occupation)
    {
      HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_RESET);
      HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_RESET);
      Time_Lidar_IMU_Reset = Timer_Time;
      Lidar_IMU_Tri_Flag = 0;
      Prepare_send_data = 1;
    }
  }

  if(Camera_Tri_Flag)
  {
    if(Timer_Time - Time_Trig_Cam > Camera_Period)
    {
      HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
      Camera_Tri_Flag = 0;
    }
  }

  if(Prepare_send_data)
  {
    if(((Timer_Time - Time_Lidar_IMU_Reset) > Message_interval) & Usart_Data_Freshed)
    {
        // send data
	OS_TASKEVENT_Set(lidar_message_taskid, EVENT_GPIO_0);
       	Prepare_send_data = 0;
        Usart_Data_Freshed = 0;
    }
  }

  OS_TIMER_Restart(NULL);
}

static void Timer_FakePPS_CB(void)
{
  OS_U64 Timer_Time = OS_TIME_Get_us();

  if(!Camera_Tri_Flag) //&& enable_auto_send)
  {
  // trigger camera
    HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
    Time_Trig_Cam = OS_TIME_Get_us();
    Camera_Tri_Flag = 1;
    OS_TASKEVENT_Set(camera_report_taskid, EVENT_CAMERA);
  }
  if((Timer_Time - Time_PPS_IN_us) > 1500000)
  {
    //触发IMU与Lidar (highest priority in this interrupt callback function) 	
    HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_SET);
    Time_Trig_LidIMU = OS_TIME_Get_us();
    Lidar_IMU_Tri_Flag = 1;
    //重置tim4
    OS_TIMER_Stop(&Timer_Trig_Cam);
    OS_TIMER_Restart(&Timer_Trig_Cam);
  }

  OS_TIMER_Restart(NULL);
}

static void Timer_Trig_Cam_CB(void)
{
  if(!Camera_Tri_Flag) //&& enable_auto_send)
  {
    HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
    Time_Trig_Cam = OS_TIME_Get_us();
    Camera_Tri_Flag = 1;
    OS_TASKEVENT_Set(camera_report_taskid, EVENT_CAMERA);
  }

  OS_TIMER_Restart(NULL);
}

void GPS_Init(void)
{
  memset(comma_index, 0, 12);
  memset(utc, 0, 7);
  memset(date, 0, 7);
  memset(rx_buffer, 0, GPSBUFSIZE + GPS_BUF_OFFSET);
  SCB_InvalidateDCache_by_Addr((uint32_t*)(((uint32_t)rx_buffer) & ~(uint32_t)0x1F), GPSBUFSIZE + GPS_BUF_OFFSET);
  HAL_UARTEx_ReceiveToIdle_DMA(&huart1, (uint8_t*)rx_buffer, GPSBUFSIZE);

  OS_TIMER_Create(&Timer_Check, Timer_Check_CB, 14); //tick once per 14 ms
  OS_TIMER_Start(&Timer_Check);
  OS_TIMER_Create(&Timer_Fake_PPS, Timer_FakePPS_CB, 1000);
  OS_TIMER_Create(&Timer_Trig_Cam, Timer_Trig_Cam_CB, 50); 
}

uint8_t GPS_validate(char *nmeastr)
{
  volatile int validata_index = 0;
  int16_t  validata_checksum = 0;
  uint8_t  transmitted_checksum[2];
  if(nmeastr[validata_index] == '$'){validata_index++;}
  else{ return 0;}
  		
  //校验位
  while((nmeastr[validata_index] != '*') && (validata_index < GPSBUFSIZE))
  {
    validata_checksum ^= nmeastr[validata_index];// calculate the checksum
    validata_index++;
  }

  if(validata_index >= GPSBUFSIZE){
    return 0;// the string was too long so return an error
  }

  if (nmeastr[validata_index] == '*'){
    transmitted_checksum[0] = nmeastr[validata_index+1];    //put hex chars in check string
    transmitted_checksum[1] = nmeastr[validata_index+2];
    }
  else
    return 0;// no checksum separator found there for invalid, ! Can not reach here !

  return(((validata_checksum&0xFF) == transmitted_checksum[0]) && ((validata_checksum>>8) == transmitted_checksum[1])) ? 1 : 0 ;
}

void GPS_parse(char *GPSstrParse)
{
  if (!strncmp(GPSstrParse, "$GPRMC", 6))
  {
    int i = 0;	
    int index_comma = 0;
    while(GPSstrParse[i] != '*')
    {
      //记录逗号index
      if(GPSstrParse[i] == ',')
      {
        comma_index[index_comma] = i;
	index_comma++;
      }
      i++;
    }
      //用来判断是否收到了UTC与Date
    if(((comma_index[1] - comma_index[0]) >= 7) && ((comma_index[9] - comma_index[8]) == 7))
    {
      //将UTC与Date转换为int
      memcpy(utc,&(GPSstrParse[comma_index[0]+1]), 6); // only need integer seconds
      memcpy(date,&(GPSstrParse[comma_index[8]+1]), 6);
      GPS.utc_time = atoi(utc);
      GPS.Date = atoi(date);
      //! Update UTC time here, and hence update Since_UTC
    }
  }
}

const GPS_t* get_gps_data(void)
{
  return &GPS;
}


void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
  if(huart == &huart1)
  {
    if(GPS_validate(rx_buffer))
    {
      GPS_parse(rx_buffer);
      Usart_Data_Freshed = 1;
    }	
    memset(rx_buffer, 0, sizeof(rx_buffer));
    SCB_InvalidateDCache_by_Addr((uint32_t*)(((uint32_t)rx_buffer) & ~(uint32_t)0x1F), GPSBUFSIZE + GPS_BUF_OFFSET);
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, (uint8_t*)rx_buffer, GPSBUFSIZE);
  }
}

// gpio_0 isr controlled by OS, pps isr not
// protect the data and ensure the consistency of data
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  OS_INT_Enter();
  //PPS IN
  if(GPIO_Pin == GPS_PPS_IN_Pin)
  {
    Time_PPS_IN_us = OS_TIME_Get_us64(); //up to 584942 years;
    if(!Camera_Tri_Flag) //&& enable_auto_send)
    {
    // trigger camera
      HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
      Time_Trig_Cam = OS_TIME_Get_us();
      Camera_Tri_Flag = 1;
      OS_TASKEVENT_Set(camera_report_taskid, EVENT_CAMERA);
    }
    if((Time_PPS_IN_us - Time_Since_PPS_us) < 1500000)
    {
      //触发IMU与Lidar (highest priority in this interrupt callback function) 	
      HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_SET);
      HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_SET);
      Time_Trig_LidIMU = OS_TIME_Get_us();
      Lidar_IMU_Tri_Flag = 1;
      //重置tim4
      OS_TIMER_Stop(&Timer_Fake_PPS);
      OS_TIMER_Restart(&Timer_Fake_PPS);
      OS_TIMER_Stop(&Timer_Trig_Cam);
      OS_TIMER_Restart(&Timer_Trig_Cam);
    }

    Time_Since_PPS_us = Time_PPS_IN_us;
  }
  OS_INT_Leave();
}

void utc_add_seconds(int *p_date, int *p_day, int seconds) {
  if (seconds == 0) {
    return;
    }
  // in our application, seconds less than 1 day.
  // NMEA UTC date, formatted as DDMMYY
  int date = *p_date;
  int year = date % 10 + date / 10 % 10 * 10;
  date /= 100;
  int mon = date % 10 + date / 10 % 10 * 10;
  date /= 100;
  int day = date % 10 + date / 10 % 10 * 10;
  // NMEA UTC time, formatted as HHMMSS
  int time_point = *p_day;
  int sec = time_point % 10 + time_point / 10 % 10 * 10;
  time_point /= 100;
  int min = time_point % 10 + time_point / 10 % 10 * 10;
  time_point /= 100;
  int hour = time_point % 10 + time_point / 10 % 10 * 10;
  	
  int cur_sec = hour * 3600 + min * 60 + sec + seconds;
  int one_day = cur_sec / 86400;
  cur_sec = cur_sec % 86400;
  sec = cur_sec % 60;
  min = cur_sec / 60 % 60;
  hour = cur_sec / 3600;
	
  *p_day = hour * 10000 + min * 100 + sec;
  if (!one_day) {
    return;
  }

  uint8_t leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
  uint8_t tab[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (leap) {
    tab[1] = 29;
  }
  day += one_day;
  if (day > tab[mon-1]) {
    day -= tab[mon-1];
    mon += 1;
  }
  if (mon > 12) {
    mon -= 12;
    year += 1;
  }
	
  *p_date = day * 10000 + mon * 100 + year;
}

void lidar_message_task(void)
{
  uint16_t calculated_check;
  GPS_Init();
  lidar_message_taskid = OS_TASK_GetID();
  OS_TASKEVENT lidar_te;
  while(1)
  {
    lidar_te = OS_TASKEVENT_GetBlocked(EVENT_GPIO_0);
    OS_INT_Disable();
    int date = GPS.Date;
    int utc_time = GPS.utc_time;
    OS_INT_Enable();
    Time_GPS_Send = OS_TIME_Get_us64();
    Since_UTC = Time_GPS_Send - Time_PPS_IN_us;
    utc_add_seconds(&date, &utc_time, Since_UTC / 1000000);
    sprintf(Lidar_GPRMC,"$GPRMC,%0.2f,A,2225.58800461,N,11412.51542972,E,0.042,165.0,%d,3.2,W,A*\n",(float)utc_time, date);
    for(int i = 1; i < GPSBUFSIZE; i++)
    {
      if(Lidar_GPRMC[i] != '*')
      {		
        calculated_check ^= Lidar_GPRMC[i];
      }        
      else
      {				
       break;
      }
    }
    sprintf(Lidar_GPRMC,"$GPRMC,%0.2f,A,2225.58800461,N,11412.51542972,E,0.042,165.0,%d,3.2,W,A*%02X\n",(float)utc_time, date, calculated_check);
    SCB_CleanDCache_by_Addr((uint32_t*)(((uint32_t)Lidar_GPRMC) & ~(uint32_t)0x1F), sizeof(Lidar_GPRMC)+32);
    HAL_UART_Transmit_DMA(&huart2, (uint8_t*)(Lidar_GPRMC),sizeof(Lidar_GPRMC));
  }
}