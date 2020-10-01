#include "Dh.h"
#include "Header.h"

bool eat = false;
bool gameover = false;
int score = 0;

void gamePlay() {
	Wall w;
	w.drawWall();
	Snake s;
	Bait b;
	b.randBait();
	while (!gameover) {
		if (eat == true) {
			system("cls");
			w.drawWall();
			eat = false;
		}
		if (s.getSnakeHeadX() == b.getX() && s.getSnakeHeadY() == b.getY()) {
			score += 10;
			eat = true;
			b.randBait();
		}
		gotoXY(0, 22);
		cout << "Score: " << score << endl;
		b.performBait();
		s.performSnake();
		s.moveSnakeHead();
		if (s.getSnakeHeadX() <= 0 || s.getSnakeHeadX() > 60) gameover = true;
		if (s.getSnakeHeadY() <= 0 || s.getSnakeHeadY() > 20) gameover = true;
		Sleep(200);
	}
}