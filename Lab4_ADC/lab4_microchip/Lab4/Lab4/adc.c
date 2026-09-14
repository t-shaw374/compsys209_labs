/*
 * adc.c
 *
 * Created: 15/09/2026 12:44:32 am
 *  Author: thoma
 */ 

#include "common.h"
#include "adc.h"
#include <avr/io.h>

void adc_init() {
	//3.1) set 0001 ADC1
	//ADMUX |= (1 << MUX0);
	//ADMUX &= ~((1 << MUX3) | (1 << MUX2) | (1 << MUX1));
	
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN)|(1<<ADPS2);
}

uint16_t adc_read(uint8_t channel) {
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F); // keep 4MSB, clear 4LSB of ADMUX, then or the new channel over top of 4LSB
	ADCSRA |= (1 << ADSC); // start conversion
	while (ADCSRA & (1 << ADSC)) {}; // wait until completed
	return ADC; // high and low
}

uint16_t adc_convert_mV(uint16_t adc_value) {
	return (uint32_t)adc_value * 5000 / 1024; // 32 to avoid overflow when multiply by 5000
}