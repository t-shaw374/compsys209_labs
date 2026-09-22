/*
 * timer.c
 *
 * Created: 21/09/2026 3:13:23 pm
 *  Author: thoma
 */ 


#include "common.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer0.h"
#include "led.h"

volatile uint8_t edge_state = 0;
volatile uint32_t overflow_count = 0;
volatile uint16_t total_ticks = 0;
volatile uint8_t result_ready = 0;

ISR(TIMER0_OVF_vect) {
	overflow_count++;
}

ISR(TIMER0_COMPA_vect) {
	static uint8_t count = 0;
	count++;
	if (count >= 10) {
		count = 0;
		toggle_led();
	}
	
}

ISR(INT0_vect) {
	if (!edge_state) {
		TCNT0 = 0;
		overflow_count = 0;
		TCCR0B |= (1<<CS00);
		edge_state = 1;
	} else {
		TCCR0B = 0;
		total_ticks = (overflow_count*256)+TCNT0;
		result_ready = 1;
		edge_state = 0;
	}
}

void int0_setup() {
	EICRA |= (1 << ISC00 | 1<<ISC01);
	EIMSK |= (1<<INT0);
}

void timer_init(uint8_t time) {
	TCCR0A = 0; //(1<<WGM01);
	TCCR0B = 0;
	//OCR0A = time;
	TIMSK0 |= (1 << TOIE0); //(1<<OCIE0A);
}

//uint8_t timer0_check_Clear_compare() {
	//if (TIFR0 & (1<<OCF0A)) {
		//TIFR0 |= (1<<OCF0A);
		//return 1;
	//}
	//return 0;
//}