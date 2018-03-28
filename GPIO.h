#include "uint.h"
#include "bits.h"
#include "registers.h"
#include <stdbool.h>
void Init(uint32_t Port);
void Port_Dir (uint32_t Port, uint8_t Dir);
void Pin_Dir (uint32_t Port, uint8_t Pin,bool Dir );
void PortWrite (uint32_t Port, uint8_t Write );
void PinWrite (uint32_t Port, uint8_t Pin, bool Write);
bool PinRead (uint32_t Port, uint8_t Pin );
uint8_t PortRead (uint32_t Port);
void PinMode(uint8_t Pin,bool Dir);
void DigitalWrite(uint8_t Pin,bool Write);
bool DigitalRead (uint8_t Pin);

