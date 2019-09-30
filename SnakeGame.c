//NOTE - make sure to put the .dll in the same folder as the produced executable!
//define the platform
#define WINDOWS

#ifdef UNIX
#include "ncurses.h"
#include "unistd.h"
#endif

#ifdef WINDOWS
#include "curses.h"
#include "windows.h"
#include "time.h"
#endif

#include "stdio.h"
#include "SnakeGame.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"

#define DELAY 20
#define PI 3.14159265
#define DISPLAY_SIZE 25
#define TITLE_BUFFER 2
#define TERMINAL_NUM_ROWS 60
#define TERMINAL_NUM_COLS 80

//declarations
void draw_borders(WINDOW *screen);
void resizeWindow_crossPlatform(int rows, int cols);

//Main entry point
int main(void){

	system("color 2");

	//Local declarations
	int ct = 0;
	char play;
	char input_ch = 0;
	char mystr[100];
	WINDOW* win = NULL;
	int x = 80;
	int y = 60;
	int i;
	int level = 1;
	int score = 0;
	int highscore = 0;
	int rx = 40;
	int ry = 30;
	int bx = 40;
	int by = 31;
	int cx = 40;
	int cy = 32;
	int dx = 40;
	int dy = 33;
	int ex = 40;
	int ey = 34;
	int fx = 40;
	int fy = 35;
	int gx = 40;
	int gy = 36;
	int hx = 40;
	int hy = 37;
	int ix = 40;
	int iy = 38;
	int xx = 40;
	int xy = 39;
	int mx = 40;
	int my = 30;
	int fx0 = 5;
	int fy0 = 20;
	int fx1 = 50;
	int fy1 = 18;
	int fx2 = 23;
	int fy2 = 20;
	int fx3 = 23;
	int fy3 = 46;
	int starter = 0;
	int p = 1;
	int quit = 0;
	char head;
	char torso;
	char center;
	char back;
	char tail;
	char xtra1;
	char xtra2;
	char xtra3;
	char xtra4;
	char space;
	char food;
	char monster;
	
	//snake assignment
	head = 'O';
	torso = 'O';
	center = 'O';
	back = ' ';
	tail = ' ';
	xtra1 = ' ';
	xtra2 = ' ';
	xtra3 = ' ';
	xtra4 = ' ';
	food = '+';
	space = ' ';
	monster = 'M';
 

	resizeWindow_crossPlatform(60, 80);
	printf("Enter Name:");
	scanf("%s", &mystr);
	system("cls");
	Sleep(100);

	//Initialize the screen
	win = SetupWindows();
	resizeWindow_crossPlatform(60, 80);

	//Clear the screen
	clear();

	//Build Screen
	//Greet player
	draw_borders(win);
	mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
	mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
	mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
	mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
	mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
	mvprintw(5, MARGIN_LEFT, "                                        |  / ");
	mvprintw(6, MARGIN_LEFT, "                                   _____| |");
	mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
	mvprintw(8, MARGIN_LEFT, "                                  |  |");
	mvprintw(9, MARGIN_LEFT, "                           _______|  |");
	mvprintw(10, MARGIN_LEFT,"                          /__________|");
	
	
	while (1){
		//Handle user input
		input_ch = getch();
		mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
		mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
		mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
		mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
		mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
		mvprintw(5, MARGIN_LEFT, "                                        |  / ");
		mvprintw(6, MARGIN_LEFT, "                                   _____| |");
		mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
		mvprintw(8, MARGIN_LEFT, "                                  |  |");
		mvprintw(9, MARGIN_LEFT, "                           _______|  |");
		mvprintw(10, MARGIN_LEFT, "                          /__________|");

		if (input_ch == 'p'){
			clear();
			draw_borders(win);
			 rx = 40;
			 ry = 30;
			 bx = 40;
			 by = 31;
			 cx = 40;
			 cy = 32;
			 dx = 40;
			 dy = 33;
			 ex = 40;
			 ey = 34;
			 fx = 40;
			 fy = 35;
			 gx = 40;
			 gy = 36;
			 hx = 40;
			 hy = 37;
			 ix = 40;
			 iy = 38;
			 xx = 40;
			 xy = 39;
			 fx0 = 5;
			 fy0 = 20;
			 fx1 = 50;
			 fy1 = 18;
			 fx2 = 23;
			 fy2 = 20;
			 fx3 = 23;
			 fy3 = 46;
			 mx = 40;
			 my = 30;
			 level = 1;
			 monster = 'M';
			 back = ' ';
			 tail = ' ';
			 xtra1 = ' ';
			 xtra2 = ' ';
			 xtra3 = ' ';
			 xtra4 = ' ';
			mvaddch(rx, ry, head);
			mvaddch(bx, by, torso);
			mvaddch(cx, cy, center);
			mvaddch(dx, dy, back);
			mvaddch(ex, ey, tail);
			mvaddch(fx, fy, xtra1);
			mvaddch(gx, gy, xtra2);
			mvaddch(hx, hy, xtra3);
			mvaddch(ix, iy, xtra4);
			mvaddch(fx0, fy0, food);
			mvaddch(fx1, fy1, food);
			mvaddch(fx2, fy2, food);
			mvaddch(fx3, fy3, food);
			quit = 1;
			//Spawn Snake
			

			while (quit == 1){

				if (p==1)
					play = getch();
				
				//enable WASD
				switch (play) {
				case 'w':
					while (1)
					{
						if (starter == 1){
							starter = starter++;
							mvprintw(1, AW_CENTER, "                          ");
						}
						if (rx > 1 && rx < 61){
							mvaddch(xx, xy, space);
							xx = ix;
							xy = iy;
							ix = hx;
							iy = hy;
							hx = gx;
							hy = gy;
							gx = fx;
							gy = fy;
							fx = ex;
							fy = ey;
							ex = dx;
							ey = dy;
							dx = cx;
							dy = cy;
							cx = bx;
							cy = by;
							bx = rx;
							by = ry;
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(rx, ry, space);
							mvaddch(bx, by, space);
							mvaddch(cx, cy, space);
							mvaddch(dx, dy, space);
							mvaddch(ex, ey, space);
							draw_borders(win);
							rx = rx--;
							mvaddch(rx, ry, head);
							mvaddch(bx, by, torso);
							mvaddch(cx, cy, center);
							mvaddch(dx, dy, back);
							mvaddch(ex, ey, tail);
							mvaddch(fx, fy, xtra1);
							mvaddch(gx, gy, xtra2);
							mvaddch(hx, hy, xtra3);
							mvaddch(ix, iy, xtra4);
							mvaddch(fx0, fy0, food);
							mvaddch(fx1, fy1, food);
							mvaddch(fx2, fy2, food);
							mvaddch(fx3, fy3, food);
							refresh();
							Sleep(50);
							play = getch();
							if (play == 'a' || play == 'd' || play == 'r' || play == 'g' || play == 'f' || play == 't')
							{
								p = 0;
								break;
							}
							if (play == 'q'){
								quit = 0;
								clear();
								draw_borders(win);
								mvaddch(xx, xy, space);
								mvaddch(ix, iy, space);
								mvaddch(hx, hy, space);
								mvaddch(gx, gy, space);
								mvaddch(fx, fy, space);
								mvaddch(mx, my, ' ');
								mvaddch(rx, ry, ' ');
								mvaddch(bx, by, ' ');
								mvaddch(cx, cy, ' ');
								mvaddch(dx, dy, ' ');
								mvaddch(ex, ey, ' ');
								mvaddch(fx0, fy0, ' ');
								mvaddch(fx1, fy1, ' ');
								mvaddch(fx2, fy2, ' ');
								mvaddch(fx3, fy3, ' ');
								rx = 40;
								ry = 30;
								bx = 40;
								by = 31;
								cx = 40;
								cy = 32;
								dx = 40;
								dy = 33;
								ex = 40;
								ey = 34;
								fx = 40;
								fy = 35;
								gx = 40;
								gy = 36;
								hx = 40;
								hy = 37;
								ix = 40;
								iy = 38;
								xx = 40;
								xy = 39;
								fx0 = 5;
								fy0 = 20;
								fx1 = 50;
								fy1 = 18;
								fx2 = 23;
								fy2 = 20;
								fx3 = 23;
								fy3 = 46;
								mx = 40;
								my = 30;
								starter = 0;
								level = 1;
								highscore = score;
								score = 0;
								back = ' ';
								tail = ' ';
								xtra1 = ' ';
								xtra2 = ' ';
								xtra3 = ' ';
								xtra4 = ' ';
								mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
								mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
								mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
								mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
								mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
								mvprintw(5, MARGIN_LEFT, "                                        |  / ");
								mvprintw(6, MARGIN_LEFT, "                                   _____| |");
								mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
								mvprintw(8, MARGIN_LEFT, "                                  |  |");
								mvprintw(9, MARGIN_LEFT, "                           _______|  |");
								mvprintw(10, MARGIN_LEFT, "                          /__________|");
								break;
							}
						}
						if (rx <= 1)
						{
							if (ry >= 1 && ry < 38){
								mvaddch(rx, ry, ' ');
								ry = ry++;
								play = 'g';
								p = 0;
								break;
							}
							if (ry > 37 && ry <= 81){
								mvaddch(rx, ry, ' ');
								ry = ry--;
								play = 'f';
								p = 0;
								break;
							}
						}
						if (rx == fx0 && ry == fy0){
							score = score++;
							if (score == 1){
								 back = 'O';
								fx0 = 9000;
							}
							if (score == 2){
								 tail = 'O';
								fx0 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx0 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx0 = 9000;
							}

						}
						if (rx == fx1 && ry == fy1) {
							score = score++;
							if (score == 1){
								back = 'O';
								fx1 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx1 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx1 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx1 = 9000;
							}

						}
						if (rx == fx2 && ry == fy2){
							score = score++;
							if (score == 1){
								back = 'O';
								fx2 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx2 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx2 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx2 = 9000;
							}

						}
						if (rx == fx3 && ry == fy3){
							score = score++;

							if (score == 1){
								back = 'O';
								fx3 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx3 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx3 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx3 = 9000;
							}
						}
						if (score == 4 && level == 1 && play == 'm'){
							level = level++;
							mvaddch(mx, my, monster);
							play = 'w';
							p = 0;
							break;
						}
						if (level == 2){
							monster = 'M';
							if (rx == mx && ry == my){
								score = score++;
							}
							if (mx > 1 && mx < 61){
							mvaddch(mx, my, ' ');
							mx = mx-2;
							mvaddch(mx, my, monster);
							refresh();
							Sleep(20);
						}
						if (mx <= 1){
							mvaddch(mx, my, ' ');
							mx = 58;
							mvaddch(mx, my, monster);
							refresh();
							Sleep(20);
						}
					}
						
					}break;
				case 'd':
					while (1)
					{
						if (starter == 1){
							starter = starter++;
							mvprintw(1, AW_CENTER, "                          ");
						}
						if (ry > 0 && ry < 78){
							mvaddch(xx, xy, space);
							xx = ix;
							xy = iy;
							ix = hx;
							iy = hy;
							hx = gx;
							hy = gy;
							gx = fx;
							gy = fy;
							fx = ex;
							fy = ey;
							ex = dx;
							ey = dy;
							dx = cx;
							dy = cy;
							cx = bx;
							cy = by;
							bx = rx;
							by = ry;
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(rx, ry, space);
							mvaddch(bx, by, space);
							mvaddch(cx, cy, space);
							mvaddch(dx, dy, space);
							mvaddch(ex, ey, space);
							draw_borders(win);
							ry = ry++;
							mvaddch(rx, ry, head);
							mvaddch(bx, by, torso);
							mvaddch(cx, cy, center);
							mvaddch(dx, dy, back);
							mvaddch(ex, ey, tail);
							mvaddch(ex, ey, tail);
							mvaddch(fx, fy, xtra1);
							mvaddch(gx, gy, xtra2);
							mvaddch(hx, hy, xtra3);
							mvaddch(ix, iy, xtra4);
							mvaddch(fx0, fy0, food);
							mvaddch(fx1, fy1, food);
							mvaddch(fx2, fy2, food);
							mvaddch(fx3, fy3, food);
							refresh();
							Sleep(50);
							play = getch();
							
							if (play == 'w' || play == 's' || play == 'r' || play == 'g' || play == 'f' || play == 't')
							{
								p = 0;
								break;
							}
						}
						if (ry >= 78)
						{
							if (rx >= 0 && rx < 30){
								mvaddch(rx, ry, ' ');
								rx = rx++;
								play = 'f';
								p = 0;
								break;
							}
							if (rx > 29 && rx <= 61){
								mvaddch(rx, ry, ' ');
								rx = rx--;
								play = 'r';
								p = 0;
								break;
							}
						}
						if (rx == fx0 && ry == fy0){
							score = score++;
							if (score == 1){
								back = 'O';
								fx0 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx0 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx0 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx0 = 9000;
							}

						}
						if (rx == fx1 && ry == fy1) {
							score = score++;
							if (score == 1){
								back = 'O';
								fx1 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx1 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx1 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx1 = 9000;
							}

						}
						if (rx == fx2 && ry == fy2){
							score = score++;
							if (score == 1){
								back = 'O';
								fx2 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx2 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx2 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx2 = 9000;
							}

						}
						if (rx == fx3 && ry == fy3){
							score = score++;

							if (score == 1){
								back = 'O';
								fx3 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx3 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx3 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx3 = 9000;
							}
						}
						if (score == 4 && level == 1 && play == 'm'){
							level = level++;
							mvaddch(mx, my, monster);
							play = 'd';
							p = 0;
							break;
						}
						if (level == 2){
							monster = 'M';
							if (rx == mx && ry == my){
								score = score++;
							}
							if (my > 0 && my < 78){
								mvaddch(mx, my, ' ');
								my = my + 2;
								mvaddch(mx, my, monster);
								refresh();
								Sleep(20);
							}
							if (my >= 78){
								mvaddch(mx, my, ' ');
								my = 2;
								mvaddch(mx, my, monster);
								refresh();
								Sleep(20);
							}
						}
						if (play == 'q'){
							quit = 0;
							clear();
							draw_borders(win);
							mvaddch(xx, xy, space);
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(mx, my, ' ');
							mvaddch(rx, ry, ' ');
							mvaddch(bx, by, ' ');
							mvaddch(cx, cy, ' ');
							mvaddch(dx, dy, ' ');
							mvaddch(ex, ey, ' ');
							mvaddch(fx0, fy0, ' ');
							mvaddch(fx1, fy1, ' ');
							mvaddch(fx2, fy2, ' ');
							mvaddch(fx3, fy3, ' ');
							rx = 40;
							ry = 30;
							bx = 40;
							by = 31;
							cx = 40;
							cy = 32;
							dx = 40;
							dy = 33;
							ex = 40;
							ey = 34;
							fx = 40;
							fy = 35;
							gx = 40;
							gy = 36;
							hx = 40;
							hy = 37;
							ix = 40;
							iy = 38;
							xx = 40;
							xy = 39;
							fx0 = 5;
							fy0 = 20;
							fx1 = 50;
							fy1 = 18;
							fx2 = 23;
							fy2 = 20;
							fx3 = 23;
							fy3 = 46;
							mx = 40;
							my = 30;
							starter = 0;
							level = 1;
							highscore = score;
							score = 0;
							back = ' ';
							tail = ' ';
							xtra1 = ' ';
							xtra2 = ' ';
							xtra3 = ' ';
							xtra4 = ' ';
							mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
							mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
							mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
							mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
							mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
							mvprintw(5, MARGIN_LEFT, "                                        |  / ");
							mvprintw(6, MARGIN_LEFT, "                                   _____| |");
							mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
							mvprintw(8, MARGIN_LEFT, "                                  |  |");
							mvprintw(9, MARGIN_LEFT, "                           _______|  |");
							mvprintw(10, MARGIN_LEFT, "                          /__________|");
							break;
						}


					}break;
				case 'a':
					while (1)
					{
						if (starter == 1){
							starter = starter++;
							mvprintw(1, AW_CENTER, "                          ");
						}
						if (ry > 1 && ry < 81){
							mvaddch(xx, xy, space);
							xx = ix;
							xy = iy;
							ix = hx;
							iy = hy;
							hx = gx;
							hy = gy;
							gx = fx;
							gy = fy;
							fx = ex;
							fy = ey;
							ex = dx;
							ey = dy;
							dx = cx;
							dy = cy;
							cx = bx;
							cy = by;
							bx = rx;
							by = ry;
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(rx, ry, space);
							mvaddch(bx, by, space);
							mvaddch(cx, cy, space);
							mvaddch(dx, dy, space);
							mvaddch(ex, ey, space);
							draw_borders(win);
							ry = ry--;
							mvaddch(rx, ry, head);
							mvaddch(bx, by, torso);
							mvaddch(cx, cy, center);
							mvaddch(dx, dy, back);
							mvaddch(ex, ey, tail);
							mvaddch(ex, ey, tail);
							mvaddch(fx, fy, xtra1);
							mvaddch(gx, gy, xtra2);
							mvaddch(hx, hy, xtra3);
							mvaddch(ix, iy, xtra4);
							mvaddch(fx0, fy0, food);
							mvaddch(fx1, fy1, food);
							mvaddch(fx2, fy2, food);
							mvaddch(fx3, fy3, food);
							refresh();
							Sleep(50);
							play = getch();
							
							if (play == 'w' || play == 's' || play == 'r' || play == 'g' || play == 'f' || play == 't')
							{
								p = 0;
								break;
							}

						}
						if (ry <= 1)
						{
							if (rx >= 0 && rx < 30){
								mvaddch(rx, ry, ' ');
								rx = rx++;
								play = 'g';
								p = 0;
								break;
							}
							if (rx > 29 && rx <= 61){
								mvaddch(rx, ry, ' ');
								rx = rx--;
								play = 't';
								p = 0;
								break;
							}
						}
						if (rx == fx0 && ry == fy0){
							score = score++;
							if (score == 1){
								back = 'O';
								fx0 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx0 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx0 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx0 = 9000;
							}

						}
						if (rx == fx1 && ry == fy1) {
							score = score++;
							if (score == 1){
								back = 'O';
								fx1 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx1 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx1 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx1 = 9000;
							}

						}
						if (rx == fx2 && ry == fy2){
							score = score++;
							if (score == 1){
								back = 'O';
								fx2 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx2 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx2 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx2 = 9000;
							}

						}
						if (rx == fx3 && ry == fy3){
							score = score++;

							if (score == 1){
								back = 'O';
								fx3 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx3 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx3 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx3 = 9000;
							}
						}
						if (score == 4 && level == 1 && play == 'm'){
							level = level++;
							mvaddch(mx, my, monster);
							play = 'a';
							p = 0;
							break;
						}
						if (level == 2){
							monster = 'M';
							if (rx == mx && ry == my){
								score = score++;
							}
							if (my > 1 && my < 81){
								mvaddch(mx, my, ' ');
								my = my - 2;
								mvaddch(mx, my, monster);
								refresh();
								Sleep(20);
							}
							if (my <= 1){
								mvaddch(mx, my, ' ');
								my = 78;
								mvaddch(mx, my, monster);
								refresh();
								Sleep(20);
							}
						}
						if (play == 'q'){
							quit = 0;
							clear();
							draw_borders(win);
							mvaddch(xx, xy, space);
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(mx, my, ' ');
							mvaddch(rx, ry, ' ');
							mvaddch(bx, by, ' ');
							mvaddch(cx, cy, ' ');
							mvaddch(dx, dy, ' ');
							mvaddch(ex, ey, ' ');
							mvaddch(fx0, fy0, ' ');
							mvaddch(fx1, fy1, ' ');
							mvaddch(fx2, fy2, ' ');
							mvaddch(fx3, fy3, ' ');
							rx = 40;
							ry = 30;
							bx = 40;
							by = 31;
							cx = 40;
							cy = 32;
							dx = 40;
							dy = 33;
							ex = 40;
							ey = 34;
							fx = 40;
							fy = 35;
							gx = 40;
							gy = 36;
							hx = 40;
							hy = 37;
							ix = 40;
							iy = 38;
							xx = 40;
							xy = 39;
							fx0 = 5;
							fy0 = 20;
							fx1 = 50;
							fy1 = 18;
							fx2 = 23;
							fy2 = 20;
							fx3 = 23;
							fy3 = 46;
							mx = 40;
							my = 30;
							starter = 0;
							level = 1;
							highscore = score;
							score = 0;
							back = ' ';
							tail = ' ';
							xtra1 = ' ';
							xtra2 = ' ';
							xtra3 = ' ';
							xtra4 = ' ';
							mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
							mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
							mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
							mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
							mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
							mvprintw(5, MARGIN_LEFT, "                                        |  / ");
							mvprintw(6, MARGIN_LEFT, "                                   _____| |");
							mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
							mvprintw(8, MARGIN_LEFT, "                                  |  |");
							mvprintw(9, MARGIN_LEFT, "                           _______|  |");
							mvprintw(10, MARGIN_LEFT, "                          /__________|");
							break;
						}

					}break;
				case 's':

					while (1)
					{
						if (starter == 1){
							starter = starter++;
							mvprintw(1, AW_CENTER, "                          ");
						}
						if (rx > 0 && rx < 58)
						{
							mvaddch(xx, xy, space);
							xx = ix;
							xy = iy;
							ix = hx;
							iy = hy;
							hx = gx;
							hy = gy;
							gx = fx;
							gy = fy;
							fx = ex;
							fy = ey;
							ex = dx;
							ey = dy;
							dx = cx;
							dy = cy;
							cx = bx;
							cy = by;
							bx = rx;
							by = ry;
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(rx, ry, space);
							mvaddch(bx, by, space);
							mvaddch(cx, cy, space);
							mvaddch(dx, dy, space);
							mvaddch(ex, ey, space);
							draw_borders(win);
							rx = rx++;
							mvaddch(rx, ry, head);
							mvaddch(bx, by, torso);
							mvaddch(cx, cy, center);
							mvaddch(dx, dy, back);
							mvaddch(ex, ey, tail);
							mvaddch(ex, ey, tail);
							mvaddch(fx, fy, xtra1);
							mvaddch(gx, gy, xtra2);
							mvaddch(hx, hy, xtra3);
							mvaddch(ix, iy, xtra4);
							mvaddch(fx0, fy0, food);
							mvaddch(fx1, fy1, food);
							mvaddch(fx2, fy2, food);
							mvaddch(fx3, fy3, food);
							refresh();
							Sleep(50);
							play = getch();
							
							if (play == 'a' || play == 'd'|| play == 'r' || play == 'g' || play == 'f' || play == 't')
							{
								p = 0;
								break;
							}
							}
							if (rx >= 58)
							{
								if (ry >= 1 && ry < 38){
									mvaddch(rx, ry, ' ');
									ry = ry++;
									play = 't';
									p = 0;
									break;
								}
								if (ry > 37 && ry <= 81){
									mvaddch(rx, ry, ' ');
									ry = ry--;
									play = 'r';
									p = 0;
									break;
								}
							}
							if (rx == fx0 && ry == fy0){
								score = score++;
								if (score == 1){
									back = 'O';
									fx0 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx0 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx0 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx0 = 9000;
								}

							}
							if (rx == fx1 && ry == fy1) {
								score = score++;
								if (score == 1){
									back = 'O';
									fx1 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx1 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx1 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx1 = 9000;
								}

							}
							if (rx == fx2 && ry == fy2){
								score = score++;
								if (score == 1){
									back = 'O';
									fx2 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx2 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx2 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx2 = 9000;
								}

							}
							if (rx == fx3 && ry == fy3){
								score = score++;

								if (score == 1){
									back = 'O';
									fx3 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx3 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx3 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx3 = 9000;
								}
							}
							if (score == 4 && level == 1 && play == 'm'){
								level = level++;
								mvaddch(mx, my, monster);
								play = 's';
								p = 0;
								break;
							}
							if (level == 2){
								monster = 'M';
								if (rx == mx && ry == my){
									score = score++;
								}
								if (mx > 0 && mx < 58){
									mvaddch(mx, my, ' ');
									mx = mx + 2;
									mvaddch(mx, my, monster);
									refresh();
									Sleep(20);
								}
								if (mx >= 58){
									mvaddch(mx, my, ' ');
									mx = 2;
									mvaddch(mx, my, monster);
									refresh();
									Sleep(20);
								}
							}
							if (play == 'q'){
								quit = 0;
								clear();
								draw_borders(win);
								mvaddch(xx, xy, space);
								mvaddch(ix, iy, space);
								mvaddch(hx, hy, space);
								mvaddch(gx, gy, space);
								mvaddch(fx, fy, space);
								mvaddch(mx, my, ' ');
								mvaddch(rx, ry, ' ');
								mvaddch(bx, by, ' ');
								mvaddch(cx, cy, ' ');
								mvaddch(dx, dy, ' ');
								mvaddch(ex, ey, ' ');
								mvaddch(fx0, fy0, ' ');
								mvaddch(fx1, fy1, ' ');
								mvaddch(fx2, fy2, ' ');
								mvaddch(fx3, fy3, ' ');
								rx = 40;
								ry = 30;
								bx = 40;
								by = 31;
								cx = 40;
								cy = 32;
								dx = 40;
								dy = 33;
								ex = 40;
								ey = 34;
								fx = 40;
								fy = 35;
								gx = 40;
								gy = 36;
								hx = 40;
								hy = 37;
								ix = 40;
								iy = 38;
								xx = 40;
								xy = 39;
								fx0 = 5;
								fy0 = 20;
								fx1 = 50;
								fy1 = 18;
								fx2 = 23;
								fy2 = 20;
								fx3 = 23;
								fy3 = 46;
								mx = 40;
								my = 30;
								starter = 0;
								level = 1;
								highscore = score;
								score = 0;
								back = ' ';
								tail = ' ';
								xtra1 = ' ';
								xtra2 = ' ';
								xtra3 = ' ';
								xtra4 = ' ';
								mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
								mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
								mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
								mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
								mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
								mvprintw(5, MARGIN_LEFT, "                                        |  / ");
								mvprintw(6, MARGIN_LEFT, "                                   _____| |");
								mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
								mvprintw(8, MARGIN_LEFT, "                                  |  |");
								mvprintw(9, MARGIN_LEFT, "                           _______|  |");
								mvprintw(10, MARGIN_LEFT, "                          /__________|");
								break;
							}

						}break;


					
					case 'r':
						while (1){
							if (starter == 1){
								starter = starter++;
								mvprintw(1, AW_CENTER, "                          ");
							}
							if (rx > 1 && rx < 61 && ry > 1 && ry < 81){
								mvaddch(xx, xy, space);
								xx = ix;
								xy = iy;
								ix = hx;
								iy = hy;
								hx = gx;
								hy = gy;
								gx = fx;
								gy = fy;
								fx = ex;
								fy = ey;
								ex = dx;
								ey = dy;
								dx = cx;
								dy = cy;
								cx = bx;
								cy = by;
								bx = rx;
								by = ry;
								mvaddch(ix, iy, space);
								mvaddch(hx, hy, space);
								mvaddch(gx, gy, space);
								mvaddch(fx, fy, space);
								mvaddch(rx, ry, space);
								mvaddch(bx, by, space);
								mvaddch(cx, cy, space);
								mvaddch(dx, dy, space);
								mvaddch(ex, ey, space);
								draw_borders(win);
								ry = ry--;
								rx = rx--;
								mvaddch(rx, ry, head);
								mvaddch(bx, by, torso);
								mvaddch(cx, cy, center);
								mvaddch(dx, dy, back);
								mvaddch(ex, ey, tail);
								mvaddch(ex, ey, tail);
								mvaddch(fx, fy, xtra1);
								mvaddch(gx, gy, xtra2);
								mvaddch(hx, hy, xtra3);
								mvaddch(ix, iy, xtra4);
								mvaddch(fx0, fy0, food);
								mvaddch(fx1, fy1, food);
								mvaddch(fx2, fy2, food);
								mvaddch(fx3, fy3, food);
								refresh();
								Sleep(50);
								play = getch();
								if (play == 'w' || play == 's' || play == 'd' || play == 'a' || play == 'f' || play == 't')
								{
									p = 0;
									break;
								}
							}
							if (ry <= 1)
							{
								if (rx >= 0 && rx < 30){
									mvaddch(rx, ry, ' ');
									rx = rx++;
									play = 'g';
									p = 0;
									break;
								}
								if (rx > 29 && rx <= 61){
									mvaddch(rx, ry, ' ');
									rx = rx++;
									play = 't';
									p = 0;
									break;
								}
							}
							if (rx <= 1)
							{
								if (ry >= 1 && ry < 38){
									mvaddch(rx, ry, ' ');
									ry = ry--;
									play = 'f';
									p = 0;
									break;
								}
								if (ry > 37 && ry <= 81){
									mvaddch(rx, ry, ' ');
									ry = ry--;
									play = 'f';
									p = 0;
									break;
								}
							}
							if (rx == fx0 && ry == fy0){
								score = score++;
								if (score == 1){
									back = 'O';
									fx0 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx0 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx0 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx0 = 9000;
								}

							}
							if (rx == fx1 && ry == fy1) {
								score = score++;
								if (score == 1){
									back = 'O';
									fx1 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx1 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx1 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx1 = 9000;
								}

							}
							if (rx == fx2 && ry == fy2){
								score = score++;
								if (score == 1){
									back = 'O';
									fx2 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx2 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx2 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx2 = 9000;
								}

							}
							if (rx == fx3 && ry == fy3){
								score = score++;

								if (score == 1){
									back = 'O';
									fx3 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx3 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx3 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx3 = 9000;
								}
							}
							if (score == 4 && level == 1 && play == 'm'){
								level = level++;
								mvaddch(mx, my, monster);
								play = 'r';
								p = 0;
								break;
							}
							if (level == 2){
								monster = ' ';
								mvaddch(mx, my, monster);
								if (rx == mx && ry == my){
									score = score++;
								}
							}
							if (play == 'q'){
								quit = 0;
								clear();
								draw_borders(win);
								mvaddch(xx, xy, space);
								mvaddch(ix, iy, space);
								mvaddch(hx, hy, space);
								mvaddch(gx, gy, space);
								mvaddch(fx, fy, space);
								mvaddch(mx, my, ' ');
								mvaddch(rx, ry, ' ');
								mvaddch(bx, by, ' ');
								mvaddch(cx, cy, ' ');
								mvaddch(dx, dy, ' ');
								mvaddch(ex, ey, ' ');
								mvaddch(fx0, fy0, ' ');
								mvaddch(fx1, fy1, ' ');
								mvaddch(fx2, fy2, ' ');
								mvaddch(fx3, fy3, ' ');
								rx = 40;
								ry = 30;
								bx = 40;
								by = 31;
								cx = 40;
								cy = 32;
								dx = 40;
								dy = 33;
								ex = 40;
								ey = 34;
								fx = 40;
								fy = 35;
								gx = 40;
								gy = 36;
								hx = 40;
								hy = 37;
								ix = 40;
								iy = 38;
								xx = 40;
								xy = 39;
								fx0 = 5;
								fy0 = 20;
								fx1 = 50;
								fy1 = 18;
								fx2 = 23;
								fy2 = 20;
								fx3 = 23;
								fy3 = 46;
								mx = 40;
								my = 30;
								starter = 0;
								level = 1;
								highscore = score;
								score = 0;
								monster = 'M';
								back = ' ';
								tail = ' ';
								xtra1 = ' ';
								xtra2 = ' ';
								xtra3 = ' ';
								xtra4 = ' ';
								mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
								mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
								mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
								mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
								mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
								mvprintw(5, MARGIN_LEFT, "                                        |  / ");
								mvprintw(6, MARGIN_LEFT, "                                   _____| |");
								mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
								mvprintw(8, MARGIN_LEFT, "                                  |  |");
								mvprintw(9, MARGIN_LEFT, "                           _______|  |");
								mvprintw(10, MARGIN_LEFT, "                          /__________|");
								break;
							}

						}break;
						case 'g':
							while (1){
								if (starter == 1){
									starter = starter++;
									mvprintw(1, AW_CENTER, "                          ");
								}
								if (rx > 0 && rx < 58 && ry > 0 && ry < 78)
								{
									mvaddch(xx, xy, space);
									xx = ix;
									xy = iy;
									ix = hx;
									iy = hy;
									hx = gx;
									hy = gy;
									gx = fx;
									gy = fy;
									fx = ex;
									fy = ey;
									ex = dx;
									ey = dy;
									dx = cx;
									dy = cy;
									cx = bx;
									cy = by;
									bx = rx;
									by = ry;
									mvaddch(ix, iy, space);
									mvaddch(hx, hy, space);
									mvaddch(gx, gy, space);
									mvaddch(fx, fy, space);
									mvaddch(rx, ry, space);
									mvaddch(bx, by, space);
									mvaddch(cx, cy, space);
									mvaddch(dx, dy, space);
									mvaddch(ex, ey, space);
									draw_borders(win);
									rx = rx++;
									ry = ry++;
									mvaddch(rx, ry, head);
									mvaddch(bx, by, torso);
									mvaddch(cx, cy, center);
									mvaddch(dx, dy, back);
									mvaddch(ex, ey, tail);
									mvaddch(ex, ey, tail);
									mvaddch(fx, fy, xtra1);
									mvaddch(gx, gy, xtra2);
									mvaddch(hx, hy, xtra3);
									mvaddch(ix, iy, xtra4);
									mvaddch(fx0, fy0, food);
									mvaddch(fx1, fy1, food);
									mvaddch(fx2, fy2, food);
									mvaddch(fx3, fy3, food);
									refresh();
									Sleep(50);

									play = getch();
									if (play == 'a' || play == 'd' || play == 'w' || play == 's'|| play == 'f' || play == 't')
									{
										p = 0;
										break;
									}
								}
								if (rx >= 58)
								{
									if (ry >= 1 && ry < 38){
										mvaddch(rx, ry, ' ');
										ry = ry++;
										play = 't';
										p = 0;
										break;
									}
									if (ry > 37 && ry <= 81){
										mvaddch(rx, ry, ' ');
										ry = ry++;
										play = 't';
										p = 0;
										break;
									}
								}
							if (ry >= 78)
							{
							if (rx >= 0 && rx < 30){
								mvaddch(rx, ry, ' ');
								rx = rx++;
								play = 'f';
								p = 0;
								break;
							}
							if (rx > 29 && rx <= 61){
								mvaddch(rx, ry, ' ');
								rx = rx--;
								play = 'r';
								p = 0;
								break;
							}
						}
							if (rx == fx0 && ry == fy0){
								score = score++;
								if (score == 1){
									back = 'O';
									fx0 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx0 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx0 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx0 = 9000;
								}

							}
							if (rx == fx1 && ry == fy1) {
								score = score++;
								if (score == 1){
									back = 'O';
									fx1 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx1 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx1 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx1 = 9000;
								}

							}
							if (rx == fx2 && ry == fy2){
								score = score++;
								if (score == 1){
									back = 'O';
									fx2 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx2 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx2 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx2 = 9000;
								}

							}
							if (rx == fx3 && ry == fy3){
								score = score++;

								if (score == 1){
									back = 'O';
									fx3 = 9000;
								}
								if (score == 2){
									tail = 'O';
									fx3 = 9000;
								}
								if (score == 3){
									xtra1 = 'O';
									fx3 = 9000;
								}
								if (score == 4){
									xtra2 = 'O';
									fx3 = 9000;
								}
							}
							if (score == 4 && level == 1 && play == 'm'){
								level = level++;
								mvaddch(mx, my, monster);
								play = 'g';
								p = 0;
								break;
							}
							if (level == 2){
								monster = ' ';
								mvaddch(mx, my, monster);
								if (rx == mx && ry == my){
									score = score++;
								}
							}
								if (play == 'q'){
									quit = 0;
									clear();
									draw_borders(win);
									mvaddch(xx, xy, space);
									mvaddch(ix, iy, space);
									mvaddch(hx, hy, space);
									mvaddch(gx, gy, space);
									mvaddch(fx, fy, space);
									mvaddch(mx, my, ' ');
									mvaddch(rx, ry, ' ');
									mvaddch(bx, by, ' ');
									mvaddch(cx, cy, ' ');
									mvaddch(dx, dy, ' ');
									mvaddch(ex, ey, ' ');
									mvaddch(fx0, fy0, ' ');
									mvaddch(fx1, fy1, ' ');
									mvaddch(fx2, fy2, ' ');
									mvaddch(fx3, fy3, ' ');
									rx = 40;
									ry = 30;
									bx = 40;
									by = 31;
									cx = 40;
									cy = 32;
									dx = 40;
									dy = 33;
									ex = 40;
									ey = 34;
									fx = 40;
									fy = 35;
									gx = 40;
									gy = 36;
									hx = 40;
									hy = 37;
									ix = 40;
									iy = 38;
									xx = 40;
									xy = 39;
									fx0 = 5;
									fy0 = 20;
									fx1 = 50;
									fy1 = 18;
									fx2 = 23;
									fy2 = 20;
									fx3 = 23;
									fy3 = 46;
									mx = 40;
									my = 30;
									starter = 0;
									level = 1;
									highscore = score;
									score = 0;
									monster = 'M';
									back = ' ';
									tail = ' ';
									xtra1 = ' ';
									xtra2 = ' ';
									xtra3 = ' ';
									xtra4 = ' ';
									mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
									mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
									mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
									mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
									mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
									mvprintw(5, MARGIN_LEFT, "                                        |  / ");
									mvprintw(6, MARGIN_LEFT, "                                   _____| |");
									mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
									mvprintw(8, MARGIN_LEFT, "                                  |  |");
									mvprintw(9, MARGIN_LEFT, "                           _______|  |");
									mvprintw(10, MARGIN_LEFT, "                          /__________|");
									break;
								}
							}break;

							case 't':
								while (1){
									if (starter == 1){
										starter = starter++;
										mvprintw(1, AW_CENTER, "                          ");
									}
									if (ry > 0 && ry < 78 && rx > 1 && rx < 61){
										mvaddch(xx, xy, space);
										xx = ix;
										xy = iy;
										ix = hx;
										iy = hy;
										hx = gx;
										hy = gy;
										gx = fx;
										gy = fy;
										fx = ex;
										fy = ey;
										ex = dx;
										ey = dy;
										dx = cx;
										dy = cy;
										cx = bx;
										cy = by;
										bx = rx;
										by = ry;
										mvaddch(ix, iy, space);
										mvaddch(hx, hy, space);
										mvaddch(gx, gy, space);
										mvaddch(fx, fy, space);
										mvaddch(rx, ry, space);
										mvaddch(bx, by, space);
										mvaddch(cx, cy, space);
										mvaddch(dx, dy, space);
										mvaddch(ex, ey, space);
										draw_borders(win);
										ry = ry++;
										rx = rx--;
										mvaddch(rx, ry, head);
										mvaddch(bx, by, torso);
										mvaddch(cx, cy, center);
										mvaddch(dx, dy, back);
										mvaddch(ex, ey, tail);
										mvaddch(ex, ey, tail);
										mvaddch(fx, fy, xtra1);
										mvaddch(gx, gy, xtra2);
										mvaddch(hx, hy, xtra3);
										mvaddch(ix, iy, xtra4);
										mvaddch(fx0, fy0, food);
										mvaddch(fx1, fy1, food);
										mvaddch(fx2, fy2, food);
										mvaddch(fx3, fy3, food);
										refresh();
										Sleep(50);
										play = getch();
										if (play == 'w' || play == 's' || play == 'd' || play == 'a' || play == 'r' || play == 'g')
										{
											p = 0;
											break;
										}
									}
									if (ry >= 78)
									{
										if (rx >= 0 && rx < 30){
											mvaddch(rx, ry, ' ');
											rx = rx++;
											play = 'f';
											p = 0;
											break;
										}
										if (rx > 29 && rx <= 61){
											mvaddch(rx, ry, ' ');
											rx = rx--;
											play = 'r';
											p = 0;
											break;
										}
									}
									if (rx <= 1)
									{
										if (ry >= 1 && ry < 38){
											mvaddch(rx, ry, ' ');
											ry = ry++;
											play = 'g';
											p = 0;
											break;
										}
										if (ry > 37 && ry <= 81){
											mvaddch(rx, ry, ' ');
											ry = ry--;
											play = 'g';
											p = 0;
											break;
										}
									}
									if (rx == fx0 && ry == fy0){
										score = score++;
										if (score == 1){
											back = 'O';
											fx0 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx0 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx0 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx0 = 9000;
										}

									}
									if (rx == fx1 && ry == fy1) {
										score = score++;
										if (score == 1){
											back = 'O';
											fx1 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx1 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx1 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx1 = 9000;
										}

									}
									if (rx == fx2 && ry == fy2){
										score = score++;
										if (score == 1){
											back = 'O';
											fx2 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx2 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx2 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx2 = 9000;
										}

									}
									if (rx == fx3 && ry == fy3){
										score = score++;

										if (score == 1){
											back = 'O';
											fx3 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx3 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx3 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx3 = 9000;
										}
									}
									if (score == 4 && level == 1 && play == 'm'){
										level = level++;
										mvaddch(mx, my, monster);
										play = 't';
										p = 0;
										break;
									}
									if (level == 2){
										monster = ' ';
										mvaddch(mx, my, monster);
										if (rx == mx && ry == my){
											score = score++;
										}
									}
									if (play == 'q'){
										quit = 0;
										clear();
										draw_borders(win);
										mvaddch(xx, xy, space);
										mvaddch(ix, iy, space);
										mvaddch(hx, hy, space);
										mvaddch(gx, gy, space);
										mvaddch(fx, fy, space);
										mvaddch(mx, my, ' ');
										mvaddch(rx, ry, ' ');
										mvaddch(bx, by, ' ');
										mvaddch(cx, cy, ' ');
										mvaddch(dx, dy, ' ');
										mvaddch(ex, ey, ' ');
										mvaddch(fx0, fy0, ' ');
										mvaddch(fx1, fy1, ' ');
										mvaddch(fx2, fy2, ' ');
										mvaddch(fx3, fy3, ' ');
										rx = 40;
										ry = 30;
										bx = 40;
										by = 31;
										cx = 40;
										cy = 32;
										dx = 40;
										dy = 33;
										ex = 40;
										ey = 34;
										fx = 40;
										fy = 35;
										gx = 40;
										gy = 36;
										hx = 40;
										hy = 37;
										ix = 40;
										iy = 38;
										xx = 40;
										xy = 39;
										fx0 = 5;
										fy0 = 20;
										fx1 = 50;
										fy1 = 18;
										fx2 = 23;
										fy2 = 20;
										fx3 = 23;
										fy3 = 46;
										mx = 40;
										my = 30;
										starter = 0;
										level = 1;
										highscore = score;
										score = 0;
										monster = 'M';
										back = ' ';
										tail = ' ';
										xtra1 = ' ';
										xtra2 = ' ';
										xtra3 = ' ';
										xtra4 = ' ';
										mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
										mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
										mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
										mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
										mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
										mvprintw(5, MARGIN_LEFT, "                                        |  / ");
										mvprintw(6, MARGIN_LEFT, "                                   _____| |");
										mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
										mvprintw(8, MARGIN_LEFT, "                                  |  |");
										mvprintw(9, MARGIN_LEFT, "                           _______|  |");
										mvprintw(10, MARGIN_LEFT, "                          /__________|");
										break;
									}
								}break;

							case 'f':
								while (1){
									if (starter == 1){
										starter = starter++;
										mvprintw(1, AW_CENTER, "                          ");
									}
									if (rx > 0 && rx < 58 && ry > 1 && ry < 81)
									{
										mvaddch(xx, xy, space);
										xx = ix;
										xy = iy;
										ix = hx;
										iy = hy;
										hx = gx;
										hy = gy;
										gx = fx;
										gy = fy;
										fx = ex;
										fy = ey;
										ex = dx;
										ey = dy;
										dx = cx;
										dy = cy;
										cx = bx;
										cy = by;
										bx = rx;
										by = ry;
										mvaddch(ix, iy, space);
										mvaddch(hx, hy, space);
										mvaddch(gx, gy, space);
										mvaddch(fx, fy, space);
										mvaddch(rx, ry, space);
										mvaddch(bx, by, space);
										mvaddch(cx, cy, space);
										mvaddch(dx, dy, space);
										mvaddch(ex, ey, space);
										draw_borders(win);
										rx = rx++;
										ry = ry--;
										mvaddch(rx, ry, head);
										mvaddch(bx, by, torso);
										mvaddch(cx, cy, center);
										mvaddch(dx, dy, back);
										mvaddch(ex, ey, tail);
										mvaddch(ex, ey, tail);
										mvaddch(fx, fy, xtra1);
										mvaddch(gx, gy, xtra2);
										mvaddch(hx, hy, xtra3);
										mvaddch(ix, iy, xtra4);
										mvaddch(fx0, fy0, food);
										mvaddch(fx1, fy1, food);
										mvaddch(fx2, fy2, food);
										mvaddch(fx3, fy3, food);
										refresh();
										Sleep(50);
										play = getch();
										if (play == 'a' || play == 'd' || play == 'w' || play == 's'|| play == 'r' || play == 'g')
										{
											p = 0;
											break;
										}
									}
									if (rx >= 58)
									{
										if (ry >= 1 && ry < 38){
											mvaddch(rx, ry, ' ');
											ry = ry++;
											play = 't';
											p = 0;
											break;
										}
										if (ry > 37 && ry <= 81){
											mvaddch(rx, ry, ' ');
											ry = ry--;
											play = 'r';
											p = 0;
											break;
										}
									}
									if (ry <= 1)
									{
										if (rx >= 0 && rx < 30){
											mvaddch(rx, ry, ' ');
											rx = rx++;
											play = 'g';
											p = 0;
											break;
										}
										if (rx > 29 && rx <= 61){
											mvaddch(rx, ry, ' ');
											rx = rx--;
											play = 't';
											p = 0;
											break;
										}
									}
									if (rx == fx0 && ry == fy0){
										score = score++;
										if (score == 1){
											back = 'O';
											fx0 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx0 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx0 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx0 = 9000;
										}

									}
									if (rx == fx1 && ry == fy1) {
										score = score++;
										if (score == 1){
											back = 'O';
											fx1 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx1 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx1 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx1 = 9000;
										}

									}
									if (rx == fx2 && ry == fy2){
										score = score++;
										if (score == 1){
											back = 'O';
											fx2 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx2 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx2 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx2 = 9000;
										}

									}
									if (rx == fx3 && ry == fy3){
										score = score++;

										if (score == 1){
											back = 'O';
											fx3 = 9000;
										}
										if (score == 2){
											tail = 'O';
											fx3 = 9000;
										}
										if (score == 3){
											xtra1 = 'O';
											fx3 = 9000;
										}
										if (score == 4){
											xtra2 = 'O';
											fx3 = 9000;
										}
									}
									if (score == 4 && level == 1 && play == 'm'){
										level = level++;
										mvaddch(mx, my, monster);
										play = 'f';
										p = 0;
										break;
									}
									if (level == 2){
										monster = ' ';
										mvaddch(mx, my, monster);
										if (rx == mx && ry == my){
											score = score++;
										}
									}
									if (play == 'q'){
										quit = 0;
										clear();
										draw_borders(win);
										mvaddch(xx, xy, space);
										mvaddch(ix, iy, space);
										mvaddch(hx, hy, space);
										mvaddch(gx, gy, space);
										mvaddch(fx, fy, space);
										mvaddch(mx, my, ' ');
										mvaddch(rx, ry, ' ');
										mvaddch(bx, by, ' ');
										mvaddch(cx, cy, ' ');
										mvaddch(dx, dy, ' ');
										mvaddch(ex, ey, ' ');
										mvaddch(fx0, fy0, ' ');
										mvaddch(fx1, fy1, ' ');
										mvaddch(fx2, fy2, ' ');
										mvaddch(fx3, fy3, ' ');
										rx = 40;
										ry = 30;
										bx = 40;
										by = 31;
										cx = 40;
										cy = 32;
										dx = 40;
										dy = 33;
										ex = 40;
										ey = 34;
										fx = 40;
										fy = 35;
										gx = 40;
										gy = 36;
										hx = 40;
										hy = 37;
										ix = 40;
										iy = 38;
										xx = 40;
										xy = 39;
										fx0 = 5;
										fy0 = 20;
										fx1 = 50;
										fy1 = 18;
										fx2 = 23;
										fy2 = 20;
										fx3 = 23;
										fy3 = 46;
										mx = 40;
										my = 30;
										starter = 0;
										level = 1;
										highscore = score;
										score = 0;
										monster = 'M';
										back = ' ';
										tail = ' ';
										xtra1 = ' ';
										xtra2 = ' ';
										xtra3 = ' ';
										xtra4 = ' ';
										mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
										mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
										mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
										mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
										mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
										mvprintw(5, MARGIN_LEFT, "                                        |  / ");
										mvprintw(6, MARGIN_LEFT, "                                   _____| |");
										mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
										mvprintw(8, MARGIN_LEFT, "                                  |  |");
										mvprintw(9, MARGIN_LEFT, "                           _______|  |");
										mvprintw(10, MARGIN_LEFT, "                          /__________|");
										break;
									}
								}break;

				default:
					while (1)
					{
						if (ry > 1 && ry < 81){
							mvaddch(xx, xy, space);
							xx = ix;
							xy = iy;
							ix = hx;
							iy = hy;
							hx = gx;
							hy = gy;
							gx = fx;
							gy = fy;
							fx = ex;
							fy = ey;
							ex = dx;
							ey = dy;
							dx = cx;
							dy = cy;
							cx = bx;
							cy = by;
							bx = rx;
							by = ry;
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(rx, ry, space);
							mvaddch(bx, by, space);
							mvaddch(cx, cy, space);
							mvaddch(dx, dy, space);
							mvaddch(ex, ey, space);
							draw_borders(win);
							ry = ry--;
							mvaddch(rx, ry, head);
							mvaddch(bx, by, torso);
							mvaddch(cx, cy, center);
							mvaddch(dx, dy, back);
							mvaddch(ex, ey, tail);
							mvaddch(ex, ey, tail);
							mvaddch(fx, fy, xtra1);
							mvaddch(gx, gy, xtra2);
							mvaddch(hx, hy, xtra3);
							mvaddch(ix, iy, xtra4);
							mvaddch(fx0, fy0, food);
							mvaddch(fx1, fy1, food);
							mvaddch(fx2, fy2, food);
							mvaddch(fx3, fy3, food);
							refresh();
							Sleep(50);
							play = getch();
							if (play == 'd'){
								if (rx >= 0 && rx < 30){
									mvaddch(rx, ry, ' ');
									rx = rx++;
									p = 0;
									break;
								}
								if (rx > 29 && rx <= 61){
									mvaddch(rx, ry, ' ');
									rx = rx--;
									p = 0;
									break;
								}
							}
							if (play == 'w' || play == 's'|| play == 'r' || play == 'g' || play == 'f' || play == 't' )
							{
								p = 0;
								break;
							}

						}
						if (ry == 1)
						{
							if (rx > 0 && rx < 30){
								mvaddch(rx, ry, ' ');
								rx = rx++;
								play = 'g';
								p = 0;
								break;
							}
							if (rx > 29 && rx < 61){
								mvaddch(rx, ry, ' ');
								rx = rx--;
								play = 't';
								p = 0;
								break;
							}
						}
						if (rx == fx0 && ry == fy0){
							score = score++;
							if (score == 1){
								back = 'O';
								fx0 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx0 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx0 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx0 = 9000;
							}

						}
						if (rx == fx1 && ry == fy1) {
							score = score++;
							if (score == 1){
								back = 'O';
								fx1 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx1 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx1 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx1 = 9000;
							}

						}
						if (rx == fx2 && ry == fy2){
							score = score++;
							if (score == 1){
								back = 'O';
								fx2 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx2 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx2 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx2 = 9000;
							}

						}
						if (rx == fx3 && ry == fy3){
							score = score++;

							if (score == 1){
								back = 'O';
								fx3 = 9000;
							}
							if (score == 2){
								tail = 'O';
								fx3 = 9000;
							}
							if (score == 3){
								xtra1 = 'O';
								fx3 = 9000;
							}
							if (score == 4){
								xtra2 = 'O';
								fx3 = 9000;
							}
						}
						if (score == 4 && level == 1 && play == 'm'){
							level = level++;
							mvaddch(mx, my, monster);
							play = 'a';
							p = 0;
							break;
						}
						if (level == 2){
							monster = 'M';
							if (rx == mx && ry == my){
								score = score++;
							}
							if (my > 1 && my < 81){
								mvaddch(mx, my, ' ');
								my = my - 2;
								mvaddch(mx, my, monster);
								refresh();
								Sleep(20);
							}
							if (my <= 1){
								mvaddch(mx, my, ' ');
								my = 78;
								mvaddch(mx, my, monster);
								refresh();
								Sleep(20);
							}
						}
						if (starter == 0){
							starter = starter++;
							mvprintw(1, AW_CENTER, "Eat some food '+' to grow.");
							
						}
						if (play == 'q'){
							quit = 0;
							clear();
							draw_borders(win);
							mvaddch(xx, xy, space);
							mvaddch(ix, iy, space);
							mvaddch(hx, hy, space);
							mvaddch(gx, gy, space);
							mvaddch(fx, fy, space);
							mvaddch(mx, my, ' ');
							mvaddch(rx, ry, ' ');
							mvaddch(bx, by, ' ');
							mvaddch(cx, cy, ' ');
							mvaddch(dx, dy, ' ');
							mvaddch(ex, ey, ' ');
							mvaddch(fx0, fy0, ' ');
							mvaddch(fx1, fy1, ' ');
							mvaddch(fx2, fy2, ' ');
							mvaddch(fx3, fy3, ' ');
							rx = 40;
							ry = 30;
							bx = 40;
							by = 31;
							cx = 40;
							cy = 32;
							dx = 40;
							dy = 33;
							ex = 40;
							ey = 34;
							fx = 40;
							fy = 35;
							gx = 40;
							gy = 36;
							hx = 40;
							hy = 37;
							ix = 40;
							iy = 38;
							xx = 40;
							xy = 39;
							fx0 = 5;
							fy0 = 20;
							fx1 = 50;
							fy1 = 18;
							fx2 = 23;
							fy2 = 20;
							fx3 = 23;
							fy3 = 46;
							mx = 40;
							my = 30;
							starter = 0;
							level = 1;
							highscore = score;
							score = 0;
							back = ' ';
							tail = ' ';
							xtra1 = ' ';
							xtra2 = ' ';
							xtra3 = ' ';
							xtra4 = ' ';
							mvprintw(2, AW_CENTER, "Welcome %s, to the Snake Game!\n", mystr);
							mvprintw(1, MARGIN_RIGHT, "Highscore: %d", highscore);
							mvprintw(AW_CENTER, AW_CENTER, "press 'p' to play.");
							mvprintw(3, MARGIN_LEFT, "                                        * *___   ");
							mvprintw(4, MARGIN_LEFT, "                                        |    ___|");
							mvprintw(5, MARGIN_LEFT, "                                        |  / ");
							mvprintw(6, MARGIN_LEFT, "                                   _____| |");
							mvprintw(7, MARGIN_LEFT, "                                  |   ____|");
							mvprintw(8, MARGIN_LEFT, "                                  |  |");
							mvprintw(9, MARGIN_LEFT, "                           _______|  |");
							mvprintw(10, MARGIN_LEFT, "                          /__________|");
							break;
						}
					}
					break;
				}
			}
			
			if (input_ch == 'q'){
				endwin();
				break;
			}
		}
		}
		//This is used to refresh the window after you update things...
		//refresh();

		//Wait a bit
		//sleep_crossPlatform(50);

		mvprintw(AW_CENTER, AW_CENTER, "%s", "Press Q to exit");

		//Wait until the user presses 'q'
		while (getch() != 'q');

		//Close out the window
		endwin();

		//End
		return 0;
	
}

