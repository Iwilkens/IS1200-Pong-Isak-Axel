#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"
#include <stdio.h>
#include <stdlib.h>
#include "pong.h"

int game_active = 0;
int game_mode = 0;
int player = 0;
int lives = 0;


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

void quit()
{
	game_active = 0;
	player1_score = 0;
	player2_score = 0;
	// resetta poäng?
	display_clear();
	castToScreen();
	display_image(0, display_pixels);
	
}
