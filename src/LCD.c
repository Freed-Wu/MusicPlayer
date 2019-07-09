#include <LCD.h>
#include "msp430f6638.h"

void SPI_Delay(volatile unsigned int i)
{
  for(i=20000;i>0;i--);                   // Delay
}

//清屏
//Color 清屏颜色 
void LCD_Clear(uint16_t Color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));             // USCI_B1 TX buffer ready?
  UCB1TXBUF = clear;                      // Transmit first character
  __delay_cycles(100);                    // Wait for slave to initialize

  while (!(UCB1IFG&UCTXIFG));             // USCI_B1 TX buffer ready?
  UCB1TXBUF = Color&0xff;                  // Transmit first character
  __delay_cycles(100);                     // Wait for slave to initialize

  while (!(UCB1IFG&UCTXIFG));              // USCI_B1 TX buffer ready?
  UCB1TXBUF = (Color>>8)&0xff;             // Transmit first character
  __delay_cycles(100);                     // Wait for slave to initialize

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}



//显示字符串
//x,y:起点坐标  
//*p:字符串起始地址
//用16字体
//发送格式 命令的标志码 + x坐标 + y坐标 +字符串
//先低位，后高位
void LCD_ShowString(uint8_t x,uint16_t y,const uint8_t *p)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = ShowString;               // 发送命令的标志码       
  __delay_cycles(100);                     // Wait for slave to initialize
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x;                        //发送x坐标
  __delay_cycles(100);                     // Wait for slave to initialize
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y&0xff;                   //发送y坐标低字节
  __delay_cycles(100);                     // Wait for slave to initialize
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y>>8)&0xff;              //发送y坐标高字节
  __delay_cycles(100);                     // Wait for slave to initialize
  
  while(*p != '\0')
  {
     while (!(UCB1IFG&UCTXIFG));       // USCI_B1 TX buffer ready?
     UCB1TXBUF = *p++;                 // 发送要显示的字符串
     __delay_cycles(100);              // Wait for slave to initialize
  }

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)//画线
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawLine;                 // 发送命令的标志码
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x1;                        //发送x坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y1&0xff;                   //发送y1坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y1>>8)&0xff;              //发送y1坐标高字节
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x2;                        //发送x2坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y2&0xff;                   //发送y2坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y2>>8)&0xff;              //发送y2坐标高字节
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

void Draw_Circle(uint8_t x0,uint16_t y0,uint8_t r)//画圆
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawCircle;                 // 发送命令的标志码
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x0;                        //发送x坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y0&0xff;                   //发送y0坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y0>>8)&0xff;              //发送y0坐标高字节
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = r;                        //圆的直径
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

void LCD_DrawRectangle(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2)//画矩形
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawRectangle;            // 发送命令的标志码
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x1;                        //发送x坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y1&0xff;                   //发送y1坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y1>>8)&0xff;              //发送y1坐标高字节
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x2;                        //发送x2坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y2&0xff;                   //发送y2坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y2>>8)&0xff;              //发送y2坐标高字节
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

//填充一块LCD区域
void LCD_Fill(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2, uint16_t color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Fill;                 // 发送命令的标志码
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x1;                       //发送x坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y1&0xff;                  //发送y1坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y1>>8)&0xff;             //发送y1坐标高字节
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x2;                       //发送x2坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y2&0xff;                  //发送y2坐标低字节 
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y2>>8)&0xff;             //发送y2坐标高字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = color&0xff;               //发送color低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (color>>8)&0xff;          //发送color高字节
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}
//画点
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t Color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawPoint;                 // 发送命令的标志码
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x;                        //发送x坐标
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y&0xff;                   //发送y坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y>>8)&0xff;              //发送y坐标高字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Color&0xff;               //发送color低字节 
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (Color>>8)&0xff;          //发送color高字节
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

//显示开启
void LCD_DisplayOn(void)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DisplayOn;                 // 发送命令的标志码
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

}

//显示关闭
void LCD_DisplayOff(void)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DisplayOff;                 // 发送命令的标志码
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

//设置画笔颜色
void LCD_SetTextColor(uint16_t Color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = SetTextColor;                 // 发送命令的标志码
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Color&0xff;                   //发送y1坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (Color>>8)&0xff;              //发送y1坐标高字节
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}


//设置背景色
void LCD_SetBackColor(uint16_t Color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = SetBackColor;                 // 发送命令的标志码
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Color&0xff;                   //发送y1坐标低字节
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (Color>>8)&0xff;              //发送y1坐标高字节
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}


void SPI_SLAVE_Trigger(void)
{
  P3OUT |= BIT6;
  P3OUT &= ~BIT6;
}
