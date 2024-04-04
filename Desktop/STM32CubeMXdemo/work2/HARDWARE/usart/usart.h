#ifndef _UART_H
#define _UART_H
#include <main.h>
#include <led.h>
#include <stdio.h>
#include <string.h>

extern UART_HandleTypeDef huart1;
extern uint8_t rx_data[2];

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
int fgetc(FILE *f);
int fputc(int ch, FILE *f);

#endif