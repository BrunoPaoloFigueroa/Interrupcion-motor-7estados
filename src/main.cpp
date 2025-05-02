#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
char comando=0;
char pos=0;

void config_PCI(void){

      PCICR |= 0x04;              
      PCMSK2 |= 0x0E;             

      DDRD &= ~(0x0E);            
      PORTD |= 0x0E;              

      

}


ISR(PCINT2_vect) {
  char entrada=PIND&0X0E;
  _delay_ms(100);
  switch (entrada) {
    case 0x02:              
        comando = 0x02;
        break;
    case 0x04:             
        comando = 0x04;
        break;
    case 0x06:          
        comando = 0x06;
        break;
    case 0x08:           
        comando = 0x08;
        break;
    case 0x0A:             
        comando = 0x0A;
        break;
    case 0x0C:              
        comando = 0x0C;
        break;
    case 0x0E:              
        comando = 0x0E;
        break;
    default:
        break;
}
}

void tarea(char t){

  switch (t){

      

    case 0x02:

    //PARO
    PORTD&=~(0x10);   //Motor A
    PORTD&=~(0x20);

    PORTD&=~(0x40);   //Motor B
    PORTD&=~(0x80);


    break;

    case 0x04:

    //Avance
    PORTD|=0x10;   //Motor A
    PORTD&=~(0x20);

    PORTD|=0x40;   //Motor B
    PORTD&=~(0x80);
 

    break;

    case 0x06:

    //Retro
    PORTD&=~(0x10);   //Motor A
    PORTD|=(0x20);

   
    PORTD&=~(0x40);   //Motor B
    PORTD|=(0x80);

    break;

    case 0x08:

    //Derecha Larga
    PORTD&=~(0x10);   //Motor A
    PORTD&=~(0x20);

    PORTD|=0x40;   //Motor B
    PORTD&=~(0x80);

    break;

    case 0x0A:

    //Derecha Corta
    PORTD&=~(0x10);   //Motor A
    PORTD|=(0x20);

    PORTD|=0x40;   //Motor B
    PORTD&=~(0x80);

    break;

    case 0x0C:

    //Izquierda Larga
    PORTD|=(0x10);   //Motor A
    PORTD&=~(0x20);

    PORTD&=~(0x40);   //Motor B
    PORTD&=~(0x80);

    break;

    case 0x0E:

     //Izquierda Corta
     PORTD|=(0x10);   //Motor A
     PORTD&=~(0x20);

     PORTD&=~(0x40);   //Motor B
     PORTD|=(0x80);

     break;      

}

}

int main(void){
    DDRD |= 0xF0;  
    PORTD &= ~(0xF0);
    config_PCI();
    sei();    
    while(1){
      tarea(comando);
      _delay_ms(500);
    }
  
}