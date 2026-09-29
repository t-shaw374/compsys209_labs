/*
 * display.h
 *
 * Created: 29/09/2026 2:42:39 pm
 *  Author: tsha374
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <stdint.h>

void display_init(void);
void send_next_character_to_display(uint8_t pattern);



#endif /* DISPLAY_H_ */