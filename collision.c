#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"



// ** RULES FOR COLLISION **
// ** ANGLE VS SPEED? **


void paddle1_collision()
{
  
// ** PADDLE MOVING UPWARDS **
// If the ball is coming from an upward angle ball angle = * 2.
// If the ball is coming from a downward angle ball angle = / 2.
// If the ball is coming from a 0 degree angle = nudge ball.
  
  if(paddle1_up == 1)
  {
	if(ball_speed_y < 0)
    {
      ball_speed_y = ball_speed_y * 2; 
    }
    else if(ball_speed_y > 0)
    {
      ball_speed_y = ball_speed_y / 2;
    }
    else
    {
      ball_speed_y = -1;
    }  
  }

    
  
// ** PADDLE MOVING DOWNWARDS **
// If ball is coming from an upward angle ball angle = * 2.
// If ball is coming from a downward angle ball angle = / 2.
// If ball is coming from a 0 degree angle = nudge ball.
  
  if(paddle1_down == 1)
  {
	if(ball_speed_y < 0)
    {
      ball_speed_y = ball_speed_y / 2;
    }
    else if (ball_speed_y > 0)
    {
      ball_speed_y = ball_speed_y * 2;
    }
    else
    {
      ball_speed_y = 1;
    } 
  }	
 }


void paddle2_collision()
{
 if(paddle2_up == 1)
 {
    if(ball_speed_y < 0) {
      ball_speed_y = ball_speed_y * 2;
    }
    else if(ball_speed_y > 0) {
      ball_speed_y = ball_speed_y / 2;
    }
    else {
      ball_speed_y = -1;
    }
 }
 
  if (paddle2_down == 1)
  {
    if(ball_speed_y < 0)
    {
      ball_speed_y = ball_speed_y / 2;
    }
    else if(ball_speed_y > 0)
    {
      ball_speed_y = ball_speed_y * 2;
    }
    else
    {
      ball_speed_y = 1;
    }
  }
}

// Function to detect collision between ball and paddle1.
void ball_collision()
{
// X coordinate satisfied.
  if(ball_x == paddle_width)
  {
    // Y coordinate satisfied.
    if (((ball_y + ball_shape) > paddle1_y) && (ball_y - ball_shape) < (paddle1_y + paddle_height))
    {
      // Both Y & X satisfied = hit. Change direction of ball.
      ball_speed_x = -(ball_speed_x);
      // Run logic for paddle collision.
      paddle1_collision();
    }
  }
  else if(ball_x < -21)
  {
  // ** MISSING FUCNTION ** 
  reset();
  }
  
  // Function to detect collision between ball and paddle2.
  if (ball_x == (128 - paddle_width - 4))
  {
    if (((ball_y + ball_shape) > paddle2_y) && (ball_y - ball_shape) < (paddle2_y + paddle_height))
    {
        ball_speed_x = -(ball_speed_x);
        paddle2_collision();
    }
  }
  else if (ball_x > 138)
  {
    // ** MISSING FUNCTION **
    reset();
  }
 }
 
 
 
