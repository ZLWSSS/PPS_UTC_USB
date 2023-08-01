#ifndef _GPS_H_
#define _GPS_H_

#define GPSBUFSIZE  128       // GPS buffer size

typedef struct{
    int utc_time;
	int    Date;
	//uint8_t msg[GPSBUFSIZE];
	//uint8_t ready;  // indicate whether the GPS message is ready 0 -- not ready, 1 -- ready
} GPS_t;


void GPS_Init(void);
void GSP_USBPrint(char *data);
void GPS_print_val(char *data, int value);
int GPS_validate(char *nmeastr);
void GPS_parse(char *GPSstrParse);
float GPS_nmea_to_dec(float deg_coord, char nsew);
const GPS_t* get_gps_data(void);

#endif
