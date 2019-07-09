#ifndef H_LCD_H
#define H_LCD_H
#include "stdint.h"

/************************************************************/
void LCD_Clear(uint16_t Color);//����
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t Color);//����
void LCD_ShowString(uint8_t x,uint16_t y,const uint8_t *p);//��ʾһ���ַ���,16����
void LCD_DrawLine(uint16_t x1,uint16_t y1, uint16_t x2, uint16_t y2);//����
void Draw_Circle(uint8_t x0,uint16_t y0,uint8_t r);//��Բ
void LCD_DrawRectangle(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2);//������
void LCD_Fill(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2, uint16_t color);//���һ����������
void LCD_DisplayOn(void);//��ʾ����
void LCD_DisplayOff(void);//��ʾ�ر�
void LCD_SetTextColor(uint16_t Color);//���û�����ɫ
void LCD_SetBackColor(uint16_t Color);//���ñ���ɫ
/************************************************************/

void SPI_SLAVE_Trigger(void);
void SPI_Delay(volatile unsigned int i);


//��������
#define clear         	  0x11
#define ShowString        0x22
#define DrawLine          0x33
#define DrawCircle        0x44
#define DrawRectangle     0x55
#define Fill              0x66
#define DrawPoint         0x77
#define DisplayOn         0x88
#define DisplayOff        0x99
#define SetTextColor      0xaa
#define SetBackColor      0xbb


//������ɫ
#define WHITE         	0xFFFF
#define BLACK         	0x0000	  
#define BLUE         	0x001F  
#define BRED            0XF81F
#define GRED 		0XFFE0
#define GBLUE		0X07FF
#define RED           	0xF800
#define MAGENTA       	0xF81F
#define GREEN         	0x07E0
#define CYAN          	0x7FFF
#define YELLOW        	0xFFE0
#define BROWN 		0XBC40 //��ɫ
#define BRRED 		0XFC07 //�غ�ɫ
#define GRAY  		0X8430 //��ɫ
//GUI��ɫ

#define DARKBLUE      	 0X01CF	//����ɫ
#define LIGHTBLUE      	 0X7D7C	//ǳ��ɫ  
#define GRAYBLUE       	 0X5458 //����ɫ
//������ɫΪPANEL����ɫ 
 
#define LIGHTGREEN     	 0X841F //ǳ��ɫ
//#define LIGHTGRAY      0XEF5B //ǳ��ɫ(PANNEL)
#define LGRAY 	         0XC618 //ǳ��ɫ(PANNEL),���屳��ɫ

#define LGRAYBLUE        0XA651 //ǳ����ɫ(�м����ɫ)
#define LBBLUE           0X2B12 //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)

#endif
