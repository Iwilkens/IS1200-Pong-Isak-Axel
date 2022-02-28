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
// If the ball is coming from a 0 degree angle = nudge ball upwards.
  
  if(paddle1_up == 1)
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
  
// ** PADDLE MOVING DOWNWARDS **
// If ball is coming from an upward angle ball angle = * 2.
// If ball is coming from a downward angle ball angle = / 2.
// If ball is coming from a 0 degree angle = nudge ball downwards.
  
  if(paddle1_down == 1)
    if(ball_speed_y < 0)
    {
      ball_speed_y = ball_speed_y / 2;
    }
    else if (ball_speed_y > 0)
    {
      ball_speed_y = ball_speed_y * 2
    }
    else
    {
      ball_speed = 1;
    }
   }
  }





