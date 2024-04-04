#include <usart.h>
#include <stdio.h>


void USART_RX_IT_BOOT(UART_HandleTypeDef *huart)
{ 
	  uint8_t ARX_BUFF;
    HAL_UART_Receive_IT(huart, (uint8_t *)&ARX_BUFF, 1);
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{  
	#define RXBUFFERSIZE  256     //�������ֽ���
  char RXBUFFER[RXBUFFERSIZE];   //��������
  uint8_t ARX_BUFF;			//�����жϻ���
  uint8_t count = 0;		//���ջ������
  UNUSED(huart);
	if(count >= 255)  //����ж�
	{	
		count = 0;
		memset(RXBUFFER,0x00,sizeof(RXBUFFER));
		HAL_UART_Transmit(huart, (uint8_t *)"�������", 10,0xFFFF); 	 
	}
	else
	{	
		 RXBUFFER[count++] = ARX_BUFF;   //��������ת��
		 if((RXBUFFER[count-1] == 0x0A)&&(RXBUFFER[count-2] == 0x0D)) //�жϽ���λ
		 {	
			      HAL_UART_Transmit(huart, (uint8_t *)&RXBUFFER, count,0xFFFF); //���յ�����Ϣ���ͳ�ȥ
            while(HAL_UART_GetState(huart) == HAL_UART_STATE_BUSY_TX);//���UART���ͽ���
			      count= 0;
			      memset(RXBUFFER,0x00,sizeof(RXBUFFER)); //�������}}
	          HAL_UART_Receive_IT(huart, (uint8_t *)&ARX_BUFF, 1);   //�ٿ��������ж�
		}
   }
}
