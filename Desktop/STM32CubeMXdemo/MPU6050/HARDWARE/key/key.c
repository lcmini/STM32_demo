#include <key.h>

int  KEY_SCAN(void)
{
   if(KEY0 == 0 | KEY1 == 0 | KEY2 == 0 |KEY_UP == 1)
	 {
	     HAL_Delay(10);
		   if(KEY0 == 0)return KEY0_PRES;
		   if (KEY1 == 0)  return KEY1_PRES;
		   if (KEY2 == 0)  return KEY2_PRES;
		   if (KEY_UP == 1)  return KEY_UP_PRES;  
	 }
   if(KEY0 == 1 && KEY1 == 1 && KEY2 == 1 &&KEY_UP == 0)
   return 0;

}