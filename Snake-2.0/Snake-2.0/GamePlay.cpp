#include "Dh.h"
#include "Header.h"

bool eat = false;
bool gameover = false;
int score = 0;

void gamePlay() {
	Wall w;
	Snake s;
	Bait b;
	w.drawWall();
	b.randBait();
	gotoXY(0, 22); cout << "Score: " << score << endl;
	while (!gameover) {
		if (s.getSnakeHeadX() == b.getX() && s.getSnakeHeadY() == b.getY()) {
			s.addSnakePart();
			score += 10;
			b.randBait();
			gotoXY(0, 22); cout << "Score: " << score << endl;
		}
		s.moveSnake();
		if (s.getSnakeHeadX() <= 0 || s.getSnakeHeadX() > 60) gameover = true;
		if (s.getSnakeHeadY() <= 0 || s.getSnakeHeadY() > 20) gameover = true;
		if (s.eatSelf() == true) gameover = true;
		Sleep(200);
	}
}