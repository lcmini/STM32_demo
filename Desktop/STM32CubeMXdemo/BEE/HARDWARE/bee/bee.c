#include <bee.h>

void BEE_BOOT(void)
{
  // HAL_GPIO_WritePin(GP)
	 BEE_ON();
	 HAL_Delay(1000);
	 BEE_OFF();
	 HAL_Delay(1000);
}