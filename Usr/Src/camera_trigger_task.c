#include "camera_trigger_task.h"
#include "lidar_message_task.h"
#include "usbd_custom_hid_if.h"

typedef struct{
  int real_utc;
  int date_utc;
  double st_time;
  uint32_t checksum;
} usb_utc_data;

const int sizeutccmd = 20;
const uint8_t sizecheck = 4;

usb_utc_data utc_real_data;
const GPS_t* local_gps_data;
OS_TASK* camera_report_taskid;
static OS_U64 Time_Camera_Send;

static uint32_t data_checksum(uint32_t* data_to_check, uint8_t length)
{
  uint32_t t = 0;
  for(int i = 0; i < length; i++)
  {
    t = t^data_to_check[i];
  }
  return t;
}

void camera_utc_task(void)
{
  OS_TASK_Delay(500);
  local_gps_data = get_gps_data();
  memset(&utc_real_data, 0, sizeof(usb_utc_data));
  camera_report_taskid = OS_TASK_GetID();
  OS_TASKEVENT cam_task_event;
  while(1)
  {
    cam_task_event = OS_TASKEVENT_GetBlocked(EVENT_CAMERA);
    Time_Camera_Send = OS_TIME_Get_us();
    OS_INT_Disable();
    Since_UTC = Time_Camera_Send - Time_PPS_IN_us;
    utc_real_data.st_time = (double)(((double)Since_UTC / 1000000.0));
    utc_real_data.real_utc = local_gps_data->utc_time;
    utc_real_data.date_utc = local_gps_data->Date;
    OS_INT_Enable();
    utc_real_data.checksum = data_checksum((uint32_t*) &utc_real_data, sizecheck);
    USBD_CUSTOM_HID_SendReport_HS((uint8_t*) &utc_real_data,  sizeutccmd);
  }
}

void trigger_camera(void)
{
  HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_SET);
  OS_TASKEVENT_Set(camera_report_taskid, EVENT_CAMERA);

  OS_TASK_Delay(5);
  HAL_GPIO_WritePin(GPIOA, Camera_triger_Pin, GPIO_PIN_RESET);
}

void trigger_imu(void)
{
  HAL_GPIO_WritePin(IMU_Trigger_GPIO_Port, IMU_Trigger_Pin, GPIO_PIN_SET);
  OS_TASKEVENT_Set(camera_report_taskid, EVENT_CAMERA);
  OS_TASK_Delay(5);
  HAL_GPIO_WritePin(IMU_Trigger_GPIO_Port, IMU_Trigger_Pin, GPIO_PIN_RESET);
}

