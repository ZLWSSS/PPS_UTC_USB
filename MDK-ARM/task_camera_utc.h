#ifndef CAMERA_TRIGGER_H_
#define CAMERA_TRIGGER_H_

#include "bsp_tim.h"
#include "struct_typedef.h"
#include "cmsis_os.h"

extern uint8_t flag_camera_utc;
void camera_utc_task(void const *pvParameters);
void Send_Camera_Shot_Time(void);
#endif
