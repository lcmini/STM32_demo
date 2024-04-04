#include "smg.h"
 
//������������
//0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,ȫ��
const uint8_t smg_num[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e,0x01,0x00};
 
//74HC138����
//�����λѡ
//num:Ҫ��ʾ������ܱ�� 0-7(��8�������)
void LED_Wei(uint8_t num)
{
  if(num&0x01)HC138_A0_H;
  else HC138_A0_L;
 
  if(num&0x02)HC138_A1_H;
  else HC138_A1_L;
 
  if(num&0x04)HC138_A2_H;
  else HC138_A2_L;
}
 
//74HC595����
//�������ʾ
//duan:��ʾ�Ķ���0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,ȫ��
//wei:Ҫ��ʾ������ܱ�� 0-7(��8�������)
void LED_Write_Data(uint8_t duan,uint8_t wei)
{
	uint8_t i;
  uint8_t smg_duan = smg_num[duan];
	for( i=0;i<8;i++)//��ѡ��
	{
    if((smg_duan>>i)&0x01)HC595_DATA_H;
    else HC595_DATA_L;
      
		HC595_SCLK_L;
		 HAL_Delay(100);
		HC595_SCLK_H;
	}
    LED_Wei(wei);//��ѡ��λ
}
 
/*74HC595����,�����ˢ����ʾ*/
void LED_Refresh(void)
{
	HC595_LCLK_H;
	 HAL_Delay(100);
	HC595_LCLK_L;
}
 