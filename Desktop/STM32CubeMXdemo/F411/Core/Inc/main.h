/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f4xx_hal.h"

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
#define LED0_Pin GPIO_PIN_0
#define LED0_GPIO_Port GPIOC
#define LED1_Pin GPIO_PIN_1
#define LED1_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_2
#define LED2_GPIO_Port GPIOC
#define LED3_Pin GPIO_PIN_3
#define LED3_GPIO_Port GPIOC
#define KEYUP_Pin GPIO_PIN_0
#define KEYUP_GPIO_Port GPIOA
#define KEYUP_EXTI_IRQn EXTI0_IRQn
#define LED4_Pin GPIO_PIN_4
#define LED4_GPIO_Port GPIOC
#define LED5_Pin GPIO_PIN_5
#define LED5_GPIO_Port GPIOC
#define LED6_Pin GPIO_PIN_6
#define LED6_GPIO_Port GPIOC
#define LED7_Pin GPIO_PIN_7
#define LED7_GPIO_Port GPIOC
#define KEY0_Pin GPIO_PIN_8
#define KEY0_GPIO_Port GPIOC
#define KEY0_EXTI_IRQn EXTI9_5_IRQn
#define KEY1_Pin GPIO_PIN_9
#define KEY1_GPIO_Port GPIOC
#define KEY1_EXTI_IRQn EXTI9_5_IRQn
#define HC138_A0_Pin GPIO_PIN_10
#define HC138_A0_GPIO_Port GPIOC
#define HC138_A1_Pin GPIO_PIN_11
#define HC138_A1_GPIO_Port GPIOC
#define HC138_A2_Pin GPIO_PIN_12
#define HC138_A2_GPIO_Port GPIOC
#define KEY2_Pin GPIO_PIN_2
#define KEY2_GPIO_Port GPIOD
#define KEY2_EXTI_IRQn EXTI2_IRQn
#define HC595_DATA_Pin GPIO_PIN_3
#define HC595_DATA_GPIO_Port GPIOB
#define HC595_LCLK_Pin GPIO_PIN_4
#define HC595_LCLK_GPIO_Port GPIOB
#define HC595_SCLK_Pin GPIO_PIN_5
#define HC595_SCLK_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
