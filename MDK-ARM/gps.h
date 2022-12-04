#ifndef _GPS_H_
#define GPSBUFSIZE  128       // GPS buffer size

typedef struct{

  double utc_time;
	char 	 Position_Status;
	double Latitude;
	char   Latitude_Direction;
	double Longtitude;
	char   Longtitude_Direction;
	double Speed_Kn;
	double Track_true;
	int    Date;
	float  Mag_Var;
	char   var_dir;
	char   Mode_ind;
} GPS_t;


void GPS_Init(void);
void GSP_USBPrint(char *data);
void GPS_print_val(char *data, int value);
int GPS_validate(char *nmeastr);
void GPS_parse(char *GPSstrParse);
float GPS_nmea_to_dec(float deg_coord, char nsew);
const GPS_t* get_gps_data(void);

#endif
