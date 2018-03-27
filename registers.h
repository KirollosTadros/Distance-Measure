#include "uint.h"
#include "bits.h"
//Base Address

#define PortA		 0x40004000
#define PortB		 0x40005000
#define PortC		 0x40006000
#define PortD		 0x40007000
#define PortE		 0x40024000
#define PortF		 0x40025000

//Base Address of AHB

#define PortA_h		 0x40058000
#define PortB_H		 0x40059000
#define PortC_H		 0x4005A000
#define PortD_H		 0x4005B000
#define PortE_H		 0x4005C000
#define PortF_H		 0x4005D000

//PIN Offset

#define PIN0         0x00000001  
#define PIN1         0x00000002  
#define PIN2         0x00000004  
#define PIN3         0x00000008  
#define PIN4         0x00000010  
#define PIN5         0x00000020  
#define PIN6         0x00000040  
#define PIN7         0x00000080 

//Registers Offset

#define DATA		 0x3FC
#define DIR			 0x400
#define DEN			 0x51C
#define LOCK		 0x520
#define RCGC		 0x400FE608
#define CR			 0x524
#define SEL			 0x420
#define CTL			 0x52C
#define MSEL		 0x528
#define PUR			 0x510



#define Func(P,F) (*((uint32_t*) (P|F)))
#define Unlock(P) Func(P,LOCK)=0x4C4F434B
#define AFSEL(P) Func(P,SEL)=0x00000000
#define FCTL(P) Func(P,CTL)=0x00000000
#define AMSEL(P) Func(P,MSEL)=0x00000000
#define GPIOCR(P) Func(P,CR)=0xFF
#define DIGITAL(P) Func(P,DEN)=0xFF
#define Output(P,Bit) SetBit(Func(P,DIR),Bit)
#define Input(P,Bit) ClearBit(Func(P,DIR),Bit)
#define Set(P,Bit) SetBit(Func(P,DATA),Bit)
#define Clear(P,Bit) ClearBit(Func(P,DATA),Bit)
#define Get(P,Bit) GetBit(Func(P,DATA),Bit)
#define RCGCGPIO (*((uint32_t*) 0x400FE608))
