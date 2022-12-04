// E:\STM32EMBEDEDSTUDIO_PROJECT\STM32H730_GPS_Lidar_Camera\Desc1.h


char ReportDescriptor[20] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x00,                    // USAGE (Undefined)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x09, 0x00,                    //   USAGE (Undefined)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
    0x95, 0x0c,                    //   REPORT_COUNT (12)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0xc0                           // END_COLLECTION
};

