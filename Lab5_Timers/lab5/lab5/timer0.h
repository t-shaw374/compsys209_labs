/*
 * timer.h
 *
 * Created: 21/09/2026 3:14:19 pm
 *  Author: thoma
 */ 

#include <stdint.h>


#ifndef TIMER_H_
#define TIMER_H_
void int0_setup();
void timer_init(uint8_t time);

extern volatile uint16_t total_ticks;
extern volatile uint8_t result_ready;
//uint8_t timer0_check_Clear_compare();



#endif /* TIMER_H_ */