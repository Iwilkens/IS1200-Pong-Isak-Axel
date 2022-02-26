#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>


int menu_chooser = 0;
int dogmenu_running = 0;

void menu()
{
  delay(150);      // without delay it gets updated to fast(since we dont have a timer
  
  
  if(menu_chooser == 0)
  {
	  display_string(0, "->Main Menu");
	  display_string(1, "  Singleplayer");
	  display_string(2, "  Multiplayer");
  }	  
  else if(menu_chooser == 1)
  {
	  display_string(0, "  Main Menu");
	  display_string(1, "->Singleplayer");
	  display_string(2, "  Multiplayer");
  }	  
  else if(menu_chooser == 2)
  {
	  display_string(0, "  Main Menu");
	  display_string(1, "  Singleplayer");
	  display_string(2, "->Multiplayer");
	  
	  if( getbtns() & 0x1)
		dogmenu_running = 1;
  }	  
  
  if ((getbtns() & 0x2) && (menu_chooser < 2))
	  menu_chooser++;
  else if ((getbtns() & 0x4) && (menu_chooser > 0))
	  menu_chooser--;
  display_update();
}

void dogmenu()
{
	display_image(96, icon);
	if( getbtns() & 0x1)
		dogmenu_running = 0;
}
