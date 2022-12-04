#include "BSP_GPIO.h"
#include "main.h"
#include "bsp_tim.h"
#include "gpio.h"
#include "tim.h"
#include "task_camera_utc.h"

uint8_t PPS_Triggered_Flag;
uint8_t exit_flag = 0;
uint8_t rising_flag;
uint8_t first_run=1;
uint8_t enable_auto_send=0;

//GPIO中断
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPS_PPS_IN_Pin)
	{
		//如果是第一次运行，那么开启第二定时器
		if(first_run)
		{	
			HAL_TIM_Base_Start_IT(&htim2);
			first_run = 0;
		}
		if(Since_PPS_Received_Time < 1500000)
		{
			//重置tim3
			HAL_TIM_Base_Stop_IT(&htim3);
			HAL_TIM_Base_Start_IT(&htim3);
			HAL_TIM_Base_Stop_IT(&htim4);
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
			//记录上一次以来重置Timer2的时间
			PPS_Camera_Trigger_Time = Since_PPS_Received_Time;
			//触发IMU与Lidar
			HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_SET);

			if(enable_auto_send)
			{
				flag_camera_utc=1;
				Camera_Timer_Request = 1;
			}

			PPS_Triggered_Flag = 1;
			
		}
		//重置timer2时间
		Since_PPS_Received_Time = 0;
	}
	else if(GPIO_Pin == GPIO_PIN_13)
	{
		if(exit_flag == 0)
		{
			exit_flag = 1;
			rising_flag = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
		}
		else
		{
			rising_flag = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
		}
	}
	else if(GPIO_Pin == GPIO_PIN_12)
	{
		if(HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12) == GPIO_PIN_RESET)
		{
			enable_auto_send = 1;
		}
	}
}
