#include <stdint.h>
#define Register_Map		0x400FE000
#define RIS					0x050
#define RCC1				0x060
#define	RCC2				0x070
#define RCGC2				0x108

#define	RCGC_TIMER			0x604
#define Func(Base,Offset) 	(*((uint32_t*) (Base|Offset)))
#define SYSCTL_RIS			Func(Register_Map,RIS)
#define SYSCTL_RCC1			Func(Register_Map,RCC1)
#define SYSCTL_RCC2			Func(Register_Map,RCC2)
#define SYSCTL_RCGC2		Func(Register_Map,RCGC2)
//#define SYSCTL_RCGC2_R		Func(Register_Map,RCGC2_R)
#define SYSCTL_RCGC_TIMER	Func(Register_Map,RCGC_TIMER)


/*
	TIMER
	
*/

#define Timer		0x40030000
#define TCTL			0x00C
#define CFG			0x000
#define TAMR		0x004
#define	AILR		0x028
#define IMR			0x018
#define	TRIS			0x01C
#define ICR			0x024

#define Timer_CTL Func(Timer,TCTL)
#define Timer_CFG Func(Timer,CFG)
#define Timer_TAMR Func(Timer,TAMR)
#define Timer_AILR Func(Timer,AILR)
#define Timer_IMR Func(Timer,IMR)
#define Timer_RIS Func(Timer,TRIS)
#define Timer_ICR Func(Timer,ICR)
#define Timer_Value Func(Timer,0x050)

