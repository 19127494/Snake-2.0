#include "Dh.h"
#include "Header.h"

bool gameover = false;
int score = 0;

void gamePlay() {
	Wall w;
	Snake s;
	Bait b;
	b.randBait();
	while (!gameover) {
		system("cls");
		w.drawWall();
		if (s.getSnakeHeadX() == b.getX() && s.getSnakeHeadY() == b.getY()) {
			score += 10;
			b.randBait();
		}
		gotoXY(0, 20);
		cout << endl << endl << "Score: " << score << endl;
		b.performBait();
		s.performSnake();
		s.moveSnakeHead();
		if (s.getSnakeHeadX() <= 0 || s.getSnakeHeadX() > 60) gameover = true;
		if (s.getSnakeHeadY() <= 0 || s.getSnakeHeadY() > 20) gameover = true;
	}
}