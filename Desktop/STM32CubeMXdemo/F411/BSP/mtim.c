#include "mtim.h"
#include "includes.h"

/*
Systick功能实现us延时，参数SYSCLK为系统时钟
*/
uint32_t fac_us;
 
void HAL_Delay_us_init(uint8_t SYSCLK)
{
     fac_us=SYSCLK; 
}
 
void HAL_Delay_us(uint32_t nus)
{
		static char us_init_flag;
		if(!us_init_flag){
			HAL_Delay_us_init(100);
			us_init_flag = 1;
		}
    uint32_t ticks;
    uint32_t told,tnow,tcnt=0;
    uint32_t reload=SysTick->LOAD;
    ticks=nus*fac_us; 
    told=SysTick->VAL; 
    while(1)
    {
        tnow=SysTick->VAL;
        if(tnow!=told)
        {
            if(tnow<told)tcnt+=told-tnow;
            else tcnt+=reload-tnow+told;
            told=tnow;
            if(tcnt>=ticks)break; 
        }
    };
}
