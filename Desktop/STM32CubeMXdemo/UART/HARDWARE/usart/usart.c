#include <usart.h>
#include <stdio.h>


void USART_RX_IT_BOOT(UART_HandleTypeDef *huart)
{ 
	  uint8_t ARX_BUFF;
    HAL_UART_Receive_IT(huart, (uint8_t *)&ARX_BUFF, 1);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{  
	#define RXBUFFERSIZE  256     //最大接收字节数
  char RXBUFFER[RXBUFFERSIZE];   //接收数据
  uint8_t ARX_BUFF;			//接收中断缓冲
  uint8_t count = 0;		//接收缓冲计数
  UNUSED(huart);
	if(count >= 255)  //溢出判断
	{	
		count = 0;
		memset(RXBUFFER,0x00,sizeof(RXBUFFER));
		HAL_UART_Transmit(huart, (uint8_t *)"数据溢出", 10,0xFFFF); 	 
	}
	else
	{	
		 RXBUFFER[count++] = ARX_BUFF;   //接收数据转存
		 if((RXBUFFER[count-1] == 0x0A)&&(RXBUFFER[count-2] == 0x0D)) //判断结束位
		 {	
			      HAL_UART_Transmit(huart, (uint8_t *)&RXBUFFER, count,0xFFFF); //将收到的信息发送出去
            while(HAL_UART_GetState(huart) == HAL_UART_STATE_BUSY_TX);//检测UART发送结束
			      count= 0;
			      memset(RXBUFFER,0x00,sizeof(RXBUFFER)); //清空数组}}
	          HAL_UART_Receive_IT(huart, (uint8_t *)&ARX_BUFF, 1);   //再开启接收中断
		}
   }
}
