#include <oled.h>

void OLED_GPIO(uint8_t add,uint8_t date)
{
	if(add==0)
	{
		if(date==1) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);//SDA
		else if(date==0)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);//
	}
	else if(add==1)
	{
		if(date==1) HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
		else if(date==0)HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET); //SCL
	}
}
/**************************************************/
/*               IIC Start                        */
/**************************************************/
void IIC_Start()
{
 
	OLED_GPIO(OLED_SDA,1);
	OLED_GPIO(OLED_CLK,1);
	OLED_GPIO(OLED_SDA,0);
	OLED_GPIO(OLED_CLK,0);
}
 
/**************************************************/
/*               IIC Stop                         */
/**************************************************/
void IIC_Stop()
{
	OLED_GPIO(OLED_CLK,1);
	OLED_GPIO(OLED_SDA,0);
	OLED_GPIO(OLED_CLK,1);
	
	OLED_GPIO(OLED_SDA,1);
	OLED_GPIO(OLED_CLK,1);
	
}
 
void IIC_Wait_Ack()  //���Ӧ��
{
	OLED_GPIO(OLED_SDA,0);
	OLED_GPIO(OLED_CLK,1);
	OLED_GPIO(OLED_CLK,0);
 
}
/**************************************************/
/*             IIC Write byte                     */
/**************************************************/
void Write_IIC_Byte(uint8_t IIC_Byte)
{
	uint8_t i;
	uint8_t m,da;
	da=IIC_Byte;
	OLED_GPIO(OLED_CLK,0);
 
	for(i=0;i<8;i++)		
	{
		m=da;
		//	OLED_SCLK_Clr();
		m=m&0x80;
		if(m==0x80)
		{
			OLED_GPIO(OLED_SDA,1);
		}
		else 
			OLED_GPIO(OLED_SDA,0);
		da=da<<1;
		OLED_GPIO(OLED_CLK,1);
		OLED_GPIO(OLED_CLK,0);
 
	}
 
 
}
/*********************************************/
/*      	IIC Write Command		   	     */
/*********************************************/
void Write_IIC_Command(uint8_t IIC_Command) //д����
{
	IIC_Start();
	Write_IIC_Byte(0x78);	// OLED��I2C��ַ����ֹ�޸ģ�
	IIC_Wait_Ack();	
	Write_IIC_Byte(0x00);	// OLED ָ���ֹ�޸ģ�			
	IIC_Wait_Ack();
	Write_IIC_Byte(IIC_Command); 
	IIC_Wait_Ack();	
	IIC_Stop();
}
/*********************************************/
/*       	IIC Write Data	  	   	         */
/*********************************************/
void Write_IIC_Data(uint8_t IIC_Data)   //д����
{
	IIC_Start();
	Write_IIC_Byte(0x78);		// OLED��I2C��ַ����ֹ�޸ģ�		
	IIC_Wait_Ack();	
	Write_IIC_Byte(0x40);		// OLED ���ݣ���ֹ�޸ģ�
	IIC_Wait_Ack();	
	Write_IIC_Byte(IIC_Data);
	IIC_Wait_Ack();	
	IIC_Stop();
}
void OLED_WR_Byte(uint8_t dat,uint8_t cmd) 
{
	if(cmd)
	{
		Write_IIC_Data(dat);
	}
	else 
	{
		Write_IIC_Command(dat);
	}
}
/**************************************************/
/*              ��������                          */
/**************************************************/
 
void OLED_Set_Pos(uint8_t x, uint8_t y) 
{ 	
	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f),OLED_CMD); 
}   	  
 
/**************************************************/
/*              ����OLED��ʾ                      */
/**************************************************/
 
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
}
 
/**************************************************/
/*              �ر�OLED��ʾ                      */
/**************************************************/
     
//void OLED_Display_Off(void)
//{
//	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC����
//	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
//	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
//}		   			 
 
/**************************************************/
/*               OLED����                         */
/**************************************************/
 
//��������,������,������Ļ�Ǻ�ɫ��!��û����һ��!!!	  
void OLED_Clear(void)  
{  
	uint8_t i,n;		    
	for(i=0;i<8;i++)  
	{  
		OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
		OLED_WR_Byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
		OLED_WR_Byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA); 
	} //������ʾ
}
 
/**************************************************/
/*               OLED����ʾ                       */
/**************************************************/
 
//void OLED_On(void)  
//{  
//	ur i,n;		    
//	for(i=0;i<8;i++)  
//	{  
//		OLED_WR_Byte (0xb0+i,OLED_CMD);    //����ҳ��ַ��0~7��
//		OLED_WR_Byte (0x00,OLED_CMD);      //������ʾλ�á��е͵�ַ
//		OLED_WR_Byte (0x10,OLED_CMD);      //������ʾλ�á��иߵ�ַ   
//		for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA); 
//	} //������ʾ
//}
 
