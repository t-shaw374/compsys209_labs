/*
 * uart0.h
 *
 * Created: 11/08/2026 12:37:30 pm
 *  Author: thoma
 * contains all uart0 related code
 */ 

#include <stdint.h>


#ifndef UART0_H_
#define UART0_H_

void usart_init(uint16_t ubrr);
void usart_transmit(uint8_t data);
void send_3_digit(uint16_t num);
void send_commaspace();
void find_primes(uint16_t found_primes[62]);



#endif /* UART0_H_ */