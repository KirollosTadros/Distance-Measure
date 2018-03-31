#include "timer.h"
#include <stdint.h>
#include "GPIO.h"

#define STCTRL      ( *((volatile uint32_t*) 0xE000E010) )
#define STRELOAD    ( *((volatile uint32_t*) 0xE000E014) )
#define STCURRENT   ( *((volatile uint32_t*) 0xE000E018) )

void systick_init() {
    //diable timer
    STCTRL &= ~0x1;     //ENABLE
    //disable interrupt
    STCTRL &= ~0x2;     //INTEN
    //use system clock
    STCTRL |=  0x4;     //CLK_SRC
    STRELOAD = 0x0;
    STCURRENT = 0x0;
}

void delay_ms(uint32_t count) {
    /*
        assumes 16 MHz clock,
        maximum count = 1,048 milliseconds
    */
    STCTRL &= ~0x1;             //disable timer
    STRELOAD = 16000 * count - 1;
    STCURRENT = 0x0;
    STCTRL |= 0x1;              //enable timer
    while( (STCTRL & 0x10000) == 0 );
    return;
}

void delay_us(uint32_t count) {
    /*
        assumes 16 MHz clock,
        maximum count = 1,048,576 microseconds
    */
    STCTRL &= ~0x1;             //disable timer
    STRELOAD = 16 * count - 1;
    STCURRENT = 0x0;
    STCTRL |= 0x1;              //enable timer
    while( (STCTRL & 0x10000) == 0 );
    return;
}

uint32_t pulse_duration(uint8_t pin) {
    /*
        returns duration of HIGH pulse in microseconds
        - waits indefinitely for pulse to go HIGH before
        starting to measure time
        - assumes pulse duration is less than
        approximately 1048 milliseconds
        - assumes clock is 16 MHz
    */
    //wait for pin to go HIGH
    while( DigitalRead(pin) != HIGH );

    //pin went HIGH, start timer
    STCTRL &= ~0x1;             //disable timer
    STRELOAD = 0x00FFFFFF;      //max value (2^24 - 1)
    STCURRENT = 0x0;
    STCTRL |= 0x1;              //enable timer

    //keep timer running while pin is still HIGH
    while( DigitalRead(pin) == HIGH );

    //pin went LOW, return elapsed time
    //- remember: systick is a down counter, to get the elapsed
    //time, we must subtract current value from reload value
    //- divide by 16 (assuming 16 MHz clock) to get time in microseconds
    return ( (STRELOAD & 0x00FFFFFF) - (STCURRENT & 0x00FFFFFF) ) / 16;
}
