#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"

int game_active = 0;

//game function, runs player motion, ball motion, ball collision and draw paddles and ball
void multiplayer(buttons)
{
	multiplayer_motion(buttons);
	ball_motion();
	ball_collision();
	display_clear();
	
	set_displayArray(paddle1_x, paddle1_y, paddle_width, paddle_height);
	set_displayArray(paddle2_x, paddle2_y, paddle_width, paddle_height);
	set_displayArray(ball_x, ball_y, ball_shape, ball_shape);
	castToScreen();
	display_image(0, display_pixels);
}

// reset score variables and return to the main menu
void quit()
{
	game_active = 0;
	score_player1 = 0;
	score_player2 = 0;
	display_clear();
	castToScreen();
	display_image(0, display_pixels);
	
}
