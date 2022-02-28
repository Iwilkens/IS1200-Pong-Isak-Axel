/***************************
AI Pong header file
Written by @Isak Wilkens,
@Axel Lokrantz Månson
**************************/

// ** Functions **

// Menu functions
void menu();
void dogmenu();

// Screen functions
void display_clear();
void string_clear();
void castToScreen();

// Motion functions
void singleplayer_motion();
void multiplayer_motion();
void computer_motion();

// ** Global variables **

// Menu variables
extern int menu_chooser;
extern int dogmenu_running;

// Screen definitions
extern uint8_t display_array[32][128];
extern uint8_t	display_pixels[512];

// Motion variables

// Paddle
extern float paddle_height;
extern float paddle_width;
extern float paddle_speed;

extern float paddle1_y;
extern float paddle1_x;
extern float paddle1_up;
extern float paddle1_down;

extern float paddle2_y;
extern float paddle2_x;
extern float paddle2_up;
extern float paddle2_down;

// Ball
extern float ball_shape;
extern float ball_speed_y;
extern float ball_speed_x;
extern int ball_y;
extern int ball_x;

extern int count;
