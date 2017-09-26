#include "header.hpp"

// void	graphic_mode()
// {
	
// }

// void	terminal_mode()
// {
// 	initscr();
// 	keypad(stdscr, TRUE);
// 	start_color();
// 	curs_set(0);
// 	noecho();

// 	init_pair(1, COLOR_CYAN, COLOR_BLACK);
// 	init_pair(2, COLOR_RED, COLOR_BLACK);
// 	init_pair(3, COLOR_GREEN, COLOR_BLACK);

// 	getch();
// 	endwin();
// }

// int		main()
// {
// 	int	c;

// 	std::cout << "View in terminal or in graphical mode? (1/2)" << std::endl;
// 	std::cin >> c;
// 	if (c == 1)
// 		terminal_mode();
// 	else if (c == 2)
// 		graphic_mode();
// 	else
// 		std::cout << "1 - terminal, 2 - graphical" << std::endl;
// 	return 0;
// }

// Main loop
void main_loop_function()
{
   // Z angle
   static float angle;
   // Clear color (screen) 
   // And depth (used internally to block obstructed objects)
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // Load identity matrix
   glLoadIdentity();
   // Multiply in translation matrix
   glTranslatef(0,0, -10);
   // Multiply in rotation matrix
   glRotatef(angle, 0, 0, 1);
   // Render colored quad
   glBegin(GL_QUADS);
   glColor3ub(255, 000, 000); glVertex2f(-1,  1);
   glColor3ub(000, 255, 000); glVertex2f( 1,  1);
   glColor3ub(000, 000, 255); glVertex2f( 1, -1);
   glColor3ub(255, 255, 000); glVertex2f(-1, -1);
   glEnd();
   // Swap buffers (color buffers, makes previous render visible)
	glutSwapBuffers();
   // Increase angle to rotate
   angle+=0.25;
}

// Initialze OpenGL perspective matrix
void GL_Setup(int width, int height)
{

	glViewport( 0, 0, width, height );
	glMatrixMode( GL_PROJECTION );
	glEnable( GL_DEPTH_TEST );
	gluPerspective( 45, (float)width/height, .1, 100 );
	glMatrixMode( GL_MODELVIEW );
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutCreateWindow("GLUT Example!!!");

	glutIdleFunc(main_loop_function);

	GL_Setup(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutMainLoop();
}