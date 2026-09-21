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


ISR(TIMER0_COMPA_vect) {
	static uint8_t count = 0;
	count++;
	if (count >= 10) {
		count = 0;
		toggle_led();
	}
	
}



void timer_init(uint8_t time) {
	TCCR0A = (1<<WGM01);
	TCCR0B = (1<<CS02);
	OCR0A = time;
	TIMSK0 |= (1<<OCIE0A);
}

//uint8_t timer0_check_Clear_compare() {
	//if (TIFR0 & (1<<OCF0A)) {
		//TIFR0 |= (1<<OCF0A);
		//return 1;
	//}
	//return 0;
//}