/* Display code
written by @Isak Wilkens */


#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"

uint8_t display_array[32][128];  //Declare bitmap array size
uint8_t	display_pixels[512];	 //Declare bitmap array pixels

// Binary set of two dimensional pixel array
void set_displayArray(int x, int y, int width, int height)     // ta värden från "objekten" i spelet och rita dem, width lägger till pixlar i x led och height i y led
{
	int row, column;
	for (row = 0; row < 32; row++)							
	{
		for( column = 0; column < 128; column++)
		{
			if(row >= y && row <= (y + height) && column >= x && column <= (x + width))   // jämför data som funktuinen får in för att se vilka bitar i 2d arrayen som ska sättas till 1
			{
				display_array[row][column] = 1;
			}
		}
	}
}

// cast of two dimensional array to screen
void castToScreen()
{
	int page, column, row;
	uint8_t pixelCount = 0;
	uint8_t binaryCount = 1;
	
	for(page = 0; page < 4; page++)
	{
		for(column = 0; column < 128; column++)
		{
			pixelCount = 0;
			binaryCount = 1;
			for(row = 0; row < 8; row++)                		// går in för varje byte och skriver ut på skärmens pixlar 512 byte * 8 = 4096 pixels
			{
			    if(display_array[8 * page + row][column])
			       {
				       pixelCount |= binaryCount;				// om biten är markerad som 1 eller 0 får den bitmappen 1 eller 0 ritad
			       }
			     binaryCount <<= 1;								// förskjuter allt 1 steg och går till nästa på tur
			 }
			 display_pixels[column + page * 128] = pixelCount;  //
			   
		 }
	}		
}

// gå igenom hela array sätt allt till 0 och casta ut till pixlarna
void display_clear()
{
	int column, row, i;
	for(row = 0; row < 32; row++)
	{
		for(column = 0; column < 128; column++)
		{
			display_array[row][column] = 0;
		}
	}
	
	for(i = 0; i < 512; i++)
	{
		display_pixels[i] = 0;
	}
}


void string_clear()
{
	display_string(0, "");
	display_string(1, "");
	display_string(2, "");
	display_update();
}
