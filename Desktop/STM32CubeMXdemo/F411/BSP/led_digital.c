#include "led_digital.h"
#include "includes.h"

//������������
//0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,ȫ��
uint8_t smg_num[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,
										0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e,0x01,0x00};


void HC138_Write_Byte(uint8_t num)//HC138����λ
{
	HAL_GPIO_WritePin(HC138_A0_GPIO_Port,HC138_A0_Pin,(GPIO_PinState)num&0x01);
	HAL_GPIO_WritePin(HC138_A1_GPIO_Port,HC138_A1_Pin,(GPIO_PinState)(num&0x02)>>1);
	HAL_GPIO_WritePin(HC138_A2_GPIO_Port,HC138_A2_Pin,(GPIO_PinState)(num&0x04)>>2);
}


void LED_Digital_Write_Data(uint8_t duan,uint8_t wei)
{
	uint8_t i;
	for( i=0;i<8;i++)//���Ͷ�
	{
		HAL_GPIO_WritePin(HC595_DATA_GPIO_Port,HC595_DATA_Pin,(GPIO_PinState)(duan>>i)&0x01);
		HAL_GPIO_WritePin(HC595_SCLK_GPIO_Port,HC595_SCLK_Pin,(GPIO_PinState)0);
		HAL_Delay_us(5);
		HAL_GPIO_WritePin(HC595_SCLK_GPIO_Port,HC595_SCLK_Pin,(GPIO_PinState)1);
	}
	HC138_Write_Byte(wei);//��ѡ��λ
}
void LED_Digital_Refresh(void)
{
	HAL_GPIO_WritePin(HC595_LCLK_GPIO_Port,HC595_LCLK_Pin,(GPIO_PinState)1);
	HAL_Delay_us(5);
	HAL_GPIO_WritePin(HC595_LCLK_GPIO_Port,HC595_LCLK_Pin,(GPIO_PinState)0);
}

void led_digital_text(void)
{
	static uchar wei_temp;
	static uchar smg_num_temp;
	if(wei_temp==8)wei_temp = 0;
	if(smg_num_temp==18)smg_num_temp = 0;
	LED_Digital_Write_Data(smg_num[smg_num_temp],wei_temp);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	wei_temp++;
	smg_num_temp++;
	HAL_Delay(300);
}

extern int key_scan_return ;
void led_digital_add_minus(void)
{
	
	static int tags;//λ��1-8
	static int tags_count;//λ���ۼ�
	static int tags_count_temp;//λ���ۼ�
	
	if(key_scan()==0)tags_count++;
	if(key_scan()==1)tags_count--;
	if(key_scan()==2)tags_count = 0;
	tags_count_temp = tags_count;
	if(tags_count<0)tags_count = 0;
	if(tags_count>=99999999)tags_count = 99999999;
	
	static int tag1_count;
	static int tag2_count;
	static int tag3_count;
	static int tag4_count;
	static int tag5_count;
	static int tag6_count;
	static int tag7_count;
	static int tag8_count;
	
	tag1_count = tags_count_temp%10;
	tags_count_temp = tags_count_temp/10;
	tag2_count = tags_count_temp%10;
	tags_count_temp = tags_count_temp/10;
	tag3_count = tags_count_temp%10;
	tags_count_temp = tags_count_temp/10;
	tag4_count = tags_count_temp%10;
	tags_count_temp = tags_count_temp/10;
	tag5_count = tags_count_temp%10;
	tags_count_temp = tags_count_temp/10;
	tag6_count = tags_count_temp%10;
	tags_count_temp = tags_count_temp/10;
	tag7_count = tags_count_temp%10;
	tags_count_temp = tags_count_temp/10;
	tag8_count = tags_count_temp%10;
	
	key_scan_return = -1;


	LED_Digital_Write_Data(smg_num[tag1_count],7-0);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	LED_Digital_Write_Data(smg_num[tag2_count],7-1);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	LED_Digital_Write_Data(smg_num[tag3_count],7-2);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	LED_Digital_Write_Data(smg_num[tag4_count],7-3);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	LED_Digital_Write_Data(smg_num[tag5_count],7-4);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	LED_Digital_Write_Data(smg_num[tag6_count],7-5);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	LED_Digital_Write_Data(smg_num[tag7_count],7-6);//�������ʾ
	LED_Digital_Refresh();//ˢ����ʾ
	LED_Digital_Write_Data(smg_num[tag8_count],7-7);//�������ʾ

		
	LED_Digital_Refresh();//ˢ����ʾ

}
