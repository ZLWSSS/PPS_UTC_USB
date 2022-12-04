#ifndef BSP_TIM_H_
#define BSP_TIM_H_

#include "tim.h"
#include "struct_typedef.h"

extern uint64_t Since_PPS_Received_Time;
extern uint8_t Camera_Timer_Request;
extern uint64_t PPS_Camera_Trigger_Time;

void Trigger_judgment(void);
void Send_Camera_Shot_Time(void);
void init_camera_utc_data(void);

#endif
