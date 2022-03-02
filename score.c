#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"


int score_player1 = 0;
int score_player2 = 0;

// updates score and displays text for points and win
void score (int paddle)
{
  if(paddle == 1)
  {
    score_player1 += 1;
    if(score_player1 == 3)
    {
      display_string(0,"Player one WINS!");
      display_update();
      delay(2000);
      quit();
    }
    else
    {
      display_string(0,"Player one score!");
      display_update();
      delay(2000);
      reset();
    }
  }
  else if (paddle == 2)
  {
    score_player2 += 1;
    if (score_player2 == 3)
    {
      display_string(0, "Player two WINS!");
      display_update();
      delay(2000);
      quit();
    }
    display_string(0, "Player two score!");
    display_update();
    delay(2000);
    reset();
  }
}

  
void reset()
{
  // Resets position & values of paddles + ball.
  // also inverts speed of ball in x direction so a new player hits the ball first.
  paddle1_x = 0;
  paddle1_y = 32/2;  
  paddle2_x = 128 - 4;
  paddle2_y = 32 /2;
  ball_y = 32/2;
  ball_x = 128/2;
  
  ball_speed_x = (ball_speed_x * -1);
  ball_speed_y = 0;
  
  display_clear();
  set_displayArray(paddle1_x, paddle1_y, paddle_width, paddle_height);
  set_displayArray(paddle2_x, paddle2_y, paddle_width, paddle_height);
  set_displayArray(ball_x, ball_y, ball_shape, ball_shape);
  castToScreen();
  display_image(0, display_pixels);
  delay(1000);
}
