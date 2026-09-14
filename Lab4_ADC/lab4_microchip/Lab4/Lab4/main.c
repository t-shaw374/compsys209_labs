/*
 * Lab4.c
 *
 * Created: 15/09/2026 12:43:03 am
 * Author : thoma
 */ 



#include <avr/io.h>
#include "adc.h"
#include "common.h"
#include <util/delay.h>

int main(void)
{
	adc_init();
    uint16_t adc_value;
	uint16_t value_mv;
    while (1) 
    {
		adc_value = adc_read(2); // read ADC2
		value_mv = adc_convert_mV(adc_value);
		_delay_ms(1);
    }
}

