#include <exit.h>
#include <led.h>
#include <bee.h>
#include <key.h>


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	  HAL_Delay(100);
    switch(GPIO_Pin)
    {
        case GPIO_PIN_0:
            if(KEY_UP==1) 
            {
							LED0_SHIE();
            }
            break;
        case GPIO_PIN_8:
            if(KEY0==0)  	
            {
							LED1_SHIE();
            }
            break;
        case GPIO_PIN_9:
            if(KEY1==0)  
            {
							LED2_SHIE();
            }
            break;
	    case GPIO_PIN_2:
			if(KEY2==0)
			{
				LED3_SHIE();
			}
				
    }
}






