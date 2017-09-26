#ifndef HEADER_H
# define HEADER_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>
#include <cfloat>
#include <climits>
#include <unistd.h>
#include <ncurses.h>

# define PLAYER 42
# define ENEMY -42
# define MAXNR 1000
# define PLAYER_STR1 "^"
# define PLAYER_STR2 "|=#=|"
# define ENEMY1_STR1 "/:#:\\"
# define ENEMY1_STR2 "|^|"
# define ENEMY2_STR1 "+-.-+"
# define ENEMY2_STR2 "\'|\'"
# define BULLET '|'
# define RIGHT 10
# define LEFT 20
# define UP 30
# define DOWN 40

std::string 	ito_str(int nr);
std::string		fto_str(float nr);
float			timePl(clock_t begin);
void			showInfo(int lives, int score, clock_t begin);
void			main_menu();
void			exit_game();
void			game_over();
void			scenery();

#endif