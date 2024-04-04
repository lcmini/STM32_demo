#include "includes.h"

void led_river(void)
{
	for(int i=0;i<8;i++)
		{
			HAL_GPIO_TogglePin(GPIOC,1<<i);
			HAL_Delay(50);
			HAL_GPIO_TogglePin(GPIOC,1<<i);
		}
}

uchar temp;
uchar flag = 1;
void led_key_control(void)
{
	temp = Key_Scan();
	if(temp == 0)
	{
		
		if(flag && (temp == 0))
		{
			HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_0);
			flag = 0;
		}
		
	}
	if(temp == 4)flag = 1;
}
