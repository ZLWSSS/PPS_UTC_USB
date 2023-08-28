#ifndef CAMERA_TRIGGER_H_
#define CAMERA_TRIGGER_H_

#include "RTOS.h"

extern OS_TASK* camera_report_taskid;
extern volatile OS_U64 Time_PPS_IN_us;

void camera_utc_task(void);
void Send_Camera_Shot_Time(void);
void trigger_camera(void);
void trigger_imu(void);
#endif