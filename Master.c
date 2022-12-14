#include <18f4550.h>
#fuses HSPLL, PLL2, CPUDIV1, NOPROTECT, NOWDT, NOMCLR, NOLVP
#use delay (clock=48M)
#use rs232(xmit = PIN_C6, rcv = PIN_C7, baud =9600, bits = 8, parity = N)
#include <string.h>
#include <stdlib.h>

//SPI Registers
#BYTE SSPBUF = 0xFC9
#BYTE SSPSTAT =0xFC7
#BYTE SSPCON1 =0xFC6
#bit BUFFER_FULL=0xFC7.0
#bit OVERFLOW=0xFC6.6
#bit COLLISION=0xFC6.7
#bit CREN=0xFAB.4    // Continuous Receive Enable Bit
#bit OERR=0xFAB.1    // Overrun Error Bit

#byte PORTA = 0xF80
#byte PORTB = 0xF81
#byte PORTC = 0xF82
#byte PORTD = 0xF83
#byte PORTE = 0xF84
#byte TRISA = 0xF92
#byte TRISB = 0xF93
#byte TRISC = 0xF94
#byte TRISD = 0xF95
#byte TRISE = 0xF96

unsigned int16 constantuS=476; //
int i;
void fflush();
char c;

#int_rda
void rcv_data()
{
   c = getchar();
}

void main()
{
   delay_ms(100);
   enable_interrupts(INT_RDA);
   enable_interrupts(GLOBAL);
   delay_ms(900);
   
   output_high(PIN_B0);
   delay_ms(1000);
   output_high(PIN_B1);
   delay_ms(1000);
   output_high(PIN_B2);
   delay_ms(1000);
   output_high(PIN_B3);
   delay_ms(1000);
   output_high(PIN_B4);
   delay_ms(1000);
   output_high(PIN_B5);
   delay_ms(1000);
   output_high(PIN_B6);
   delay_ms(1000);
   output_high(PIN_B7);
   delay_ms(1000);
   fflush();
   //printf("Hola");
   
   while(true)
   {
      switch (c)
      {
         case 0xA6:
         {
            // T
            PORTB=0b00000001;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b00000001;
            for(i=0;i<9;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // I
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b00000000;
            for(i=0;i<9;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // Z
            PORTB=0b10000001;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            PORTB=0b11100001;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            PORTB=0b10011001;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            PORTB=0b10000111;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            PORTB=0b10000001;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            PORTB=0b00000000;
            delay_ms(124);
            delay_us(400);
            break;
         }
         
         case 0x66:
         {
            // E      
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b10001001;
            for(i=0;i<19;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // M      
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b00000011;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            PORTB=0b00000110;
            for(i=0;i<3;i++)
            delay_us(constantuS);
            
            PORTB=0b00001100;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            PORTB=0b00000110;
            for(i=0;i<3;i++)
            delay_us(constantuS);
            
            PORTB=0b00000011;
            for(i=0;i<4;i++)
            delay_us(constantuS);
            
            PORTB=0b11111111;
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // I
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b00000000;
            for(i=0;i<9;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // L
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b10000000;
            for(i=0;i<19;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            PORTB=0b00000000;
            delay_ms(110);
            delay_us(120);
            break;
         }
         
         case 0xE6:
         {
            // C
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b10000001;
            for(i=0;i<19;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // H
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b00001000;
            for(i=0;i<18;i++)
            delay_us(constantuS);
            
            PORTB=0b11111111;
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // E      
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b10001001;
            for(i=0;i<19;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // L
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b10000000;
            for(i=0;i<19;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            // L
            PORTB=0b11111111;
            delay_us(constantuS);
            
            PORTB=0b10000000;
            for(i=0;i<19;i++)
            delay_us(constantuS);
            
            // 
            PORTB=0b00000000;
            for(i=0;i<10;i++)
            delay_us(constantuS);
            
            PORTB=0b00000000;
            delay_ms(95);
            delay_us(840);
            
            break;
         }
         
         default:
         {
            PORTB=0b10101010;
            break;
         }
      }
   }
}

void fflush()
{
   if(OERR)
   {
      getc();     //Clear buffer
      getc();
      CREN=0;      //Clear CREN bit
      CREN=1;           
   }
}

