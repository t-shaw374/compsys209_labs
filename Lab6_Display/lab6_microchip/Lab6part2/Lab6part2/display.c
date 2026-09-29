/*
 * display.c
 *
 * Created: 29/09/2026 2:42:21 pm
 *  Author: tsha374
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "display.h"



static volatile uint8_t count = 0;
static volatile uint8_t digit1_displayed = 0;

#define SH_DS_pin 4
#define SH_CP_pin 3
#define SH_ST_pin 5
#define DS1_pin 4
#define DS2_pin 5
#define DS3_pin 6
#define DS4_pin 7


//static void timer0_init(void) {
	//TCCR0A = (1 << WGM01);              // CTC mode
	//TCCR0B = (1 << CS02) | (1 << CS00); // prescaler 356
	//OCR0A = 78;                         // ~10ms @ 2MHz
	//TIMSK0 = (1 << OCIE0A);             // enable compare-match interrupt
//}

void display_init(void) {
	DDRC |= (1 << SH_CP_pin | 1 << SH_DS_pin | 1 << SH_ST_pin);
	DDRD |= (1<<DS1_pin | 1<<DS2_pin | 1<<DS3_pin | 1<<DS4_pin);
	
	//initially off
	PORTC &= ~((1<<SH_CP_pin)|(1<<SH_ST_pin));
	PORTD |= (1<<DS1_pin | 1<<DS2_pin | 1<<DS3_pin | 1<<DS4_pin);
	
	
}

void send_next_character_to_display(uint8_t pattern) {
	PORTC &= ~((1<<SH_CP_pin)|(1<<SH_ST_pin));
	
	for (int8_t i = 7; i>=0; i--) {
		if (pattern & (1<<i)) {
			PORTC |= (1<<SH_DS_pin);
		} else {
			PORTC &= ~(1<<SH_DS_pin);
		}
		
		PORTC |= (1<<SH_CP_pin);
		PORTC &= ~(1<<SH_CP_pin);
	}
	PORTC |= (1<<SH_ST_pin);
	PORTC &= ~(1<<SH_ST_pin);
}
//
//void display_increment_counter(void) {
	//count++;
	//if (count > 99) {
		//count = 0;
	//}
//}
//
//static void set_segments(uint8_t num) {
	//uint8_t digit = digits[num];
	//PORTC = (PORTC & 0xC0) | (digit & 0x3F);
	//PORTB = (PORTB & 0xEF) | (((digit & 0x40) >> 2));
//}
//
//ISR(TIMER0_COMPA_vect) {
	//uint8_t tens = count / 10;
	//uint8_t ones = count % 10;
//
	//if (digit1_displayed)
	//{
		//// Showed tens last -> show ones now
		//PORTB |= (1 << PORTB0) | (1 << PORTB1); // 3. disable both
		//set_segments(ones);                // 2/4. set segments for ones
		//PORTB &= ~(1 << PORTB1);              // 5. enable Ds2
		//digit1_displayed = 0;
	//}
	//else
	//{
		//// Showed ones last -> show tens now
		//PORTB |= (1 << PORTB0) | (1 << PORTB1); // 3. disable both
		//set_segments(tens);                // 2/4. set segments for tens
		//PORTB &= ~(1 << PORTB0);              // 5. enable Ds1
		//digit1_displayed = 1;
	//}
//}
