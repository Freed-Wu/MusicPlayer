#ifndef H_LCD_H
#define H_LCD_H
#include "stdint.h"

/************************************************************/
void LCD_Clear(uint16_t Color);//清屏
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t Color);//画点
void LCD_ShowString(uint8_t x,uint16_t y,const uint8_t *p);//显示一个字符串,16字体
void LCD_DrawLine(uint16_t x1,uint16_t y1, uint16_t x2, uint16_t y2);//画线
void Draw_Circle(uint8_t x0,uint16_t y0,uint8_t r);//画圆
void LCD_DrawRectangle(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2);//画矩形
void LCD_Fill(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2, uint16_t color);//填充一个矩形区域
void LCD_DisplayOn(void);//显示开启
void LCD_DisplayOff(void);//显示关闭
void LCD_SetTextColor(uint16_t Color);//设置画笔颜色
void LCD_SetBackColor(uint16_t Color);//设置背景色
/************************************************************/

void SPI_SLAVE_Trigger(void);
void SPI_Delay(volatile unsigned int i);


//命令类型
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


//画笔颜色
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
#define BROWN 		0XBC40 //棕色
#define BRRED 		0XFC07 //棕红色
#define GRAY  		0X8430 //灰色
//GUI颜色

#define DARKBLUE      	 0X01CF	//深蓝色
#define LIGHTBLUE      	 0X7D7C	//浅蓝色  
#define GRAYBLUE       	 0X5458 //灰蓝色
//以上三色为PANEL的颜色 
 
#define LIGHTGREEN     	 0X841F //浅绿色
//#define LIGHTGRAY      0XEF5B //浅灰色(PANNEL)
#define LGRAY 	         0XC618 //浅灰色(PANNEL),窗体背景色

#define LGRAYBLUE        0XA651 //浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 //浅棕蓝色(选择条目的反色)

#endif
