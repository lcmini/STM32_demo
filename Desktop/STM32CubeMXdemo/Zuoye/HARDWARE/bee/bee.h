#ifndef _BEE_H
#define _BEE_H


#define BEE_ON()    HAL_GPIO_WritePin(GPIOB,BEE_Pin,GPIO_PIN_RESET)
#define BEE_OFF()   HAL_GPIO_WritePin(GPIOB,BEE_Pin,GPIO_PIN_SET)
#include <main.h>

void BEE_BOOT(void);

#endif