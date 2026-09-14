/*
 * adc.h
 *
 * Created: 15/09/2026 12:44:44 am
 *  Author: thoma
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>

void adc_init();
uint16_t adc_read(uint8_t channel);
uint16_t adc_convert_mV(uint16_t adc_value);




#endif /* ADC_H_ */