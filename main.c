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
    PinMode(trigPin,OUTPUT);
    PinMode (echoPin,INPUT);

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
      duration=pulse_duration(echoPin);
     delay_ms(80);
     PortWrite(PortE,5);
        /*
while(HIGH)
{
        while(DigitalRead(echoPin))
        {
            delay_us(60);
            duration+=60000;
        }
}
*/

     distance = duration/58;
        //distance=150;
        PortWrite(PortE,duration/100);//portE hundreds
        PortWrite(PortD,(duration%100)/10);//portD tens
        PortWrite(PortB,(duration%10));//portB units
delay_ms(60);



    }
}
