/*
 * Lab4.c
 *
 * Created: 15/09/2026 12:43:03 am
 * Author : thoma
 */ 



#include <avr/io.h>
#include "adc.h"
#include "uart.h"
#include "common.h"
#include <util/delay.h>

#define BAUD 9600
#define UBRR_VAL ((F_CPU / ((uint32_t)16 * BAUD)) - 1)
#define ADC_DELAY 0.1 //ms
#define NUM_SAMPLES 100


int main(void)
{
	usart_init(UBRR_VAL);
	adc_init();
    //uint16_t adc_value;
	//uint16_t value_mv;
	uint16_t adc0_values[NUM_SAMPLES];
	uint16_t adc1_values[NUM_SAMPLES];
	
	for (uint8_t i = 0; i<NUM_SAMPLES; i++) {
		adc0_values[i] = adc_convert_mV(adc_read(0));
		adc1_values[i] = adc_convert_mV(adc_read(1));
		
	}
		
	for (uint8_t i = 0; i<NUM_SAMPLES;i++) {
		send_mV_value(adc0_values[i]);
		usart_transmit(' ');
		send_mV_value(adc1_values[i]);
		usart_transmit('\r');
		usart_transmit('\n');
	}
	
    while (1) 
    {
		//adc_value = adc_read(2); // read ADC2
		//value_mv = adc_convert_mV(adc_value);
		//send_mV_value(value_mv);
		//_delay_ms(1000);
    }
}

