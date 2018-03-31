#include "uint.h"
#include "bits.h"
#include "registers.h"
#include "GPIO.h"
#include "timer.h"

#define trigPin PA3
#define echoPin PA2



void main(void)
{
    //Setting Pin Mode & initiating port
    //PinMode (PF0,INPUT);
    PinMode (PF1,OUTPUT);
    //PinMode (PF2,OUTPUT);
    //PinMode (PF3,OUTPUT);
    PinMode (PA3, OUTPUT);
    PinMode (PA2, INPUT);
    PinMode (PF4,OUTPUT);
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

    //for pullup resisitors
   // Func(PortF,PUR)=0x11;

    //setting the 2 buttons to High
   // DigitalWrite(PF 0,HIGH);
    //DigitalWrite(PF 4,HIGH);
   // uint8_t i=0;

    systick_init();
    while(1){
        uint32_t  duration=0, distance;
        DigitalWrite(trigPin, LOW);
        delay_us(2);
        DigitalWrite(trigPin, HIGH);
        delay_us(10);
        DigitalWrite(trigPin, LOW);
        while(!DigitalRead(echoPin)){delay_ms(60);PortWrite(PortE,1);}//test
       // if(DigitalRead(echoPin))//test
            PortWrite(PortE,2);//test
        delay_ms(1000);//test
        /*while(DigitalRead(echoPin))
        {
            delay_us(60);
            duration+=60000;
        }

        distance = (duration/2) / 29.1;

        PortWrite(PortE,distance/100);//portE hundreds
        PortWrite(PortD,(distance%100)/10);//portD tens
        PortWrite(PortB,(distance%10));//portB units*/


    }

}
