/***************************
AI Pong header file
Written by @Isak Wilkens
**************************/
// Menu functions
void menu();
void dogmenu();

// Menu variables
extern int menu_chooser;
extern int dogmenu_running;

// Screen defenitions
extern uint8_t display_array[32][128];
extern uint8_t	display_pixels[512];

// Screen functions
void display_clear();
void string_clear();
void castToScreen();

// Motion functions
void singleplayer_motion();
void multiplayer_motion();
void computer_motion();
