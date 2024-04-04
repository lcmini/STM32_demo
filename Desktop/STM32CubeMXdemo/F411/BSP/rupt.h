#ifndef _RUPT_H_
#define  _RUPT_H_
#include "includes.h"

extern uchar key0_value,key1_value,key2_value;

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
int key_scan(void);

#endif
