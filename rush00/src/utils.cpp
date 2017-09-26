#include "Player.hpp"

std::string ito_str(int nr)
{
	std::stringstream s;

	s << nr;
	return s.str();
}

std::string	fto_str(float nr)
{
	std::stringstream s;

	s << nr;
	return s.str();
}

float	timePl(clock_t begin)
{
	float kek = (float)(clock() - begin) / CLOCKS_PER_SEC;
	return ((int)(kek * 100.0F + 0.5F)) / 100.0F;
}

void	showInfo(int lives, int score, clock_t begin)
{
	std::string	str;

	attron(A_BOLD | COLOR_PAIR(3));

	str = "Lives: " + ito_str(lives);
	mvprintw(0, (COLS - str.length())/ 3, str.c_str());

	str = "Score: " + ito_str(score);
	mvprintw(0, (COLS - str.length()) / 2, str.c_str());

	str = "Time:";
	mvprintw(0, (COLS - str.length()) / 1.5, str.c_str());

	str = fto_str(timePl(begin));
	mvprintw(0, (COLS - str.length()) / 1.5 + 6, str.c_str());

	attroff(A_BOLD | COLOR_PAIR(3));
}

void	main_menu()
{
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	curs_set(0);
	noecho();

	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_BLACK);

	char	play[] = "Press [space] to play";
	char	escape[] = "Press anything else to exit";

	char	s1[] = " $$$$$$\\  $$\\   $$\\  $$$$$$\\  $$$$$$$\\      $$$$$$\\ $$\\   $$\\ $$\\    $$\\  $$$$$$\\  $$$$$$$\\  $$$$$$$$\\ $$$$$$$\\   $$$$$$\\  ";
	char	s2[] = "$$  __$$\\ $$ |  $$ |$$  __$$\\ $$  __$$\\     \\_$$  _|$$$\\  $$ |$$ |   $$ |$$  __$$\\ $$  __$$\\ $$  _____|$$  __$$\\ $$  __$$\\ ";
	char	s3[] = "$$ /  \\__|$$ |  $$ |$$ /  $$ |$$ |  $$ |      $$ |  $$$$\\ $$ |$$ |   $$ |$$ /  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$ /  \\__|";
	char	s4[] = "$$ |      $$$$$$$$ |$$$$$$$$ |$$$$$$$  |      $$ |  $$ $$\\$$ |\\$$\\  $$  |$$$$$$$$ |$$ |  $$ |$$$$$\\    $$$$$$$  |\\$$$$$$\\  ";
	char	s5[] = "$$ |      $$  __$$ |$$  __$$ |$$  __$$<       $$ |  $$ \\$$$$ | \\$$\\$$  / $$  __$$ |$$ |  $$ |$$  __|   $$  __$$<  \\____$$\\ ";
	char	s6[] = "$$ |  $$\\ $$ |  $$ |$$ |  $$ |$$ |  $$ |      $$ |  $$ |\\$$$ |  \\$$$  /  $$ |  $$ |$$ |  $$ |$$ |      $$ |  $$ |$$\\   $$ |";
	char	s7[] = "\\$$$$$$  |$$ |  $$ |$$ |  $$ |$$ |  $$ |    $$$$$$\\ $$ | \\$$ |   \\$  /   $$ |  $$ |$$$$$$$  |$$$$$$$$\\ $$ |  $$ |\\$$$$$$  |";
	char	s8[] = " \\______/ \\__|  \\__|\\__|  \\__|\\__|  \\__|     \\______|\\__|  \\__|    \\_/    \\__|  \\__|\\_______/ \\________|\\__|  \\__| \\______/ ";

	attron(A_BOLD | COLOR_PAIR(3));

	mvprintw(LINES / 2 - 6, (COLS - strlen(s1)) / 2, s1);
	mvprintw(LINES / 2 - 5, (COLS - strlen(s2)) / 2, s2);
	mvprintw(LINES / 2 - 4, (COLS - strlen(s3)) / 2, s3);
	mvprintw(LINES / 2 - 3, (COLS - strlen(s4)) / 2, s4);
	mvprintw(LINES / 2 - 2, (COLS - strlen(s5)) / 2, s5);
	mvprintw(LINES / 2 - 1, (COLS - strlen(s6)) / 2, s6);
	mvprintw(LINES / 2, (COLS - strlen(s7)) / 2, s7);
	mvprintw(LINES / 2 + 1, (COLS - strlen(s8)) / 2, s8);

	attroff(A_BOLD | COLOR_PAIR(3));

	attron(A_BOLD | COLOR_PAIR(1));

	mvprintw(LINES / 1.3, (COLS - strlen(play)) / 2, play);
	mvprintw(LINES / 1.25, (COLS - strlen(escape)) / 2, escape);

	attroff(A_BOLD | COLOR_PAIR(1));	
}