/**************************************************/
/*           OLEDдһ���ַ�                       */     
/*           ��ָ��λ����ʾһ���ַ�,���������ַ�  */
/*           x:0~127                              */
/*           y:0~63                               */
/*           mode:0,������ʾ;1,������ʾ           */				 
/*           size:ѡ������ 16/12                  */
/**************************************************/
void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
{      	
	uint8_t c=0,i=0;	
	c=chr-' ';                    //�õ�ƫ�ƺ��ֵ			
	if(x>Max_Column-1)
	{
		x=0;y=y+2;
	}
	if(Char_Size ==16)
	{
		OLED_Set_Pos(x,y);	
		for(i=0;i<8;i++)
		OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
		OLED_Set_Pos(x,y+1);
		for(i=0;i<8;i++)
		OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
	}
	else 
	{	
		OLED_Set_Pos(x,y);
		for(i=0;i<6;i++)
		OLED_WR_Byte(F6x8[c][i],OLED_DATA);
 
	}
}
 
/**************************************************/
/*        ��������m^n����                         */
/**************************************************/
uint16_t oled_pow(uint8_t m,uint8_t n)
{
	uint16_t result=1;	 
	while(n--)
    {
      result*=m; 
    }        
	return result;
} 
 
/**************************************************/
/*         ��ʾ2������                            */
/*         x,y :�������                          */ 
/*         len :���ֵ�λ��                        */
/*         size:�����С                          */
/*         mode:ģʽ	0,���ģʽ;1,����ģʽ     */
/*         num:��ֵ(0~4294967295);                */	 		 
/**************************************************/
void OLED_ShowNum(uint8_t x,uint8_t y,uint16_t num,uint8_t wei,uint8_t size2)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<wei;t++)
	{
		temp=(num/oled_pow(10,wei-t-1))%10;
		if(enshow==0&&t<(wei-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
				continue;
			}
         	else
            enshow=1; 
		} 
	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2); 
	}
}
 

/**************************************************/
/*        ����������ʾһ���ַ��Ŵ�                */
/**************************************************/
void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size)
{
	uint8_t j=0;
	while (chr[j]!='\0')
	{      
        OLED_ShowChar(x,y,chr[j],Char_Size);
		x+=8;
		if(x>120)
        {
        x=0;y+=2;
           }
        j++;
	}
}
 
/**************************************************/
/*          ����������ʾ����                      */
/**************************************************/
void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no)
{      			    
	uint8_t t,adder=0;
	OLED_Set_Pos(x,y);    //��ʾ����λ��	
    for(t=0;t<16;t++)
	{
		 OLED_WR_Byte(Hzk[2*no][t],OLED_DATA);
		 adder+=1;
 	}	
	OLED_Set_Pos(x,y+1);   //����	
    for(t=0;t<16;t++)
	{	
		OLED_WR_Byte(Hzk[2*no+1][t],OLED_DATA);
		adder+=1;
    }					
}
/***********��ʾͼƬ*****************/
void OLED_DrawBMP(uint8_t x0, uint8_t y0,uint8_t x1, uint8_t y1,uint8_t BMP[])
{ 	
	unsigned int j=0;
	uint8_t x,y;
 
	if(y1%8==0) y=y1/8;      
	else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
		for(x=x0;x<x1;x++)
		{      
			OLED_WR_Byte(BMP[j++],OLED_DATA);	    	
		}
	}
} 
/**************************************************/
/*           ����������ʼ��OLED                   */
/**************************************************/
void OLED_Init(void)          
{ 	
  OLED_WR_Byte(0xAE,OLED_CMD);//����ʾ
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address  
	OLED_WR_Byte(0xB0,OLED_CMD);//--set page address
	OLED_WR_Byte(0x81,OLED_CMD); // contract control
	OLED_WR_Byte(0xFF,OLED_CMD);//--128   
	OLED_WR_Byte(0xA1,OLED_CMD);//set segment remap 
	OLED_WR_Byte(0xA6,OLED_CMD);//--normal / reverse
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3F,OLED_CMD);//--1/32 duty
	OLED_WR_Byte(0xC8,OLED_CMD);//Com scan direction
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset
	OLED_WR_Byte(0x00,OLED_CMD);//
	OLED_WR_Byte(0xD5,OLED_CMD);//set osc division
	OLED_WR_Byte(0x80,OLED_CMD);//
    
	OLED_WR_Byte(0xD8,OLED_CMD);//set area color mode off
	OLED_WR_Byte(0x05,OLED_CMD);//
	
	OLED_WR_Byte(0xD9,OLED_CMD);//Set Pre-Charge Period
	OLED_WR_Byte(0xF1,OLED_CMD);//
	
	OLED_WR_Byte(0xDA,OLED_CMD);//set com pin configuartion
	OLED_WR_Byte(0x12,OLED_CMD);//
	
	OLED_WR_Byte(0xDB,OLED_CMD);//set Vcomh
	OLED_WR_Byte(0x30,OLED_CMD);//
	
	OLED_WR_Byte(0x8D,OLED_CMD);//set charge pump enable
	OLED_WR_Byte(0x14,OLED_CMD);//
	
	OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel
	
	OLED_Display_On();
	OLED_Clear();
} 