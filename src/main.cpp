#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>

char pos=0;

void config_PCI(void){

      PCICR |= 0x04;              
      PCMSK2 |= 0x0E;             

      DDRD &= ~(0x0E);            
      PORTD |= 0x0E;              

      DDRD |= 0xF0;  


}
