#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h" 

int getsw(void)
{
	return (PORTD >> 8) & 0x000f;	// (from header file) Read input 8-11 (Slide switches) För att sedan returnera detta. 
}

int getbtns(void)
{
	// Binary OR Operator copies a bit if it exists in either operand.
	// **OSÄKER PÅ PARENTERSERNA**
    return ((((PORTD >> 5) & 0x0007) << 1) | ((PORTF >> 1) & 0x1));
	// (from header file) Read input 5-7 (push buttons. För att sedan returnera detta. 
}
