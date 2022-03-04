#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"

// Paddle size / speed
float paddle_height = 8;
float paddle_width = 3;
float paddle_speed = 1;

// Paddle #1 intial positioning
float paddle1_x = 0;
float paddle1_y = 32 / 2 - 2;
// Paddle #1 movement variables
float paddle1_up = 0;
float paddle1_down = 0;


// Paddle #2 intial positioning
float paddle2_x = 128 - 4; // total length minus width of paddle. 1 pixel to spare.
float paddle2_y = 32 / 2 - 2;
// Paddle #2 movement variables
float paddle2_up = 0;
float paddle2_down = 0;


//Ball specific variables
float ball_shape = 2;
float ball_speed_x = 1;
float ball_speed_y = 0;

int ball_x = 128 / 2 - 5;
int ball_y = 32 / 2;
int count = 0;

// Function for multiplayer movement.
// (player_movement_two)
void multiplayer_motion(buttons) 
{
  // reset values.
  paddle2_up = 0;
  paddle2_down = 0;
  paddle1_up = 0;
  paddle1_down = 0;

  if ((buttons & 0x1) && (paddle2_y < (32 - paddle_height))) {
    paddle2_y += paddle_speed;
    paddle2_up = 1;
  }
  if ((buttons & 0x2) && (paddle2_y > 0)) {
    paddle2_y -= paddle_speed;
    paddle2_down = 1;
  }
  if ((buttons & 0x4) && (paddle1_y < (32 - paddle_height))) {
    paddle1_y += paddle_speed;
    paddle1_up = 1;
  }
  if ((buttons & 0x8) && (paddle1_y > 0)) {
    paddle1_y -= paddle_speed;
    paddle1_down = 1;
  }
}



void ball_motion() {
  ball_x += ball_speed_x;    // changes in the balls position relative to speed (movement)
  ball_y += ball_speed_y;
  
 // control of speed in y direction.
 // ensure that ball speed have a limit.
  if(ball_speed_y > 1.7){
    ball_speed_y = 1.7;
  }
  if(ball_speed_y < -1.7){
    ball_speed_y = -1.7;
  }

  // If statement to send ball in opposite y-direction when it collisions with screen border.
  if (ball_y < 0 || ball_y > (31 - ball_shape)) {
    ball_speed_y = (ball_speed_y * -1);
  }
  
 
   // if the ball gets stuck in y direction, count up and then give it y-speed
   if((ball_speed_y < 0.3) && (ball_y <= 10)) {
     count++;
     if(count >= 10){
       ball_speed_y = 1;
       count = 0;
     }
   }
   else{
     count = 0;
   }

   
}
