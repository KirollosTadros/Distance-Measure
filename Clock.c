#include "Clock.h"
#include "GPIO.h"
#include <stdint.h>
 void Clock()
 {
	 SYSCTL_RCC2|=0x80000000;
	SYSCTL_RCC2|=0x00000800;
	SYSCTL_RCC1=(SYSCTL_RCC1 & ~0x000007C0)+0x00000540;
	SYSCTL_RCC2 &= ~0x00000070;
	SYSCTL_RCC2 &= ~0x00002000;
	SYSCTL_RCC2 |= 0x40000000;
	SYSCTL_RCC2 =(SYSCTL_RCC2&~ 0x1FC00000)+(4<<22);
	//while((SYSCTL_RIS&0x00000040)==0){};
	SYSCTL_RCC2 &= ~0x00000800;
 }

 void Init_Timer ()
 {
	 SYSCTL_RCGC_TIMER |= 0x01;
	 uint8_t delay=0;
	 Timer_CTL &= ~ 0x00000001;
	 Timer_CFG = 0x00000000;
	 Timer_TAMR =0x00000002;
	
	Timer_AILR =0x04C4B400;
	 Timer_CTL |= 0x00000001;

 }

void delay_MS(uint32_t delay)
{

 
	 Timer_TAMR |=0x00000010;
	 Timer_AILR = delay*80000;
	
while((Timer_RIS&0x00000001)!=1){}
Timer_ICR|=(1<<0);
//Timer_AILR = delay*80000;
}

void delay_10us(uint32_t delay)
{

 
	 Timer_TAMR |=0x00000010;
	 Timer_AILR = delay*800;
	
while((Timer_RIS&0x00000001)!=1){}
Timer_ICR|=(1<<0);
//Timer_AILR = delay*80000;
}

void down_count()
{
	ClearBit(Timer_TAMR,4);
	Timer_AILR =0x04C4B400;

	while((Timer_RIS&0x00000001)!=1){}
	Timer_ICR|=(1<<0);
}

void one()
{
	ClearBit(Timer_TAMR,4);
	Timer_AILR =80;

	while((Timer_RIS&0x00000001)!=1){}
	Timer_ICR|=(1<<0);
}
/*
uint32_t pin_time(uint32_t pin)
{
	uint32_t count=0;
	while(DigitalRead(pin))
	{
		delay_10us(1);
		count++	;	
	}
	return count/10;
}
*/
