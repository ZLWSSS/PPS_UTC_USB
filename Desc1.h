// E:\Github_Rep\PPS_UTC_USB\Desc1.h


char ReportDescriptor[33] = {
    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
    0x09, 0x00,                    // USAGE (Undefined)
    0xa1, 0x01,                    // COLLECTION (Application)
    0x09, 0x00,                    //   USAGE (Undefined)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
    0x95, 0x14,                    //   REPORT_COUNT (20)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
    0x09, 0x00,                    //   USAGE (Undefined)
    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
    0x26, 0xff, 0x00,              //   LOGICAL_MAXIMUM (255)
    0x95, 0x04,                    //   REPORT_COUNT (4)
    0x75, 0x08,                    //   REPORT_SIZE (8)
    0x91, 0x00,                    //   OUTPUT (Data,Ary,Abs)
    0xc0                           // END_COLLECTION
};

