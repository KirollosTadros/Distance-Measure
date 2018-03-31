#include <stdint.h>
#include "bits.h"
#include "registers.h"
#include "GPIO.h"
#include "timer.h"

#define trigPin PA3
#define echoPin PA2

void main(void)
{
    //Setting Pin Mode & initiating port
    PinMode (PB0,OUTPUT);
    PinMode (PB1,OUTPUT);
    PinMode (PB2,OUTPUT);
    PinMode (PB3,OUTPUT);
    PinMode (PE0,OUTPUT);
    PinMode (PE1,OUTPUT);
    PinMode (PE2,OUTPUT);
    PinMode (PE3,OUTPUT);
    PinMode (PD0,OUTPUT);
    PinMode (PD1,OUTPUT);
    PinMode (PD2,OUTPUT);
    PinMode (PD3,OUTPUT);
    PinMode (trigPin,OUTPUT);
    PinMode (echoPin,INPUT);

    systick_init();
    uint32_t duration, distance;
    DigitalWrite(trigPin, LOW);
    delay_us(1);
    while(1){
        DigitalWrite(trigPin, HIGH);
        delay_us(10);
        DigitalWrite(trigPin, LOW);
        duration = pulse_duration(echoPin);
        distance = duration / 58;
        PortWrite(PortE, distance/100);			//portE hundreds
        PortWrite(PortD, (distance%100)/10);	//portD tens
        PortWrite(PortB, (distance%10));		//portB units
        delay_ms(50);
    }
}
