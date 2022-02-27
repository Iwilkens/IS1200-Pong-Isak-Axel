#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"

uint8_t display_array[32][128];
uint8_t	display_pixels[512];


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

// Binary set of two dimensional pixel array
void set_displayArray(int x, int y, int height, int width)
{
	int row, column;
	for (row = 0; column < 128; column++)
	{
		for( column = 0; column < 128; column++)
		{
			if(row >= y && row <= (y + height) && column >= x && column <= (x + width))
				display_array[row][column] = 1;
		}
	}
}

// cast of two dimensional array to screen
void castToScreen()
{
	int 
}
