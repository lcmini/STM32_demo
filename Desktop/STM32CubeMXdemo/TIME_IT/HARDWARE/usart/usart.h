#ifndef _UART_H
#define _UART_H
#include <main.h>

void USART_RX_IT_BOOT(UART_HandleTypeDef *huart);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif