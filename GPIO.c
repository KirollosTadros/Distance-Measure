#include "GPIO.h"
#include "uint.h"
#include "bits.h"
#include "registers.h"
#include <stdbool.h>

/*
Port Inilsization Function
*/

void Init (uint32_t Port){
	switch (Port)
	{
		case PortA : SetBit(RCGCGPIO,0); break;	
		case PortB : SetBit(RCGCGPIO,1); break;
		case PortC : SetBit(RCGCGPIO,2); break;
		case PortD : SetBit(RCGCGPIO,3); break;
		case PortE : SetBit(RCGCGPIO,4); break;
		case PortF : SetBit(RCGCGPIO,5); break;
	}

	Unlock(Port);
    GPIOCR(Port);
    AMSEL(Port);
    FCTL(Port);
    AFSEL(Port);
	DIGITAL(Port);

}

/*
Port Direction With Port argument and 8 bit fo the direction of all pins
*/

void Port_Dir(uint32_t Port, uint8_t Dir ){
	Init(Port);
	Func(Port,DIR)=Dir;
}
/*
Pin Direction 
*/

void Pin_Dir (uint32_t Port, uint8_t Pin,bool Dir ){

	Init(Port);

	if(Dir)
		Output (Port,Pin);
	else
		Input (Port,Pin);
}
/*
Write in the Whole port with 8 bits
*/
void PortWrite (uint32_t Port, uint8_t Write ){
	Func(Port,DATA)=Write;
}
/*
Pin Write
*/
void PinWrite (uint32_t Port, uint8_t Pin, bool Write){
	if(Write)
		Set(Port,Pin);
	else
		Clear(Port,Pin);
}

/*
Reads From Specifict pin
*/
bool PinRead (uint32_t Port, uint8_t Pin ){
	return Get(Port,Pin);
}
/*
Reads The Port 8 Bits
*/
uint8_t PortRead (uint32_t Port){
	return Func(Port,DATA);
}

/*
Like Ardiuno
*/

void DigitalWrite(uint8_t Pin,bool Write){

	switch(Pin/10)
	{
	case 0: if(Write) Set(PortA,Pin%10); else Clear(PortA,Pin%10); break;
	case 1: if(Write) Set(PortB,Pin%10); else Clear(PortB,Pin%10); break;	
	case 2: if(Write) Set(PortC,Pin%10); else Clear(PortC,Pin%10); break;
	case 3: if(Write) Set(PortD,Pin%10); else Clear(PortD,Pin%10); break;
	case 4: if(Write) Set(PortE,Pin%10); else Clear (PortE,Pin%10); break;
	case 5: if(Write) Set(PortF,Pin%10); else Clear(PortF,Pin%10); break;
	}
}
/*
Like Ardiuno
*/
void PinMode(uint8_t Pin,bool Dir)
{
	switch(Pin/10)
	{
   	  case 0: Init(PortA); if(!Dir) Input(PortA,Pin%10); else Output(PortA,Pin%10); break;
  	  case 1: Init(PortB); if(!Dir) Input(PortB,Pin%10); else Output(PortB,Pin%10); break;
  	  case 2: Init(PortC); if(!Dir) Input(PortC,Pin%10); else Output(PortC,Pin%10); break;
  	  case 3: Init(PortD); if(!Dir) Input(PortD,Pin%10); else Output(PortD,Pin%10); break;
	  case 4: Init(PortE); if(!Dir) Input(PortE,Pin%10); else  Output(PortE,Pin%10); break;
	  case 5: Init(PortF); if(!Dir) Input(PortF,Pin%10); else Output(PortF,Pin%10); break;
	}
}
/*
Like Ardiuno
*/
bool DigitalRead(uint8_t Pin){
	switch(Pin/10)
	{
	case 0: return Get(PortA, Pin%10); break;
	case 1: return Get(PortB, Pin%10); break;
	case 2: return Get(PortC, Pin%10); break;
	case 3: return Get(PortD, Pin%10); break;
	case 4: return Get(PortE, Pin%10); break;
	case 5: return Get(PortF, Pin%10); break;
	}
}
