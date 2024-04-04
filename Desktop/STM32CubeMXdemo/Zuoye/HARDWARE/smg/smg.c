#include "smg.h"
 
//共阴数字数组
//0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,全灭
const uint8_t smg_num[]={0xfc,0x60,0xda,0xf2,0x66,0xb6,0xbe,0xe0,0xfe,0xf6,0xee,0x3e,0x9c,0x7a,0x9e,0x8e,0x01,0x00};
 
//74HC138驱动
//数码管位选
//num:要显示的数码管编号 0-7(共8个数码管)
void LED_Wei(uint8_t num)
{
  if(num&0x01)HC138_A0_H;
  else HC138_A0_L;
 
  if(num&0x02)HC138_A1_H;
  else HC138_A1_L;
 
  if(num&0x04)HC138_A2_H;
  else HC138_A2_L;
}
 
//74HC595驱动
//数码管显示
//duan:显示的段码0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F, .,全灭
//wei:要显示的数码管编号 0-7(共8个数码管)
void LED_Write_Data(uint8_t duan,uint8_t wei)
{
	uint8_t i;
  uint8_t smg_duan = smg_num[duan];
	for( i=0;i<8;i++)//先选段
	{
    if((smg_duan>>i)&0x01)HC595_DATA_H;
    else HC595_DATA_L;
      
		HC595_SCLK_L;
		 HAL_Delay(100);
		HC595_SCLK_H;
	}
    LED_Wei(wei);//后选中位
}
 
/*74HC595驱动,数码管刷新显示*/
void LED_Refresh(void)
{
	HC595_LCLK_H;
	 HAL_Delay(100);
	HC595_LCLK_L;
}
 