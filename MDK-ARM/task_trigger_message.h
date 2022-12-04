#ifndef M_TRIGGER_H_
#define M_TRIGGER_H_

#include "bsp_tim.h"
#include "struct_typedef.h"
#include "cmsis_os.h"

extern uint8_t flag_task_trigger_message;
void trigger_message_task(void const *pvParameters);

#endif
