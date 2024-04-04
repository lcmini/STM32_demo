#include <usart.h>


int fputc(int ch, FILE *f)
 
{
 
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xffff);
 
  return ch;
 
}


int fgetc(FILE *f)
 
{
 
uint8_t ch;
 
// 采用轮询方式接收 1字节数据，超时时间设置为无限等待
 
HAL_UART_Receive( &huart1,(uint8_t*)&ch,1, HAL_MAX_DELAY );
 
return ch;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{ 
	
   UNUSED(huart);
	if(huart->Instance ==USART1)
	{ 

		HAL_UART_Transmit_IT(&huart1,rx_data,2);
		if(rx_data[0] == 'a')
		{  
			LED0_ON();
			HAL_UART_Receive_IT(&huart1, rx_data, 2);
		}

		if(rx_data[0] == 'b')
		{
			LED0_OFF();
			HAL_UART_Receive_IT(&huart1, rx_data, 2);
		}
		if(rx_data[0] == 'c')
		{
			LED0_SHIE();
			//LED3_OFF();
			HAL_UART_Receive_IT(&huart1, rx_data, 2);
		}

	}
	HAL_UART_Receive_IT(&huart1, rx_data, 2);
} 