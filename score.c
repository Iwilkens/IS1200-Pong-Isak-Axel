#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"

/*
int score_player1 = 0;
int score_player2 = 0;

void score (player)
{
  if(player == 1)
  {
    score_player1 += 1;
    display_string("Player one: score!")
    display_update();
    delay(2000);
  }
  else if (player == 2)
  {
    score_player2 += 1;
    display_string("Player two: score!")
    display_update();
    delay(2000);
  }
}
*/
  
void reset()
{
  // Resets position & values of paddles + ball.
  paddle1_x = 0;
  paddle1_y = 32/2;  
  paddle2_x = 128 - 4;
  paddle1_y = 32/2;
  ball_y = 32/2;
  ball_x = 128/2;
  
  ball_speed_x = 1;
  ball_speed_y = 0;
  
  display_clear();
  set_displayArray(paddle1_x, paddle1_y, paddle_width, paddle_height);
  set_displayArray(paddle2_x, paddle2_y, paddle_width, paddle_height);
  set_displayArray(ball_x, ball_y, ball_shape, ball_shape);
  castToScreen();
  display_image(0, display_pixels);
}
