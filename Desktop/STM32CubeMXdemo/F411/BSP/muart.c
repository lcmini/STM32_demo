#include "muart.h"
#include "includes.h"
extern UART_HandleTypeDef huart1;
uint8_t TxBuffer[10];
uint8_t usart1_rx[10];
//		TxBuffer[0] = "hh";
//		HAL_UART_Transmit(&huart1,TxBuffer,5,HAL_MAX_DELAY);
//		HAL_Delay(500);
void usart1_text(void)
{
		huart1.Instance->DR = 'a';
		while(!(huart1.Instance->SR & USART_SR_TXE));
		huart1.Instance->DR = 'b';
		while(!(huart1.Instance->SR & USART_SR_TXE));
		huart1.Instance->DR = 'c';
		while(!(huart1.Instance->SR & USART_SR_TXE));
		huart1.Instance->DR = 'd';
		while(!(huart1.Instance->SR & USART_SR_TXE));
		HAL_Delay(500);
}


char rxdata[30];
uint8_t rxdat;
uchar rx_pointer=0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *hurat)
{
	rxdata[rx_pointer]=rxdat;
	HAL_UART_Receive_IT(&huart1,&rxdat,1);
	if(rxdata[0] == 0x01)HAL_GPIO_TogglePin(LED0_GPIO_Port,LED0_Pin);
}

