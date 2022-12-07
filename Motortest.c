#include <18f4550.h>
#device adc=10
#fuses HSPLL, PLL2, CPUDIV1, NOPROTECT, NOWDT, NOMCLR, NOLVP
#use delay (clock=48M)
#use rs232(rcv=pin_c7,xmit=pin_c6,baud=9600,bits=8,parity=n)

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

int16 pwm=0;

volatile int8 aux;      
volatile int8 encoderM1=0;
volatile int8 encoderM1_prev=0;
volatile signed int16 pulsesM1=0;
volatile int8 encoderM2=0;
volatile int8 encoderM2_prev=0;
volatile signed int16 pulsesM2=0;
short flag1, flag2;

#int_rb
void rb_isr(){
   encoderM1=(PORTB&0b00110000)>>4;
   aux=encoderM1^encoderM1_prev;
   flag1=0;
   flag2=0;
   
   if(aux!=0&&aux!=0b00000011)
   {
      flag1=1;
      if(((encoderM1_prev<<1)^encoderM1)&0b00000010)
         pulsesM1--;
      else
         pulsesM1++;
   }
   encoderM1_prev=encoderM1;

   encoderM2=(PORTB&0b11000000)>>6;
   aux=encoderM2^encoderM2_prev;
   if(aux!=0&&aux!=0b00000011)
   {
      flag2=1;
      if(((encoderM2_prev<<1)^encoderM2)&0b00000010)
         pulsesM2++;
      else
         pulsesM2--;
   }
            
   encoderM2_prev=encoderM2;
   
   if(flag1 && flag2)
   set_timer0((int16)0);
}

void main ()
{
   output_low(PIN_D0);
   enable_interrupts(int_rb);
   enable_interrupts(global);
   
   setup_timer_2(T2_DIV_BY_1,255,1);
   setup_ccp1(CCP_PWM);
   
   setup_adc(adc_clock_div_16);
   setup_adc_ports(AN0, VSS_VDD);
   set_adc_channel(0);
   delay_ms(500);
   
   output_high(PIN_D0);
   
   while (true)
   {
      pwm=read_adc();
      set_pwm1_duty(pwm);
      printf("M1:%Ld\t\tM2:%Ld\r\n",pulsesM1, pulsesM2);
      delay_ms(100);
   }
}

