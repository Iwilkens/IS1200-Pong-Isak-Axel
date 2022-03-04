#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"

// variable to track which menu option that is currently active
int menu_chooser = 0;

// variable for credits 
int credits_active = 0;

void menu()
{
  if(menu_chooser == 0)
  {
	  display_string(0, "->Start Game");
	  display_string(1, "  Credits");
	   if( getbtns() & 0x1)
	  {
		game_active = 1;
		string_clear();
	  }
  }	  
  else if(menu_chooser == 1)
  {
	  display_string(0, "  Start Game");
	  display_string(1, "->Credits");
	     if( getbtns() & 0x1)
	  {
		credits_active = 1;
		string_clear();
	  }
  }	  	  
  
  if ((getbtns() & 0x2) && (menu_chooser < 1))
	  menu_chooser++;
  else if ((getbtns() & 0x4) && (menu_chooser > 0))
	  menu_chooser--;
  
  
  display_update();
}

void creditsMenu()
{
	delay(150);
	display_string(0, "Game made by");
	display_string(1, "@Isak Wilkens");
	display_string(2, "@Axel M. L.");
	display_string(3, "Press2 to return");
	if(getbtns() & 0x2)
	{
		credits_active = 0;
		string_clear();
	}
	display_update();
}
