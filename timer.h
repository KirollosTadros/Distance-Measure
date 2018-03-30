#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

void systick_init();
void delay_ms(uint32_t count);
void delay_us(uint32_t count);
uint32_t pulse_duration(uint8_t pin);

#endif //TIMER_H
