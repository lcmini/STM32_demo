#include "pwm.h"
unsigned int pwm_compare = 50;
unsigned int pwm_compare_dir = 0;
unsigned int pwm_Autoreload = 100-1;
unsigned int pwm_Autoreload_dir = 0;


//		if(pwm_compare_dir==0)
//		{
//			
//			pwm_compare+=1;
//			if(pwm_compare==100)pwm_compare_dir = 1;
//		}if(pwm_compare_dir==1)
//		{
//			pwm_compare-=1;
//			if(pwm_compare==0)pwm_compare_dir = 0;
//		}
//		
//		if(pwm_Autoreload_dir==0)
//		{
//			
//			pwm_Autoreload+=1;
//			if(pwm_Autoreload==200)pwm_Autoreload_dir = 1;
//		}if(pwm_Autoreload_dir==1)
//		{
//			pwm_Autoreload-=1;
//			if(pwm_Autoreload==100)pwm_Autoreload_dir = 0;
//		}
//		__HAL_TIM_SetAutoreload(&htim3,pwm_Autoreload);
//		__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,pwm_compare);
		
//		printf("Hello world !\r\n");
//		HAL_Delay(50);

