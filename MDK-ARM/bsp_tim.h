#ifndef BSP_TIM_H_
#define BSP_TIM_H_

#include "tim.h"
#include "struct_typedef.h"

extern uint64_t Since_PPS_Received_Time;        // time since the latest PPS
extern uint64_t Since_First_PPS_Received_Time;  // time since the first PPS
//! timestamp of the MCU is determined by the UTC time plus Since_UTC
extern uint64_t Since_UTC;                      // time since current UTC time
extern uint8_t Camera_Timer_Request;
extern uint64_t Camera_Trigger_Time;
extern uint64_t Lidar_IMU_Triggered_Time;

void Trigger_judgment(void);
void Send_Camera_Shot_Time(void);
void init_camera_utc_data(void);
void Trigger_IMU_Lidar(void);

#endif
