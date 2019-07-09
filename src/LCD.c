#include <LCD.h>
#include "msp430f6638.h"

void SPI_Delay(volatile unsigned int i)
{
  for(i=20000;i>0;i--);                   // Delay
}

//����
//Color ������ɫ 
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



//��ʾ�ַ���
//x,y:�������  
//*p:�ַ�����ʼ��ַ
//��16����
//���͸�ʽ ����ı�־�� + x���� + y���� +�ַ���
//�ȵ�λ�����λ
void LCD_ShowString(uint8_t x,uint16_t y,const uint8_t *p)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = ShowString;               // ��������ı�־��       
  __delay_cycles(100);                     // Wait for slave to initialize
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x;                        //����x����
  __delay_cycles(100);                     // Wait for slave to initialize
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y&0xff;                   //����y������ֽ�
  __delay_cycles(100);                     // Wait for slave to initialize
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y>>8)&0xff;              //����y������ֽ�
  __delay_cycles(100);                     // Wait for slave to initialize
  
  while(*p != '\0')
  {
     while (!(UCB1IFG&UCTXIFG));       // USCI_B1 TX buffer ready?
     UCB1TXBUF = *p++;                 // ����Ҫ��ʾ���ַ���
     __delay_cycles(100);              // Wait for slave to initialize
  }

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2)//����
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawLine;                 // ��������ı�־��
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x1;                        //����x����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y1&0xff;                   //����y1������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y1>>8)&0xff;              //����y1������ֽ�
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x2;                        //����x2����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y2&0xff;                   //����y2������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y2>>8)&0xff;              //����y2������ֽ�
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

void Draw_Circle(uint8_t x0,uint16_t y0,uint8_t r)//��Բ
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawCircle;                 // ��������ı�־��
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x0;                        //����x����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y0&0xff;                   //����y0������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y0>>8)&0xff;              //����y0������ֽ�
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = r;                        //Բ��ֱ��
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

void LCD_DrawRectangle(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2)//������
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawRectangle;            // ��������ı�־��
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x1;                        //����x����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y1&0xff;                   //����y1������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y1>>8)&0xff;              //����y1������ֽ�
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x2;                        //����x2����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y2&0xff;                   //����y2������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y2>>8)&0xff;              //����y2������ֽ�
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

//���һ��LCD����
void LCD_Fill(uint8_t x1, uint16_t y1, uint8_t x2, uint16_t y2, uint16_t color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Fill;                 // ��������ı�־��
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x1;                       //����x����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y1&0xff;                  //����y1������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y1>>8)&0xff;             //����y1������ֽ�
  __delay_cycles(100);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x2;                       //����x2����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y2&0xff;                  //����y2������ֽ� 
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y2>>8)&0xff;             //����y2������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = color&0xff;               //����color���ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (color>>8)&0xff;          //����color���ֽ�
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}
//����
void LCD_DrawPoint(uint16_t x,uint16_t y,uint16_t Color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DrawPoint;                 // ��������ı�־��
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = x;                        //����x����
  __delay_cycles(100);
 
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = y&0xff;                   //����y������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (y>>8)&0xff;              //����y������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Color&0xff;               //����color���ֽ� 
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (Color>>8)&0xff;          //����color���ֽ�
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

//��ʾ����
void LCD_DisplayOn(void)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DisplayOn;                 // ��������ı�־��
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

}

//��ʾ�ر�
void LCD_DisplayOff(void)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = DisplayOff;                 // ��������ı�־��
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}

//���û�����ɫ
void LCD_SetTextColor(uint16_t Color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = SetTextColor;                 // ��������ı�־��
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Color&0xff;                   //����y1������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (Color>>8)&0xff;              //����y1������ֽ�
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}


//���ñ���ɫ
void LCD_SetBackColor(uint16_t Color)
{
  SPI_SLAVE_Trigger();
  SPI_Delay(20000);

  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = SetBackColor;                 // ��������ı�־��
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = Color&0xff;                   //����y1������ֽ�
  __delay_cycles(100);
  
  while (!(UCB1IFG&UCTXIFG));           // USCI_B1 TX buffer ready?
  UCB1TXBUF = (Color>>8)&0xff;              //����y1������ֽ�
  __delay_cycles(100);

  SPI_SLAVE_Trigger();
  SPI_Delay(20000);
}


void SPI_SLAVE_Trigger(void)
{
  P3OUT |= BIT6;
  P3OUT &= ~BIT6;
}
