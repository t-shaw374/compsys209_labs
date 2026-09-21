/*
 * led.c
 *
 * Created: 21/09/2026 3:21:22 pm
 *  Author: thoma
 */ 
#include "led.h"
#include <avr/io.h>

void toggle_led() {
	PORTB ^= (1 << PORTB5);
}