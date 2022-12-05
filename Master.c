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

void fflush();

void main()
{
   char c;
   
   delay_ms(1000);
   
   output_high(PIN_B0);
   delay_ms(500);
   output_high(PIN_B1);
   delay_ms(500);
   output_high(PIN_B2);
   delay_ms(500);
   output_high(PIN_B3);
   delay_ms(500);
   output_high(PIN_B4);
   delay_ms(500);
   output_high(PIN_B5);
   delay_ms(500);
   output_high(PIN_B6);
   delay_ms(500);
   output_high(PIN_B7);
   delay_ms(500);
   
   printf("Hola");
   
   while(true)
   {
     /*if(kbhit())
      {
         c=getc();
         printf("Recibi un: %c",c);
      }*/
      
      output_toggle(PIN_B0);
      output_toggle(PIN_B1);
      output_toggle(PIN_B2);
      output_toggle(PIN_B3);
      output_toggle(PIN_B4);
      output_toggle(PIN_B5);
      output_toggle(PIN_B6);
      output_toggle(PIN_B7);
      delay_ms(1000);
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

