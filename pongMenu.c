#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>

float menu_options = 1;

void menu()
{
  display_string(1, "PONG");
  display_string(1, "Singleplayer");
  display_string(2, "Multiplayer");
  display_string(3, "Inverse pong");
  
  display_update();
}
