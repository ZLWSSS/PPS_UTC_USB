#include "task_camera_utc.h"
#include "usbd_custom_hid_if.h"
#include "string.h"
#include "gps.h"
#include "bsp_gpio.h"
#include "tftlcd.h"

typedef struct{
	int real_utc;
	int date_utc;
	double st_time;
	uint32_t checksum;
} usb_utc_data;

const int sizeutccmd = 20;
const uint8_t sizecheck = 4;

usb_utc_data utc_real_data;
const GPS_t* local_gps_data;
uint8_t flag_camera_utc;
int task_camera_utc_loop;
uint8_t not_print=1;

void init_camera_utc_data()
{
	local_gps_data = get_gps_data();
	memset(&utc_real_data, 0, sizeof(usb_utc_data));
}

static uint32_t data_checksum(uint32_t* data_to_check, uint8_t length)
{
	uint32_t t = 0;
	for(int i = 0; i < length; i++)
	{
		t = t^data_to_check[i];
	}
	return t;
}

void Send_Camera_Shot_Time(void)
{
	utc_real_data.real_utc = (int)(local_gps_data->utc_time);
	//有pps信号后，这里需要改成PPS_Camera_Trigger_Time
	utc_real_data.st_time = (double)(((double)PPS_Camera_Trigger_Time / 1000000.f) - 1);
	utc_real_data.date_utc = local_gps_data->Date;
	utc_real_data.checksum = data_checksum((uint32_t*) &utc_real_data, sizecheck);
	USBD_CUSTOM_HID_SendReport_HS((uint8_t*) &utc_real_data,  sizeutccmd);
}

//发送相机时间utc
void camera_utc_task(void const *pvParameters)
{
	init_camera_utc_data();
	while(1)
	{
		if(flag_camera_utc)
		{
			task_camera_utc_loop++;
			Send_Camera_Shot_Time();
			flag_camera_utc = 0;
		}
		//用来显示自动触发是否开始
		if(enable_auto_send&&not_print)
		{
			not_print=0;
			LCD_ShowString(0, 50, 160, 32, 32, "Start AUTO Transmit!");
		}
		osDelay(1);
	}
}
