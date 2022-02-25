/* mipslabwork.c
   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall
   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):
   This file modified 2022-02-25 by @Isak Wilkens and @Axel Månson Lokrantz
   For copyright and licensing, see file COPYING */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

volatile int *newTRISE;		// globala pointers för TRISE
volatile int *newPORTE;		// samt PORTE



/* Interrupt Service Routine */
void user_isr( void )
{
	if (IFS(0) & 0x0100)
	{
		timeoutcount++;
		if (timeoutcount == 10)
		{
			time2string( textstring, mytime );
			display_string( 3, textstring );
			display_update();
			tick( &mytime );
			timeoutcount = 0;
		}
		IFSCLR(0) = 0x0100;
	}

}

/* Lab-specific initialization goes here */
void labinit( void )
{
	newTRISE = (volatile int *) 0xbf886100; // Ska peka på given adress för TRISE
	newPORTE = (volatile int *) 0xbf886110;  // ska peka på given adress för PORTE
	
	*newPORTE = 0x0; 						// clear PORTE
	
	*newTRISE &= 0xff00;					// set 8 LSB to 0 för att de ska räknas som output
	
	//*newPORTE += 0xff;				    // sätter värdet för PORTE till 8 för 0-7 (lamporna) Uppgift 1C bortkommenterad
	
	TRISD &= 0x0fe0;						// sätter VOLATILE pointer TRISDs värde för bitar 5-11 till 1
	
	
	// kod för timer 2 (clock source)
	T2CON = 0x0;     // stop timer and clear control register
	T2CONSET = 0x70; // sätter prescaling till 1:256 blir 0111 0000, vi sätter alltså TCKPS bitarna till den sista varianten
	TMR2 = 0x0;      // clear timer register
	PR2 = (80000000/256/10); // Load period register, vi delar 80 M till största prescaling
	// och får då 312500 beräningar per sekund. Vi måste ha 1:256 prescaling för att det ska få plats på en 16-bitars timer (2^16)
	// när vi sedan delar på 10 för att få 100 ms
	
	T2CONSET = 0x8000;  // starts the timr genom att sätta T2COn till ON
	
	IPCSET(2) = 0x1f;		// Set priority level to 7, in Timer manual Timer belongs to that group
						    // IPC = interrupt priority protocol
							// 0x1F 0001 1111 bits 4:2 Prio, T2IP (timer2 interrupt priority bits)
							// Bit 0:1 subprio 3 enligt timer manualen 14.6  T2IS (timer2 interrupt subpriority bits
							// vi skriver annorlunda från manual pga headerfil
							// Family data sheet sidan 53. IPC så har T2IP 2:0 (3 bitar) som är på
							
						
	
	IECSET(0) = (1<<8);      // enable external interrupt 2 (INT2), PIC32 Family data sheet sidan 53.
	
	
	enable_interrupt();		// kallar på funktionen från labwork.S för att enabla interrupts globally
	return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
	prime = nextprime( prime );
	display_string( 0, itoaconv( prime ) );
	display_update();
}
