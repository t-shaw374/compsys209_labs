/*
 * microchipStudioTesting.c
 *
 * Created: 6/08/2026 1:29:44 pm
 * Author : thoma
 */ 


#define F_CPU 2000000UL

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#define BAUD 9600
#define UBRR_VAL ((F_CPU / (16UL * BAUD)) - 1)
#define SEND_DELAY 5000 //ms



void usart_init(uint16_t ubrr) {
	UCSR0B |= (1 << TXEN0 | 1 << UDRIE0);
	UCSR0C |= (1 << UCSZ01 | 1 << UCSZ00);
	UBRR0L = (uint8_t)(ubrr);
	UBRR0H = (uint8_t)(ubrr >> 8);
}

void usart_transmit(uint8_t data) {
	while (~UCSR0A & (1 << UDRE0)) {}
	UDR0 = data;
}

void send_3_digit(uint16_t num) {
	uint8_t num_chars[] = {(num / 100) % 10, (num / 10) % 10, num % 10};
	for(uint8_t i = 0; i < 3; i++) {
		usart_transmit(num_chars[i] + 48);
	}
}

void send_commaspace() {
	usart_transmit(44);
	usart_transmit(32);
}

int main(void)
{
	usart_init(UBRR_VAL);
	
	uint8_t position = 0;
	uint16_t found_primes[62];
	for(uint16_t i = 2; i <= 300; i++) {
		uint8_t is_prime = 1;
		for(uint16_t j = 2; j < i; j++) {
			if(i % j == 0) {
				is_prime = 0;
			}
		}
		if(is_prime) {
			found_primes[position] = i;
			position++;
		}
	}
	
    /* Replace with your application code */
	
	
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

