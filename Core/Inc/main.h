/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RED_Pin GPIO_PIN_0
#define RED_GPIO_Port GPIOC
#define GREEN_Pin GPIO_PIN_1
#define GREEN_GPIO_Port GPIOC
#define Camera_triger_Pin GPIO_PIN_4
#define Camera_triger_GPIO_Port GPIOA
#define GPS_PPS_IN_Pin GPIO_PIN_5
#define GPS_PPS_IN_GPIO_Port GPIOA
#define GPS_PPS_IN_EXTI_IRQn EXTI9_5_IRQn
#define Lidar_PPS_OUT_Pin GPIO_PIN_6
#define Lidar_PPS_OUT_GPIO_Port GPIOA
#define IMU_Trigger_Pin GPIO_PIN_7
#define IMU_Trigger_GPIO_Port GPIOA
#define IMU_PPS_Pin GPIO_PIN_4
#define IMU_PPS_GPIO_Port GPIOC
#define Lidar_Out_Pin GPIO_PIN_5
#define Lidar_Out_GPIO_Port GPIOC
#define Soft_Trigger_Pin GPIO_PIN_0
#define Soft_Trigger_GPIO_Port GPIOB
#define Soft_Trigger_EXTI_IRQn EXTI0_IRQn
#define BLUE_Pin GPIO_PIN_10
#define BLUE_GPIO_Port GPIOD
#define LCD_PWR_Pin GPIO_PIN_3
#define LCD_PWR_GPIO_Port GPIOD
#define LCD_RST_Pin GPIO_PIN_4
#define LCD_RST_GPIO_Port GPIOD
#define LCD_DC_Pin GPIO_PIN_4
#define LCD_DC_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
