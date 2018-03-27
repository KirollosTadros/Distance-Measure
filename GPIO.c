#include "GPIO.h"
#include "uint.h"
#include "bits.h"
#include "registers.h"
#include <stdbool.h>

void Init (uint32_t Port){
	switch (Port)
	{
		case PortA : RCGCGPIO =0x01;
		case PortB : RCGCGPIO =0x02;
		case PortC : RCGCGPIO =0x04;
		case PortD : RCGCGPIO =0x08;
		case PortE : RCGCGPIO =0x10;
		case PortF : RCGCGPIO =0x20;
	}

	Unlock(Port);
    GPIOCR(Port);
    AMSEL(Port);
    FCTL(Port);
    AFSEL(Port);
	DIGITAL(Port);

}

void Port_Dir(uint32_t Port, uint8_t Dir ){

	Func(Port,DIR)=Dir;
}

void Pin_Dir (uint32_t Port, uint8_t Pin,bool Dir ){
	if(Dir)
		Output (Port,Pin);
	else
		Input (Port,Pin);
}

void PortWrite (uint32_t Port, uint8_t Write ){
	Func(Port,DATA)=Write;
}

void PinWrite (uint32_t Port, uint8_t Pin, bool Write){
	if(Write)
		Set(Port,Pin);
	else
		Clear(Port,Pin);
}

bool PinRead (uint32_t Port, uint8_t Pin ){
	return Get(Port,Pin);
}
uint8_t PortRead (uint32_t Port){
	return Func(Port,DATA);
}