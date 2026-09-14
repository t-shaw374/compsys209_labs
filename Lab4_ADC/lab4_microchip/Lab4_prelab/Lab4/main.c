/*
 * Lab4.c
 *
 * Created: 14/09/2026 9:38:49 pm
 * Author : thoma
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>

//#define BUTTON_PRESSED (PINB & (1<<PINB7))


int main(void)
{
	
	DDRB |= (1 << DDB5);
	DDRB &= ~(1<<DDB7);
	
	//DDRB = 0xFF; //output
	//DDRC = 0x00; //input
	//DDRD = 0x00; //input
	
    /* Replace with your application code */
    while (1) 
    {
		
		
		
		
		
// 		if (BUTTON_PRESSED) {
// 			PORTB &= ~(1<<PINB5);
// 		}
// 		else {
// 			PORTB |= (1<<PINB5);
// 		}
		//_delay_ms(0.5);
    }
}

