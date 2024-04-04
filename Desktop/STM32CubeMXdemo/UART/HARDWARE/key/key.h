#ifndef _KEY_H
#define _KEY_H
#include <main.h>


#define KEY0   HAL_GPIO_ReadPin(GPIOC,KEY0_Pin) //KEY0 °´¼ü PC8
#define KEY1   HAL_GPIO_ReadPin(GPIOC,KEY1_Pin) //KEY0 °´¼ü PC8
#define KEY2   HAL_GPIO_ReadPin(KEY2_GPIO_Port,KEY2_Pin) //KEY2 °´¼ü PD2
#define KEY_UP HAL_GPIO_ReadPin(KEY_UP_GPIO_Port,KEY_UP_Pin) //KEY_UP PA0

#define KEY0_PRES 1
#define KEY1_PRES 2
#define KEY2_PRES 3
#define KEY_UP_PRES 4

int KEY_SCAN(void);

#endif