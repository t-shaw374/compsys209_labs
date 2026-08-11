/*
 * uart0.c
 *
 * Created: 11/08/2026 12:38:10 pm
 *  Author: thoma
 */ 

#include <avr/io.h>
#include <stdint.h>
#include "uart0.h"

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

void find_primes(uint16_t found_primes[62]) {
	uint8_t position = 0;
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
}