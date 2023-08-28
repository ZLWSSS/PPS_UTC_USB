#ifndef M_TRIGGER_H_
#define M_TRIGGER_H_

#include "stdint.h"
#include "float.h"

#define GPSBUFSIZE  128       // GPS buffer size
#define GPS_BUF_OFFSET 32

#define EVENT_GPIO_0 (1u << 0)
#define EVENT_CAMERA (1u << 1)

typedef struct{
    int utc_time;
    int Date;
} GPS_t;

extern uint64_t Since_UTC;
extern uint8_t enable_auto_send;
 
void GPS_Init(void);
uint8_t GPS_validate(char *nmeastr);
void GPS_parse(char *GPSstrParse);
const GPS_t* get_gps_data(void);
void lidar_message_task(void);

#endif