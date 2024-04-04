#ifndef __OLED_H_
#define __OLED_H_
 
#include <ziku.h>
/**************************************************/
/*                宏定义                          */
/**************************************************/
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据
#define OLED_MODE 0
#define OLED_SDA  0
#define OLED_CLK  1
 
//OLED模式设置
//0:4线串行模式
//1:并行8080模式
 
#define SIZE 16
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
 
void OLED_GPIO(uint8_t add,uint8_t date);
void IIC_Start();
void IIC_Stop();
void IIC_Wait_Ack();
void Write_IIC_Byte(uint8_t IIC_Byte);
void Write_IIC_Command(uint8_t IIC_Command);
void Write_IIC_Data(uint8_t IIC_Data);
void OLED_WR_Byte(uint8_t dat,uint8_t cmd);
void OLED_Set_Pos(uint8_t x, uint8_t y);
void OLED_Display_On(void);
void OLED_Clear(void);
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size);
uint16_t oled_pow(uint8_t m,uint8_t n);
void OLED_ShowNum(uint8_t x,uint8_t y,uint16_t num,uint8_t wei,uint8_t size2);
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size);
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no);
void OLED_DrawBMP(uint8_t x0, uint8_t y0,uint8_t x1, uint8_t y1,uint8_t BMP[]);
void OLED_Init(void);



#endif