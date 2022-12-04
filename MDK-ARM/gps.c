#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "usart.h"
#include "gps.h"
#include "struct_typedef.h"


uint8_t rx_data = 0;
uint8_t rx_buffer[GPSBUFSIZE];
uint8_t rx_index = 0;
uint8_t time_refresh_flag = 0;
int into_break;
uint8_t gotovalidate;
uint8_t comma_index[12];
char utc[9];
char date[6];

GPS_t GPS;

void GPS_Init()
{
	memset(comma_index, 0, 12);
	memset(utc, 0, 9);
	memset(date, 0, 6);
	HAL_UART_Receive_IT(&huart1, &rx_data, 1);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	into_break++;
	if((rx_data != '\n') && (rx_index < sizeof(rx_buffer))) 
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

int16_t calculated_check;
char check[2];
int GPS_validate(char *nmeastr){
		gotovalidate++;
		calculated_check = 0;
    char checkcalcstr[2];
    int i = 0;
    calculated_check=0;

    if(nmeastr[i] == '$'){i++;}
    else
		{
        return 0;
		}
		
		//校验位
    while((nmeastr[i] != '*') && (i < 128)){
        calculated_check ^= nmeastr[i];// calculate the checksum
        i++;
    }

    if(i >= 128){
        return 0;// the string was too long so return an error
    }

    if (nmeastr[i] == '*'){
        check[0] = nmeastr[i+1];    //put hex chars in check string
        check[1] = nmeastr[i+2];
    }
    else
        return 0;// no checksum separator found there for invalid

    sprintf(checkcalcstr,"%02X",calculated_check);
    return((checkcalcstr[0] == check[0])
        && (checkcalcstr[1] == check[1])) ? 1 : 0 ;
}

//解析参数
void GPS_parse(char *GPSstrParse){
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
		if(((comma_index[1] - comma_index[0]) == 10) && ((comma_index[9] - comma_index[8]) == 7))
		{
			//将UTC与Date转换为double与int
			memcpy(utc,&(GPSstrParse[comma_index[0]+1]), 9);
			memcpy(date,&(GPSstrParse[comma_index[8]+1]), 6);
			GPS.utc_time = atof(utc);
			GPS.Date = atoi(date);
		}
	}
}

const GPS_t* get_gps_data(void)
{
	return &GPS;
}
