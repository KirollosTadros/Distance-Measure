#include "uint.h"
#include "bits.h"
#include "registers.h"
#include "GPIO.h"
#include "GPIO.c"
void main(void)
{


    //Setting Pin Mode & initiating port

    PinMode (PF0,INPUT);
    PinMode (PF1,OUTPUT);
    PinMode (PF2,OUTPUT);
    PinMode (PF3,OUTPUT);
    PinMode (PF4,INPUT);

    //for pullup resisitors

    Func(PortF,PUR)=0x11;

    //setting the 2 buttons to High

    DigitalWrite(PF 0,HIGH);
    DigitalWrite(PF 4,HIGH);



    while(1){


       DigitalWrite(PF1,(!DigitalRead(PF0))&&DigitalRead(PF4));     //One Button pressed PF1 is on
       DigitalWrite (PF2,(!DigitalRead(PF4))&&(DigitalRead (PF0))); //Another one is pressed PF2 is on
       DigitalWrite (PF3,(!DigitalRead(PF4))&&(!DigitalRead (PF0)));    //The 2 are pressed together PF3 is on

    }

}
