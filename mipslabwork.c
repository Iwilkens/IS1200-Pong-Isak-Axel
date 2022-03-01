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
#include "pong.h"

int timeoutcount = 0;



/* Lab-specific initialization goes here */
void labinit( void )
{

	TRISD &= 0x0fe0;		// sätter VOLATILE pointer TRISDs värde för bitar 5-11 till 1
	TRISF &= 0x2;			// samma för TRISF (knapp1)
	
	// kod för timer 2 (clock source)
	T2CON = 0x0;     // stop timer and clear control register
	T2CONSET = 0x70; // sätter prescaling till 1:256 blir 0111 0000, vi sätter alltså TCKPS bitarna till den sista varianten
	TMR2 = 0x0;      // clear timer register
	PR2 = (80000000/256); // Load period register, vi delar 80 M till största prescaling
	// och får då 312500 beräningar per sekund. Vi måste ha 1:256 prescaling för att det ska få plats på en 16-bitars timer (2^16)
	// när vi sedan delar på 10 för att få 100 ms
	
	T2CONSET = 0x8000;  // starts the timr genom att sätta T2COn till ON
	
	IPCSET(2) = 0x1f;		// Set priority level to 7, in Timer manual Timer belongs to that group
						    // IPC = interrupt priority protocol
							// 0x1F 0001 1111 bits 4:2 Prio, T2IP (timer2 interrupt priority bits)
							// Bit 0:1 subprio 3 enligt timer manualen 14.6  T2IS (timer2 interrupt subpriority bits
							// vi skriver annorlunda från manual pga headerfil
							// Family data sheet sidan 53. IPC så har T2IP 2:0 (3 bitar) som är på
							
						
	
	IPCSET(4) = 0x1f << 24;  // Sätter priority protocol syns på sidan 53. Samma här med högsta prio 7 och subprio 3
	
	IECSET(0) = (1<<8);      // enable external interrupt 2 (INT2), PIC32 Family data sheet sidan 53.
	
	
	enable_interrupt();		// kallar på funktionen från labwork.S för att enabla interrupts globally
	return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
			int buttons = getbtns();
			int switches = getsw();
			if(game_active)
				multiplayer(buttons);	
			if(credits_active)
				creditsMenu();
}


/* Interrupt Service Routine */
void user_isr( void )
{
	
	if (IFS(0) & (1 << 19))  //Kollar flaggan på bit 19 enligt PiC data sheet s.52, flaggan för external interrupt 4
	{
		quit();
		IFSCLR(0) = (1 << 19);
    }
	if (IFS(0) & 0x0100)
	{
		timeoutcount++;
		if (timeoutcount == 1)
		{
			if(!game_active && !credits_active)
				menu();
			timeoutcount = 0;
		}
		IFSCLR(0) = 0x0100;
	}
}
