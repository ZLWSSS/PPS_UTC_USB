#include "main.h"
#include "gps.h"
#include "task_trigger_message.h"
#include "string.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>

const int sizeGPRMC = 128;
char Lidar_GPRMC[sizeGPRMC];
const GPS_t* mt_local_gps;
uint8_t flag_task_trigger_message;
int taks_tm_loop;

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

//�������״﷢����Ϣ
void trigger_message_task(void const *pvParameters)
{
	uint16_t calculated_check;
	mt_local_gps = get_gps_data();
	
	while(1)
	{
		if(flag_task_trigger_message)
		{
      		calculated_check = 0;
			taks_tm_loop++;
			int date = mt_local_gps->Date;
			int utc_time = mt_local_gps->utc_time;
			utc_add_seconds(&date, &utc_time, Since_UTC / 1000000);
			sprintf(Lidar_GPRMC,"$GPRMC,%0.2f,A,2225.58800461,N,11412.51542972,E,0.042,165.0,%d,3.2,W,A*\n",(float)utc_time, date);
			for(int i = 1; i < sizeGPRMC; i++)
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
			// sprintf(Lidar_GPRMC,"$GPRMC,120546.00,A,2225.58800461,N,11412.51542972,E,0.042,165.0,080623,3.2,W,A*24\n");
			flag_task_trigger_message=0;
			HAL_UART_Transmit_IT(&huart2, (uint8_t*)(Lidar_GPRMC),sizeof(Lidar_GPRMC));
		}
		osDelay(1);
	}
}



