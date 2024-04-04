#include <led.h>

void LED0_SHIE(void)
{
   LED0_ON();
   HAL_Delay(100);
	 LED0_OFF();
	 HAL_Delay(100);
}

void LED1_SHIE(void)
{
   LED1_ON();
   HAL_Delay(100);
	 LED1_OFF();
	 HAL_Delay(100);

}

void LED2_SHIE(void)
{
   LED2_ON();
   HAL_Delay(100);
	 LED2_OFF();
	 HAL_Delay(100);

}

void LED3_SHIE(void)
{
   LED3_ON();
   HAL_Delay(100);
	 LED3_OFF();
	 HAL_Delay(100);

}