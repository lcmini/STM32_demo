#ifndef  _LED_DIGITAL_H_
#define  _LED_DIGITAL_H_
#include "includes.h"

extern uint8_t smg_num[];

void LED_Digital_Refresh(void);
void LED_Digital_Write_Data(uint8_t duan,uint8_t wei);
void HC138_Write_Byte(uint8_t num);//HC138¿ØÖÆÎ»
void led_digital_text(void);
void led_digital_add_minus(void);

#endif
