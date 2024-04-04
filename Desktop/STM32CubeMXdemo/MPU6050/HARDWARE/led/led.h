#ifndef _LED_H
#define _LED_H


#define LED0_ON()  HAL_GPIO_WritePin(GPIOC,LED0_Pin,GPIO_PIN_RESET)
#define LED0_OFF() HAL_GPIO_WritePin(GPIOC,LED0_Pin,GPIO_PIN_SET)

#define LED1_ON()  HAL_GPIO_WritePin(GPIOC,LED1_Pin,GPIO_PIN_RESET)
#define LED1_OFF() HAL_GPIO_WritePin(GPIOC,LED1_Pin,GPIO_PIN_SET)

#define LED2_ON()  HAL_GPIO_WritePin(GPIOC,LED2_Pin,GPIO_PIN_RESET)
#define LED2_OFF() HAL_GPIO_WritePin(GPIOC,LED2_Pin,GPIO_PIN_SET)

#define LED3_ON()  HAL_GPIO_WritePin(GPIOC,LED3_Pin,GPIO_PIN_RESET)
#define LED3_OFF() HAL_GPIO_WritePin(GPIOC,LED3_Pin,GPIO_PIN_SET)

#include <main.h>

void LED0_SHIE(void);
void LED1_SHIE(void);
void LED2_SHIE(void);
void LED3_SHIE(void);


#endif