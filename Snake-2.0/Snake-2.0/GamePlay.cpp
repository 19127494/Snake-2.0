#include "Dh.h"
#include "Header.h"

bool eat = false;



bool gamePlay(int speed,int &score, int mode) {
	bool gameover = false;
	score = 0;
	Wall w;
	Snake s;
	Bait b;
	w.drawWall();
	b.randBait();
	gotoXY(75, 2); cout << "Score: " << score;
	gotoXY(75, 3); cout << "Mode: " << mode;
	gotoXY(75, 4); cout << "Speed: " << speed/50;
	while (!gameover) {
		if (s.getSnakeHeadX() == b.getX() && s.getSnakeHeadY() == b.getY()) {
			s.addSnakePart();
			score += 10;
			b.randBait();
			gotoXY(75, 2); cout << "Score: " << score ;
		}
		s.moveSnake();
		
		if(mode == 1)
		{
			if (s.getSnakeHeadX() <= 0 || s.getSnakeHeadX() > 70) gameover = true;
			if (s.getSnakeHeadY() <= 0 || s.getSnakeHeadY() > 20) gameover = true;
			if (s.eatSelf() == true) gameover = true;
		}
		else if(mode == 2)
		{
			if (s.getSnakeHeadX() <= 0 || s.getSnakeHeadX() > 70) gameover = true;
			if (s.getSnakeHeadY() <= 0 || s.getSnakeHeadY() > 20) gameover = true;
			if (s.eatSelf() == true) gameover = 0;
		}
		else if(mode == 3)
		{
			if (s.getSnakeHeadX() <= 0) s.setHX(69);
			if (s.getSnakeHeadX() > 70) s.setHX(1);
			if (s.getSnakeHeadY() <= 0) s.setHY(19);
			if (s.getSnakeHeadY() > 20)  s.setHY(1);
			if (s.eatSelf() == true) gameover = true;
			w.drawWall();
		}
		
		Sleep(speed);
	}
	return gameover;
}