#include "bsp_tim.h"
#include "BSP_GPIO.h"
#include "gpio.h"
#include "cmsis_os.h"
#include "task_trigger_message.h"
#include "task_camera_utc.h"
#include "usbd_custom_hid_if.h"

uint64_t Since_PPS_Received_Time = 0;
uint64_t Since_First_PPS_Received_Time = 0;
uint64_t Since_UTC = 0;
uint64_t Lidar_IMU_Triggered_Time;
uint64_t Lidar_IMU_Reset_Time;
uint64_t Camera_Trigger_Time;
uint8_t  Prepare_send_data = 0;

uint32_t Set_Occupation = 50000;
uint32_t Message_interval = 60000;
uint32_t Camera_Period = 20000;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	//timer3: alternate PPS in case of absence of PPS
	if(htim->Instance == TIM3)
	{
		if (!flag_camera_trigger && enable_auto_send)
		{
			// trigger camera
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
			Camera_Trigger_Time = Since_First_PPS_Received_Time;
			flag_camera_trigger = 1;
			flag_camera_utc = 1;
		}
		
		if(Since_PPS_Received_Time > 1500000)
		{
			//触发IMU与Lidar (highest priority in this interrupt callback function) 	
			HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_SET);
			Lidar_IMU_Triggered_Time = Since_First_PPS_Received_Time;

			//重置tim4
			HAL_TIM_Base_Stop_IT(&htim4);
			HAL_TIM_Base_Start_IT(&htim4);
			PPS_Output_Flag = 1;
		}
	}
	// Timer2: Time Counter
	// also set/reset the pin after trigger/PPS to 
	// satisfy the requirement of occupany and
	// prepare for next trigger/PPS
	else if(htim->Instance == TIM2)
	{
		Since_PPS_Received_Time++;
		Since_First_PPS_Received_Time++;
		Since_UTC++;
		Trigger_judgment();
	} 
	//timer4:enbale the camera: 20hz
	else if(htim->Instance == TIM4)
	{
		if (!flag_camera_trigger && enable_auto_send)
		{
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
			Camera_Trigger_Time = Since_First_PPS_Received_Time;
			flag_camera_trigger = 1;
		}
	}
	//timer1: ingonre
	else if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
}

void Trigger_judgment(void)
{
	if(PPS_Output_Flag)
	{
		//如果计时器时间减去雷达imu的触发时间大于占空比，那么复位
		if((Since_First_PPS_Received_Time - Lidar_IMU_Triggered_Time) > Set_Occupation)
		{
			HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_RESET);
			Lidar_IMU_Reset_Time = Since_First_PPS_Received_Time;
			PPS_Output_Flag = 0;
			Prepare_send_data = 1;
		}
	}
	//如果相机被触发了，这里需要复位电平
	if(flag_camera_trigger)
	{
		if(Since_First_PPS_Received_Time - Camera_Trigger_Time > Camera_Period)
		{
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
			flag_camera_trigger = 0;
		}
	}
	//如果可以准备发送数据，那么在至少60ms之后，触发任务：任务为最高优先级。
	if(Prepare_send_data)
	{
		if((Since_First_PPS_Received_Time - Lidar_IMU_Reset_Time) > Message_interval)
		{
			// send data
			flag_task_trigger_message = 1;
			Prepare_send_data = 0;
		}
	}
}

