#ifndef _GPS_H_
#define _GPS_H_

#define GPSBUFSIZE  128       // GPS buffer size
#define GPS_BUF_OFFSET 32

#include "stdint.h"
#include "float.h"

typedef struct{
    int utc_time;
    int Date;
} GPS_t;
 

void GPS_Init(void);
uint8_t GPS_validate(uint8_t *nmeastr);
void GPS_parse(uint8_t *GPSstrParse);
const GPS_t* get_gps_data(void);

#endif