/*
 * lab5.c
 *
 * Created: 21/09/2026 2:14:26 pm
 * Author : thoma
 */ 

#include "common.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"
//#include <util/delay.h>

//#define LED_ON PORTB |= (1 << PB5);
// #define LED_OFF PORTB &= ~(1 << PB5);

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00;
	timer_init(77);
	sei();
    /* Replace with your application code */
    while (1) 
    {
		
		
		
		//if(timer0_check_Clear_compare()) {
			//toggle_led();
		//}
		
		
		//LED_ON;
		//_delay_ms(0.375);
		//LED_OFF;
		//_delay_ms(0.125);
    }
}

