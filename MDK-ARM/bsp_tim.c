#include "bsp_tim.h"
#include "BSP_GPIO.h"
#include "gpio.h"
#include "cmsis_os.h"
#include "task_trigger_message.h"
#include "task_camera_utc.h"

uint64_t Since_PPS_Received_Time;
uint64_t Lidar_IMU_Triggered_Time;
uint64_t Lidar_IMU_Reset_Time;
uint64_t Camera_Trigger_Time_4;
uint64_t PPS_Camera_Trigger_Time;
uint8_t  flag_Tim_Triggered = 0;
uint8_t  flag_Camera_Triggered = 0;
uint8_t  Prepare_send_data = 0;
uint8_t  Camera_Timer_Request = 0;

uint32_t Set_Occupation = 1000;
uint32_t Message_interval = 60000;
uint32_t Camera_Period = 10000;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	//timer3: alternate PPS in case of absence of PPS
	if(htim->Instance == TIM3)
	{
		if(Since_PPS_Received_Time > 1500000)
		{
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
			PPS_Camera_Trigger_Time = Since_PPS_Received_Time;	
			HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_SET);

			
			Lidar_IMU_Triggered_Time = Since_PPS_Received_Time;
			HAL_TIM_Base_Stop_IT(&htim4);
			if(enable_auto_send)
			{
				flag_camera_utc = 1;
				Camera_Timer_Request = 1;
			}
			flag_Tim_Triggered = 1;
		}
	}
	//Timer2: Time Counter
	else if(htim->Instance == TIM2)
	{
		Since_PPS_Received_Time++;
		Trigger_judgment();
		} 
	//timer4:enbale the camera: 20hz
	else if(htim->Instance == TIM4)
	{
		HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
		Camera_Trigger_Time_4 = Since_PPS_Received_Time;
		flag_Camera_Triggered = 1;
	}
	//timer1: ingonre
	else if (htim->Instance == TIM1) {
    HAL_IncTick();
  }
}

void Trigger_judgment(void)
{
	if(flag_Tim_Triggered)
	{
		//�����ʱ��ʱ���ȥ�״�imu�Ĵ���ʱ�����ռ�ձȣ���ô��λ
		if((Since_PPS_Received_Time - Lidar_IMU_Triggered_Time) > Set_Occupation)
		{
			HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_RESET);
			Lidar_IMU_Reset_Time = Since_PPS_Received_Time;
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
			//�����Ҫ�������
			if(Camera_Timer_Request)
			{	
				HAL_TIM_Base_Start_IT(&htim4);
				Camera_Timer_Request = 0;
			}
			//���Ը�PC����UTCʱ���
			Prepare_send_data = 1;
			flag_Tim_Triggered = 0;
		}
	}
	else if(PPS_Triggered_Flag)
	{
		//�����pps���������IMU���״�
		if(Since_PPS_Received_Time > Set_Occupation)
		{
			HAL_GPIO_WritePin(GPIOC, IMU_PPS_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, Lidar_PPS_OUT_Pin, GPIO_PIN_RESET);
			Lidar_IMU_Reset_Time = Since_PPS_Received_Time;
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
			if(Camera_Timer_Request)
			{	
				HAL_TIM_Base_Start_IT(&htim4);
				Camera_Timer_Request = 0;
			}
			Prepare_send_data = 1;
			PPS_Triggered_Flag = 0;
		}
	}
	//�������������ˣ�������Ҫ��λ��ƽ
	else if(flag_Camera_Triggered)
	{
		if(Since_PPS_Received_Time - Camera_Trigger_Time_4 > Camera_Period)
		{
			flag_Camera_Triggered = 0;
			HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
		}
	}
	//�������׼���������ݣ���ô������60ms֮�󣬴�����������Ϊ������ȼ���
	if(Prepare_send_data)
	{
		if((Since_PPS_Received_Time - Lidar_IMU_Reset_Time) > Message_interval)
		{
			flag_task_trigger_message=1;
			Prepare_send_data = 0;
		}
	}
}

