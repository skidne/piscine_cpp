#include "Player.hpp"
#include "Enemy.hpp"
#include "header.hpp"

Player	player;
Enemy	enemy[MAXNR];
Bullet	bPlayer[MAXNR], bEnemy[MAXNR];

void	enemiesInit()
{
	int t;

	for (int i = 0; i < MAXNR; i++)
	{
		enemy[i].die();
		t = rand() % 3;
		if (t == 0)
			enemy[i].type = 1;
		else if (t == 1)
			enemy[i].type = 2;
		else
			enemy[i].type = 3;
	}
}

void	bulletsInit()
{
	for (int i = 0; i < MAXNR; i++)
	{
		bPlayer[i].init(PLAYER);
		bEnemy[i].init(ENEMY);
	}
}

void	enemyBehaviour()
{
	static int a = 0;
	bool	flag = false;

	for (int i = 0; i < MAXNR; i++)
	{
		if (enemy[i].lives > 0)
		{
			enemy[i].checkCollision(player);
			enemy[i].draw();
			if (!(a % 1032))
				enemy[i].move(player.x1, player.y1);
			if (!(a % 3532))
				enemy[i].shoot(bEnemy);
		}
		if (!flag && !(a % 8621) && !enemy[i].lives)
		{
			enemy[i].spawn();
			flag = true;
		}
	}
	a = (a == INT_MAX) ? 0 : a + 1;
}

void	bulletBehaviour()
{
	static int a = 0;

	if (!(a % 2532))
		player.shoot(bPlayer);
	for (int i = 0; i < MAXNR; i++)
	{
		if (!bPlayer[i].available())
		{
			bPlayer[i].checkCollision(enemy);
			if (bPlayer[i].available())
				player.setScore(player.getScore() + 1);
			bPlayer[i].draw();
			if (!(a % 223))
				bPlayer[i].move();
		}
		if (!bEnemy[i].available())
		{
			bEnemy[i].draw();
			bEnemy[i].checkCollision(player);
			if (!(a % 223))
				bEnemy[i].move();
		}
	}
	a = (a == INT_MAX) ? 0 : a + 1;
}

void	play_game()
{
	int c;

	clear();
	main_menu();
	if ((c = getch()) == ' ')
	{
		restart:
		clock_t	begin = clock();
		cbreak();
		nodelay(stdscr, TRUE);

		enemiesInit();
		bulletsInit();
		player.init(2);

		while (1)
		{
			if (player.getLives() < 1)
			{
				game_over();
				goto restart;
			}
			clear();
			scenery();
			player.draw();
			bulletBehaviour();
			enemyBehaviour();
			showInfo(player.getLives(), player.getScore(), begin);
			switch((c = getch()))
			{
				case 27: exit_game();
								break;
				case KEY_RIGHT: player.move(RIGHT);
								break;
				case KEY_LEFT: player.move(LEFT);
								break;
				case KEY_DOWN: player.move(DOWN);
								break;
				case KEY_UP: player.move(UP);
								break;
			}
			refresh();
		}
	}
	else
		exit_game();
	getch();
}

int 	main()
{
	srand(time(NULL));

	play_game();
	endwin();
	return 1;
}