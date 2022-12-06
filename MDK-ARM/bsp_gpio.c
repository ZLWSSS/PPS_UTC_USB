#include "BSP_GPIO.h"
#include "main.h"
#include "bsp_tim.h"
#include "gpio.h"
#include "tim.h"
#include "task_camera_utc.h"

//< flag whether output PPS driven by PPS input or timer
uint8_t PPS_Output_Flag;  
//< flag the time duration when trigger signal for camera has been output, 
//< and not be reset. The flag will be reset once RESET signal for camera 
//< has been output.
uint8_t flag_camera_trigger = 0;
uint8_t exit_flag = 1;
uint8_t rising_flag = 0;
uint8_t first_run=1;
uint8_t enable_auto_send=0;

//GPIO中断
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPS_PPS_IN_Pin)
	{
		//如果是第一次运行，那么开启第二定时器
		/*if(first_run)
		{	
			HAL_TIM_Base_Start_IT(&htim2);
			first_run = 0;
		}*/
		if(!flag_camera_trigger)
		{
			// trigger camera
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
			Camera_Trigger_Time = Since_First_PPS_Received_Time;
			flag_camera_trigger = 1;
		}
		if(Since_PPS_Received_Time < 1500000)
		{
			//触发IMU与Lidar (highest priority in this interrupt callback function)
			HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_SET);
			Lidar_IMU_Triggered_Time = Since_First_PPS_Received_Time;

			//重置tim3&tim4
			HAL_TIM_Base_Stop_IT(&htim3);
			HAL_TIM_Base_Start_IT(&htim3);
			HAL_TIM_Base_Stop_IT(&htim4);
			HAL_TIM_Base_Start_IT(&htim4);
			// 重置timer2时间
			Since_PPS_Received_Time = 0;
			PPS_Output_Flag = 1;
		}
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
