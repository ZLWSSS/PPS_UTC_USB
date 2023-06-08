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

//给激光雷达发送消息
void trigger_message_task(void const *pvParameters)
{
	int calculated_check;
	mt_local_gps = get_gps_data();
	
	while(1)
	{
		if(flag_task_trigger_message)
		{
      calculated_check = 0;
			taks_tm_loop++;
			sprintf(Lidar_GPRMC,"$GPRMC,%0.3f,,,,,,,,%d,,,A*\n",(float)mt_local_gps->utc_time, mt_local_gps->Date);
			for(int i = 0; i < sizeGPRMC; i++)
			{
				if((Lidar_GPRMC[i] != 0) && (Lidar_GPRMC[i] != '*'))
				{
					calculated_check ^= Lidar_GPRMC[i];
				}
			}
			sprintf(Lidar_GPRMC,"$GPRMC,%0.3f,,,,,,,,%d,,,A*%02X\n",(float)mt_local_gps->utc_time, mt_local_gps->Date, calculated_check);
			flag_task_trigger_message=0;
			HAL_UART_Transmit_IT(&huart2, (uint8_t*)(Lidar_GPRMC),sizeof(Lidar_GPRMC));
		}
		osDelay(1);
	}
}



