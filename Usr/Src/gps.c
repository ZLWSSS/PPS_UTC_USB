#include "gps.h"
#include "usart.h"
#include "stm32h7xx_hal_uart_ex.h"
#include "string.h"
#include "RTOS.h"

uint8_t rx_buffer[GPSBUFSIZE + GPS_BUF_OFFSET];
GPS_t GPS;

void GPS_Init(void)
{
  memset(rx_buffer, 0, GPSBUFSIZE + GPS_BUF_OFFSET);
  SCB_InvalidateDCache_by_Addr((uint32_t*)(((uint32_t)rx_buffer) & ~(uint32_t)0x1F), GPSBUFSIZE + GPS_BUF_OFFSET);
  HAL_UARTEx_ReceiveToIdle_DMA(&huart1, rx_buffer, GPSBUFSIZE);
}

uint8_t GPS_validate(uint8_t *nmeastr)
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

void GPS_parse(uint8_t *GPSstrParse)
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
      if (message_arrrive_time < 800000)
      {
        //将UTC与Date转换为int
        memcpy(utc,&(GPSstrParse[comma_index[0]+1]), 6); // only need integer seconds
        memcpy(date,&(GPSstrParse[comma_index[8]+1]), 6);
        GPS.utc_time = atoi(utc);
        GPS.Date = atoi(date);
        //! Update UTC time here, and hence update Since_UTC
        Since_UTC = Since_PPS_Received_Time;
      }
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
    __HAL_GPIO_EXTI_GENERATE_SWIT(GPIO_PIN_0);
  }
}

// gpio_0 isr controlled by OS, pps isr not
// protect the data and ensure the consistency of data
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == GPIO_PIN_0)
  {
    OS_INT_Enter();
    if(GPS_validate((char*) rx_buffer))
      GPS_parse((char*) rx_buffer);	
    memset(rx_buffer, 0, sizeof(rx_buffer));
    SCB_InvalidateDCache_by_Addr((uint32_t*)(((uint32_t)rx_buffer) & ~(uint32_t)0x1F), GPSBUFSIZE + GPS_BUF_OFFSET);
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, rx_buffer, GPSBUFSIZE);
    OS_INT_Leave();
  }
}