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
float paddle1_y = 32 / 2 -2; // Center paddle in middle of screen.
// Paddle #1 movement variables
float paddle1_up = 0;
float paddle1_down = 0;

// Paddle #2 intial positioning
float paddle2_x = 128 - 4; // total length minus width of paddle. 1 pixel to spare.
float paddle2_y = 32 / 2 - 2;
// Paddle #2 movement variables
float paddle2_up = 0;
float paddle2_down = 0;

// Ball variables
float ball_shape = 3;
// Ball initial speed
float ball_speed_x = 1;
float ball_speed_y = 0;

// Ball initial positioning
int ball_x = 128 / 2;
int ball_y = 32 / 2;

// Värdet för btns hämtas från getbtns.
// ** ??? ***
int count = 0;



/*

// Function for singleplayer motion.
// (player_movement_one)
void singleplayer_motion (buttons)
{
  // reset values.
  paddle1_down = 0;
  paddle1_up = 0;
  
  // **BYT DESSA KNAPPAR?
  // **ÄR Paranteserna korrekta?**
  // **Mindre Y-värde = Paddle rör sig uppåt, varför inte tvärt om?**
  // **Behövs testas att skriva tvärt om precis som i multiplayer**
  
  // If button X is pressed and paddle y position is less than screen height. 
  // IF STATEMENT TO MOVE PADDLE 1 DOWN.
  if ((buttons & 0x4) && (paddle1_y < (32 - paddle_height)))
  {
      paddle1_down = 1;
      paddle1_y += paddle_speed;
  }
  // IF STATMENT TO MOVE PADDLE 1 UP.
  if ((buttons & 0x8) && (paddle1_y > 0))
  {
      paddle1_up = 1;
      paddle1_y -= paddle_speed;
   }
}

*/
      
  // Function for multiplayer movement.
  // (player_movement_two)
  
void multiplayer_motion (buttons)
{    
      // reset values.
      paddle1_down = 0;
      paddle1_up = 0;
      paddle2_down = 0;
      paddle2_up = 0;
      
      if ((buttons & 0x1) && (paddle2_y < (32 - paddle_height)))
      {
          paddle2_y += paddle_speed;
          paddle2_up = 1;
      }
      if ((buttons & 0x2) && (paddle2_y > 0))
      {
        paddle2_y -= paddle_speed;
        paddle2_down = 1;
      }
      if ((buttons & 0x4) && (paddle1_y < (32 - paddle_height)))
      {
        paddle1_y += paddle_speed;
        paddle1_up = 1;
      }
      if ((buttons & 0x8) && (paddle1_y > 0))
      {
        paddle1_y -= paddle_speed;
        paddle1_down = 1;
      }
}
 
void ball_motion()
{
	ball_y += ball_speed_y; // changes in the balls position relative to speed (movement)
	ball_x += ball_speed_x;
			
    // control of speed in y directions
	if (ball_speed_y > 1.7)
		ball_speed_y = 1.7;
            
	if (ball_speed_y < -1.7)
		ball_speed_y = -1.7;

	// If statement to give ball negative speed when it collisions with oled y border.
	if (ball_y < 1 || ball_y > (31 - ball_shape))
	{
		ball_speed_y = -(ball_speed_y);
	}
            
	// ** Tror detta if statement är gjort för att bollen inte rörde sig om dem ville **
	
    // åker långsamt nära kanten hotfix?
	if ((ball_speed_y < 0.3) && (ball_y <= 10))
	{
		count++;
		if(count >= 10)
		{
			ball_speed_y = 1;
			count = 0;
		}
		else
		{
			count = 0;
		}
    }   
}


/*     
void computer_motion(void)
{
	// sets paddle 2 values (which are used by AI) to 0.
	paddle2_up = 0;
    paddle2_down = 0;
    // ** TOG BORT AI DIFFICULTY **, får se om det funkar utan.
    // ** OSÄKER PÅ SPEED I DENNA FIL, har den med difficulty att göra? **
    if ((ball_y < paddle2_y) && (paddle2_y > 0))
    {
		paddle2_y -= paddle_speed;
		paddle_up = 1;
    }
            
    if ((ball_y > paddle2_y) && (paddle2_y < (32-paddle_height)))
    {
        paddle_y += paddle_speed;
        paddle_down = 1;
    } 
}
  
  


*/
