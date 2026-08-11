/*
 * microchipStudioTesting.c
 *
 * Created: 6/08/2026 1:29:44 pm
 * Author : thoma
 */ 


#define F_CPU 2000000UL

#include <util/delay.h>
#include "uart0.h"

#define BAUD 9600
#define UBRR_VAL ((F_CPU / ((uint32_t)16 * BAUD)) - 1)
#define SEND_DELAY 10000 //ms


int main(void)
{
	usart_init(UBRR_VAL);
	
	uint16_t found_primes[62];
	find_primes(found_primes);
	
    while (1) 
    {
		for(uint16_t vro = 0; vro < 62; vro++) {
			send_3_digit(found_primes[vro]);
			if (vro < 61) {
				send_commaspace();
			}
		}

		
		_delay_ms(SEND_DELAY);
		
    }
}

