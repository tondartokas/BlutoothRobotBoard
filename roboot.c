//version 0.01
#include <mega8.h>
//#include <delay.h>

// Declare your global variables here

// Standard Input/Output functions
#include <stdio.h>

void main(void)
{
char input;

PORTD=0x00;
DDRD=0xFC;

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (1<<RXEN) | (1<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);
UBRRH=0x00;
UBRRL=0x33;

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADFR) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);
                       
//delay_ms(500);
//printf("hello \n\r");

while (1)
      {               
      input = getchar();      
      switch (input) 
      {
        case'U':
            //PORTD=0x50;  
            PORTD.4=1;
            PORTD.5=0;
            PORTD.6=1;
            PORTD.7=0;
        break;
        case 'D':
            //PORTD=0xA0;
            PORTD.4=0;
            PORTD.5=1;
            PORTD.6=0;
            PORTD.7=1;
        break;
        case 'L':      
            //PORTD=0x60;//1
            PORTD.4=0;
            PORTD.5=1;
            PORTD.6=1;
            PORTD.7=0;
        break;
        case 'R':
            //PORTD=0x90;//4
            PORTD.4=1;
            PORTD.5=0;
            PORTD.6=0;
            PORTD.7=1;
        break;        
        case 'S':
            //PORTD=0x00;
            PORTD.4=0;
            PORTD.5=0;
            PORTD.6=0;
            PORTD.7=0;
        break;    
        case '1':
            PORTD.2=1;
        break;
        case '2':
            PORTD.2=0;
        break;
        case '3':
            PORTD.3=1;
        break;
        case '4':
            PORTD.3=0;
        break;
      }; 
 
      putchar(input);//reply in termia for debuging

      }
}