void	exit_game()
{
	clear();

	char s1[] = "  GGGG   OOOOO   OOOOO  DDDDD   BBBBB   YY   YY EEEEEEE         ((( ";
	char s2[] = " GG  GG OO   OO OO   OO DD  DD  BB   B  YY   YY EE         ::: (((  ";
	char s3[] = "GG      OO   OO OO   OO DD   DD BBBBBB   YYYYY  EEEEE          (((  ";
	char s4[] = "GG   GG OO   OO OO   OO DD   DD BB   BB   YYY   EE         ::: (((  ";
	char s5[] = " GGGGGG  OOOO0   OOOO0  DDDDDD  BBBBBB    YYY   EEEEEEE         ((( ";

	attron(A_BOLD | COLOR_PAIR(5));

	mvprintw(LINES / 2 - 2, (COLS - strlen(s1)) / 2, s1);
	mvprintw(LINES / 2 - 1, (COLS - strlen(s2)) / 2, s2);
	mvprintw(LINES / 2, (COLS - strlen(s3)) / 2, s3);
	mvprintw(LINES / 2 + 1, (COLS - strlen(s4)) / 2, s4);
	mvprintw(LINES / 2 + 2, (COLS - strlen(s5)) / 2, s5);

	attroff(A_BOLD | COLOR_PAIR(5));
	refresh();
	sleep(1);
	endwin();
	exit(1);
}

void	game_over()
{
	clear();
	char s2[] = "  6MMMMb/      dM.    `MMb     dMM`MMMMMMMMM         6MMMMb  `Mb(     )d' `MMMMMMMMM `MMMMMMMb.  ";
	char s3[] = " 8P    YM     ,MMb     MMM.   ,PMM MM      \\        8P    Y8  YM.     ,P   MM      \\  MM    `Mb  ";
	char s4[] = "6M      Y     d'YM.    M`Mb   d'MM MM              6M      Mb `Mb     d'   MM         MM     MM  ";
	char s5[] = "MM           ,P `Mb    M YM. ,P MM MM    ,         MM      MM  YM.   ,P    MM    ,    MM     MM  ";
	char s6[] = "MM           d'  YM.   M `Mb d' MM MMMMMMM         MM      MM  `Mb   d'    MMMMMMM    MM    .M9  ";
	char s7[] = "MM     ___  ,P   `Mb   M  YM.P  MM MM    `         MM      MM   YM. ,P     MM    `    MMMMMMM9'  ";
	char s8[] = "MM     `M'  d'    YM.  M  `Mb'  MM MM              MM      MM   `Mb d'     MM         MM  \\M\\    ";
	char s9[] = "YM      M  ,MMMMMMMMb  M   YP   MM MM              YM      M9    YM,P      MM         MM   \\M\\   ";
	char s10[] = " 8b    d9  d'      YM. M   `'   MM MM      /        8b    d8     `MM'      MM      /  MM    \\M\\  ";
	char s11[] = "  YMMMM9 _dM_     _dMM_M_      _MM_MMMMMMMMM         YMMMM9       YP      _MMMMMMMMM _MM_    \\M\\_";

	attron(A_BOLD | COLOR_PAIR(2));
	mvprintw(LINES / 2 - 5, (COLS - strlen(s2)) / 2, s2);
	mvprintw(LINES / 2 - 4, (COLS - strlen(s3)) / 2, s3);
	mvprintw(LINES / 2 - 3, (COLS - strlen(s4)) / 2, s4);
	mvprintw(LINES / 2 - 2, (COLS - strlen(s5)) / 2, s5);
	mvprintw(LINES / 2 - 1, (COLS - strlen(s6)) / 2, s6);
	mvprintw(LINES / 2, (COLS - strlen(s7)) / 2, s7);
	mvprintw(LINES / 2 + 1, (COLS - strlen(s8)) / 2, s8);
	mvprintw(LINES / 2 + 2, (COLS - strlen(s9)) / 2, s9);
	mvprintw(LINES / 2 + 3, (COLS - strlen(s10)) / 2, s10);
	mvprintw(LINES / 2 + 4, (COLS - strlen(s11)) / 2, s11);
	attroff(A_BOLD | COLOR_PAIR(2));

	refresh();
	sleep(2);
}

void	scenery()
{
	int	j;

	for (int i = 0; i < 10; i++)
	{
		j = 0;
		while (++j < 8)
		{
			attron(COLOR_PAIR(j));
			mvaddch(rand() % LINES, rand() % COLS - 1, '.');
			attroff(COLOR_PAIR(j));
		}
	}
}
