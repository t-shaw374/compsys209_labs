/*
 * lab6prelab.c
 *
 * Created: 28/09/2026 10:25:53 pm
 * Author : thoma
 */ 
#define F_CPU 2000000UL
#include <avr/io.h>

#define DS1_high PORTB |= (1<<PB0)
#define DS2_high PORTB |= (1<<PB1)
#define DS1_low PORTB &= ~(1<<PB0)
#define DS2_low PORTB &= ~(1<<PB1)

int main(void)
{
	
	DDRB &= ~(1<<DDB7);
	DDRB |= (1<<DDB0 | 1<<DDB1 | 1<<DDB7);
	DDRC |= (1<<DDC0 | 1<<DDC1 | 1<<DDC2 | 1<<DDC3 | 1<<DDC4 | 1<<DDC5);
	
	DS1_high;
	DS2_low;
    /* Replace with your application code */
    while (1) 
    {
    }
}

