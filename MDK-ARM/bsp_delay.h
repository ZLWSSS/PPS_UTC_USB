#ifndef BSP_DELAY_H
#define BSP_DELAY_H
#include "struct_typedef.h"

void delay_init(void);
void delay_us(uint16_t nus);
void delay_ms(uint16_t nms);
#endif

