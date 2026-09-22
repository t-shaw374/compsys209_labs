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
#include "uart.h"
#include <stdio.h>




#define BAUD 9600
#define UBRR_VAL ((F_CPU / ((uint32_t)16 * BAUD)) - 1)

//#include <util/delay.h>

//#define LED_ON PORTB |= (1 << PB5);
// #define LED_OFF PORTB &= ~(1 << PB5);

int main(void)
{
	DDRB = 0xFF;
	DDRC = 0x00;
	DDRD = 0x00;
	usart_init(UBRR_VAL);
	timer_init(77);
	int0_setup();
	sei();
	
	char buffer[32];
    /* Replace with your application code */
    while (1) 
    {
		if (result_ready) {
			result_ready = 0;
			uint16_t time_us = total_ticks/2;
			uint16_t freq = 1000000/time_us;
			sprintf(buffer, "%u\r\n",freq);
			uart_tx_string(buffer);
			
		}
		
		
		//if(timer0_check_Clear_compare()) {
			//toggle_led();
		//}
		
		
		//LED_ON;
		//_delay_ms(0.375);
		//LED_OFF;
		//_delay_ms(0.125);
    }
}

