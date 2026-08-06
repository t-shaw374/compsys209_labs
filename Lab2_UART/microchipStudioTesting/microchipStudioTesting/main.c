/*
 * microchipStudioTesting.c
 *
 * Created: 6/08/2026 1:29:44 pm
 * Author : thoma
 */ 

#include <avr/io.h>
#include <stdint.h>

int main(void)
{
	uint8_t position = 0;
	int found_primes[62];
	for(uint8_t i = 2; i <= 300; i++) {
		uint8_t is_prime = 1;
		for(uint8_t j = 2; j < i; j++) {
			if(i % j == 0) {
				is_prime = 0;
			}
		}
		if(is_prime) {
			found_primes[position] = i;
			position++;
		}
	}
	uint16_t debug_check = found_primes[0];  
    /* Replace with your application code */
    while (1) 
    {
    }
}

