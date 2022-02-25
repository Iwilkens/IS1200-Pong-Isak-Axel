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

/* Interrupt Service Routine */
void user_isr( void )
{
	return;
}

/* Lab-specific initialization goes here */
void labinit( void )
{
	TRISD &= 0x0fe0;		// sätter VOLATILE pointer TRISDs värde för bitar 5-11 till 1
	TRISF &= 0x2;			// samma för TRISF (knapp1)
	return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
	menu();
}
