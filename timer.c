#include <stdint.h>
#include "GPIO.c"

#define SYSTICK     ( *((volatile uint32_t*) 0xE000E000) )
#define STCTRL      ( *((volatile uint32_t*) 0xE000E010) )
#define STRELOAD    ( *((volatile uint32_t*) 0xE000E014) )
#define STCURRENT   ( *((volatile uint32_t*) 0xE000E018) )

void systick_init() {
    STRELOAD = 0x0;
    STCURRENT = 0x0;
    //diable timer
    STCTRL &= ~0x1;     //ENABLE
    //disable interrupt
    STCTRL &= ~0x2;     //INTEN
    //use system clock
    STCTRL |=  0x4;     //CLK_SRC
}

void delay_ms(uint32_t count) {
    /*
        assumes 16 MHz clock,
        maximum count = 1,048 milliseconds
    */
    STCTRL &= ~0x1;             //disable timer
    STCURRENT = 0x0;
    STRELOAD = 16000 * count - 1;
    STCTRL |= 0x1;              //enable timer
    while( STCTRL & 0x10 != 1 );
    return;
}

void delay_us(uint32_t count) {
    /*
        assumes 16 MHz clock,
        maximum count = 1,048,576 microseconds
    */
    STCTRL &= ~0x1;             //disable timer
    STCURRENT = 0x0;
    STRELOAD = 16 * count - 1;
    STCTRL |= 0x1;              //enable timer
    while( STCTRL & 0x10000 != 1 );
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
    STCURRENT = 0x0;
    STRELOAD = 0x00FFFFFF;      //2^24 - 1
    STCTRL |= 0x1;              //enable timer

    //keep timer running while pin is still HIGH
    while( DigitalRead(pin) == HIGH );

    //pin went LOW, return counted time (lower 24 bits)
    return (STCURRENT & 0x00FFFFFF) / 16;
}