//Curses library window setup
WINDOW* SetupWindows(void){

    //Local declarations
    WINDOW* win = NULL;

    //Initialize the screen
    win = initscr();
    nodelay(win, TRUE);
    noecho();
    curs_set(FALSE);

    return win;
}

//Function to provide cross platform sleep functionality.
void sleep_crossPlatform(int sleepMs){

//If in unix, use usleep.
#ifdef UNIX
	usleep(sleepMs * 1000);
#endif

//If in windows, use Sleep.
#ifdef WINDOWS
	Sleep(sleepMs);
#endif

}

// Create Border
void draw_borders(WINDOW *screen) {
	int x, y, i;
	getmaxyx(screen, y, x);
	// 4 corners
	mvwprintw(screen, 0, 0, "|");
	mvwprintw(screen, y - 1, 0, "|");
	mvwprintw(screen, 0, x - 1, "|");
	mvwprintw(screen, y - 1, x - 1, "|");
	// sides
	for (i = 1; i < (y - 1); i++) {
		mvwprintw(screen, i, 0, "|");
		mvwprintw(screen, i, x - 1, "|");
	}
	// top and bottom
	for (i = 1; i < (x - 1); i++) {
		mvwprintw(screen, 0, i, "-");
		mvwprintw(screen, y - 1, i, "-");
	}
}

//Function to automatically resize the window to a certain number of rows and columns
void resizeWindow_crossPlatform(int rows, int cols){

#ifdef UNIX

	//NOTE - this seems to work on Debian based systems, but may not be extremely portable.  
	// Your mileage may vary.

	//Local declarations
	char tempStr[1000];
	int rowPix = 0;
	int colPix = 0;
	int vertPixPerChar = 16; //This number is based on the font in the terminal
	int horzPixPerChar = 8;  //As is this...  So they may need to be updated in the future.

	//Convert from characters to pixels
	rowPix = (rows + 2) * vertPixPerChar;
	colPix = (cols + 2) * horzPixPerChar;

	//Create the command to issue to resize the window. 
	// NOTE - this requires the wmctrl package be installed, and
	//  that the current window is not already maximized.
	sprintf(tempStr, "wmctrl -r :ACTIVE: -e 0,-1,-1,%d,%d", colPix, rowPix);

	//Issue the system command to resize the window.
	system(tempStr);

#endif

#ifdef WINDOWS

	//Local declarations
	char tempStr[1000];
	int err = 0;

	//Create the command string
	sprintf(tempStr, "mode con lines=%d cols=%d", rows, cols);

	//Issue the system command to resize the window
	err = system(tempStr);

#endif

}