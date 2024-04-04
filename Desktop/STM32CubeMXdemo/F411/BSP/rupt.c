#include "includes.h"
#include "rupt.h"

uchar key0_value,key1_value,key2_value;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == KEY0_Pin)
	{
		key0_value++;
	}
	if(GPIO_Pin == KEY1_Pin)
	{
		key1_value++;
	}
	if(GPIO_Pin == KEY2_Pin)
	{
		key2_value++;
	}
	
}
 int key_scan_return = -1;
int key_scan(void)
{
	static uchar key0_value_last,key1_value_last,key2_value_last;
	
	if(key0_value-key0_value_last!=0)key_scan_return = 0;
	if(key1_value-key1_value_last!=0)key_scan_return = 1;
	if(key2_value-key2_value_last!=0)key_scan_return = 2;
//	else key_scan_return = -1;
	key0_value_last = key0_value;
	key1_value_last = key1_value;
	key2_value_last = key2_value;
	
	return key_scan_return;
}






