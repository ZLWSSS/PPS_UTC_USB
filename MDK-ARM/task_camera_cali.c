#include "task_camera_cali.h"
#include "BSP_GPIO.h"
#include "bsp_delay.h"
#include "gpio.h"
#include "task_camera_utc.h"
#include "bsp_lcd.h"
#include "tftlcd.h"
#include "usart.h"
#include "gps.h"

int task_flag;
//这里是按键触发任务（按键发送utc时间）
void camera_cali_task(void const *pvParameters)
{
	delay_init();
	while(1)
	{
		if(exit_flag == 1)
		{
			if(rising_flag == GPIO_PIN_RESET)
			{
				delay_ms(10);
				if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
				{
					task_flag++;
					HAL_UART_AbortReceive_IT(&huart1);
					HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
					Send_Camera_Shot_Time();
					HAL_UART_Receive_IT(&huart1, &rx_data, 1);
					delay_ms(10);
					HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
					exit_flag = 0;
				}
				else{
					exit_flag = 0;
				}
			}
		}
		osDelay(1);
	}
}

void trigger_camera(void)
{
	// stop GPS UART interrupt to avoid MCU utc update during MCU time sending
	// HAL_UART_AbortReceive_IT(&huart1);
	HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
	__HAL_GPIO_EXTI_GENERATE_SWIT(GPIO_PIN_0);
	// restart GPS UART after MCU time sending
	// HAL_UART_Receive_IT(&huart1, &rx_data, 1);
	delay_ms(10);
	HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
}

void trigger_imu(void)
{
	// stop GPS UART interrupt to avoid MCU utc update during MCU time sending
	// HAL_UART_AbortReceive_IT(&huart1);
	// add the imu trigger pin: named as IMU_Trigger_Pin
	HAL_GPIO_WritePin(IMU_Trigger_GPIO_Port, IMU_Trigger_Pin, GPIO_PIN_SET);
	__HAL_GPIO_EXTI_GENERATE_SWIT(GPIO_PIN_0);
	// restart GPS UART after MCU time sending
	// HAL_UART_Receive_IT(&huart1, &rx_data, 1);
	delay_ms(10);
	HAL_GPIO_WritePin(IMU_Trigger_GPIO_Port, IMU_Trigger_Pin, GPIO_PIN_RESET);
}