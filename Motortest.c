#include <18f4550.h>
#device adc=10
#fuses HSPLL, PLL2, CPUDIV1, NOPROTECT, NOWDT, NOMCLR, NOLVP
#use delay (clock=48M)
//#use rs232(rcv=pin_c7,xmit=pin_c6,baud=9600,bits=8,parity=n)
/*
#include <lcd.c>

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

unsigned int32 pwm=0;
unsigned int32 tmr0=0;
float RPM=0;

volatile int8 aux;      

volatile int8 encoderM2=0;
volatile int8 encoderM2_prev=0;
volatile signed int16 pulsesM2=0;

#int_rb
void rb_isr(){
   encoderM2=(PORTB&0b11000000)>>6;
   aux=encoderM2^encoderM2_prev;
   if(aux!=0&&aux!=0b00000011)
   {
      if(((encoderM2_prev<<1)^encoderM2)&0b00000010)
      {
         pulsesM2++;
      }
      else
      {
         pulsesM2--;
         
      }
   } 
   
   if(pulsesM2>=940)
   {
      tmr0=get_timer0();
      set_timer0((int16)0);
      pulsesM2=0;
   }
   encoderM2_prev=encoderM2;
}
*/

void main ()
{
   delay_ms(1000);
   setup_timer_2(T2_DIV_BY_1,255,1);
   setup_ccp1(CCP_PWM);
   //delay_ms(500);
   /*
   //output_low(PIN_D0);
   enable_interrupts(int_rb);
   enable_interrupts(global);
   lcd_init();
   setup_timer_0(T0_INTERNAL|T0_DIV_256);
   
   
   
   set_timer0(0);   
   tmr0=get_timer0(); 
   */
   /*
   setup_adc(adc_clock_div_16);
   setup_adc_ports(AN0, VSS_VDD);
   set_adc_channel(0);
   delay_ms(500);
   */
   set_pwm1_duty((int16)920);
   
   //output_high(PIN_D0);
   
   while (true)
   {
      //pwm=read_adc();
      
      
      /*
      RPM=TMR0;
      RPM=RPM/(46875.0);
      RPM=60.0/RPM;          
      
      lcd_putc('\f');      //LIMPIAR LA PANTALLA LCD
      lcd_gotoxy(1,1); 
      printf(lcd_putc,"RPM: %f",RPM); 
      lcd_gotoxy(1,2);
      printf(lcd_putc,"%Ld, %Ld, %Ld",pulsesM2,tmr0,pwm); 
      //printf("M1:%Ld\t\tM2:%Ld\r\n",pulsesM1, pulsesM2);
      delay_ms(200);
      */
   }
}

