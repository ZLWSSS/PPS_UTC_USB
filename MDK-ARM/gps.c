#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "usart.h"
#include "gps.h"
#include "bsp_tim.h"
#include "struct_typedef.h"


uint8_t rx_data = 0;
uint8_t rx_buffer[GPSBUFSIZE];
uint8_t rx_index = 0;
uint8_t time_refresh_flag = 0;
uint8_t comma_index[12];
char utc[7];
char date[7];
uint64_t message_arrrive_time;

GPS_t GPS;

void GPS_Init()
{
	memset(comma_index, 0, 12);
	memset(utc, 0, 7);
	memset(date, 0, 7);
	HAL_UART_Receive_IT(&huart1, &rx_data, 1);
}

int uart_cb = 0;
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  uart_cb++;
	if (rx_index == 0) message_arrrive_time = Since_PPS_Received_Time;
	if((rx_data != 0x0A) && (rx_index < sizeof(rx_buffer))) 
	{
		rx_buffer[rx_index++] = rx_data;
	} 
	else 
	{
		if(GPS_validate((char*) rx_buffer))
			GPS_parse((char*) rx_buffer);
		
		rx_index = 0;
		memset(rx_buffer, 0, sizeof(rx_buffer));
	}
	
	HAL_UART_Receive_IT(&huart1, &rx_data, 1);
}

int16_t checksum;
char transmitted_checksum[2];
char checkcalcstr[3];

int GPS_validate(char *nmeastr){
	checksum = 0;
  int i = 0;

  if(nmeastr[i] == '$'){i++;}
  else{ return 0; }
		
	//校验位
  while((nmeastr[i] != '*') && (i < GPSBUFSIZE)){
		checksum ^= nmeastr[i];// calculate the checksum
		i++;
  }

  if(i >= GPSBUFSIZE){
		return 0;// the string was too long so return an error
  }

  if (nmeastr[i] == '*'){
    transmitted_checksum[0] = nmeastr[i+1];    //put hex chars in check string
		transmitted_checksum[1] = nmeastr[i+2];
	}
  else
		return 0;// no checksum separator found there for invalid, ! Can not reach here !

	sprintf(checkcalcstr,"%02X",checksum);
  return((checkcalcstr[0] == transmitted_checksum[0]) && (checkcalcstr[1] == transmitted_checksum[1])) ? 1 : 0 ;
}

int gps_parse;
//解析参数
void GPS_parse(char *GPSstrParse){
  gps_parse++;
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
