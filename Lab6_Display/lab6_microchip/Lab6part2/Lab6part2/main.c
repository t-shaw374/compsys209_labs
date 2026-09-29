/*
 * Lab6part2.c
 *
 * Created: 29/09/2026 12:33:41 pm
 * Author : thoma
 */ 

#define F_CPU 2000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include "display.h"

static const uint8_t digits[10] = {
	0x3F, // 0
	0x06, // 1
	0x5B, // 2
	0x4F, // 3
	0x66, // 4
	0x6D, // 5
	0x7D, // 6
	0x07, // 7
	0x7F, // 8
	0x6F  // 9
};

#define SH_DS_pin 4
#define SH_CP_pin 3
#define SH_ST_pin 5
#define DS1_pin 4
#define DS2_pin 5
#define DS3_pin 6
#define DS4_pin 7

int main(void)
{
	display_init();
	PORTD |= (1<<DS1_pin) | (1<<DS2_pin) | (1<<DS3_pin);
	PORTD &= ~(1<<DS4_pin);
	
	send_next_character_to_display(digits[7]);
	
	
    /* Replace with your application code */
    while (1) 
    {
    }
}

