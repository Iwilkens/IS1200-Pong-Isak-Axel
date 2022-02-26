#include <stdint.h>
#include <pic32mx.h>
// mipslab.h headerfil, declares functions 
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>


// Paddle size / speed
float paddle_height = 8;
float paddle_width = 3;
float paddle_speed = 1;

// Paddle #1 intial positioning
float paddle1_x = 0;
float paddle1_y = 32 / 2; // Center paddle in middle of screen.
// Paddle #1 movement variables
float paddle1_up = 0;
float paddle1_down = 0;

// Paddle #2 intial positioning
float paddle2_x = 128 - 4; // total length minus width of paddle. 1 pixel to spare.
float paddle2_y = 32 / 2;
// Paddle #2 movement variables
float paddle2_up = 0;
float paddle2_down = 0;

// Ball variables
float ball_size = 3;
// Ball initial speed
float ball_speed_x = 1;
float ball_speed_y = 0;

// Ball initial positioning
int ball_x = 128 / 2;
int ball_y = 32 / 2;

// Värdet för btns hämtas från getbtns.
// ** ??? ***
int count = 0;

void player1_motion (buttons)
{
  // reset values.
  paddle1_down = 0;
  paddle1_up = 0;
  
  
  
  
  
}




