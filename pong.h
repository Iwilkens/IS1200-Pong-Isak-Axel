/***************************
AI Pong header file
Written by @Isak Wilkens,
@Axel Lokrantz Månson
**************************/

// ** Functions **

// Menu functions
void menu(void);
void creditsMenu(void);

// Screen functions
void display_clear(void);
void string_clear(void);
void castToScreen(void);
void set_displayArray(int, int, int, int);

// Motion functions
void multiplayer_motion(int);
void computer_motion(void);

// Game funcitons
void multiplayer(int);
void quit(void);
void reset(void);
void score(int);

// Collision functions
void paddle1_collision(void);
void paddle2_collision(void);
void ball_collision(void);


// ** Global variables **
// Menu variables
extern int menu_chooser;
extern int credits_active;

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

// game variables
extern int game_active;

// main file vairables
extern int buttons;
extern int switches;
int score_player1;
int score_player2;
