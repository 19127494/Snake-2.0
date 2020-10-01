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
	b.randBait(0);
	gotoXY(75, 2); cout << "Score: " << score;
	gotoXY(75, 3); cout << "Mode: " << mode;
	gotoXY(75, 4); cout << "Speed: " << speed/50;
	while (!gameover) {
		ShowCur(0);
		
		if (s.getSnakeHeadX() == b.getX() && s.getSnakeHeadY() == b.getY()) {
			s.addSnakePart();
			if ((score+10) % 100 == 0 && score != 0)
			{
				score += 10;
				b.randBait(1);
				gotoXY(75, 6); cout << "CAUTION !!! RED MODE IS ON !!!";
				speed -= 30;
			}
			else if(score % 100 == 0 && score!=0)
			{
				score += 20;
				b.randBait(0);
				speed += 20;
				gotoXY(75, 6); cout << "                              ";
			}
			else
			{
				score += 10;
				b.randBait(0);
			}
			gotoXY(75, 2); cout << "Score: " << score ;
		}
		
		s.moveSnake();
		
		if(mode == 1)
		{
			if (s.getSnakeHeadX() <= 0 || s.getSnakeHeadX() > 60) gameover = true;
			if (s.getSnakeHeadY() <= 0 || s.getSnakeHeadY() > 20) gameover = true;
			if (s.eatSelf() == true) gameover = true;
		}
		else if(mode == 2)
		{
			if (s.getSnakeHeadX() <= 0 || s.getSnakeHeadX() > 60) gameover = true;
			if (s.getSnakeHeadY() <= 0 || s.getSnakeHeadY() > 20) gameover = true;
			if (s.eatSelf() == true) gameover = 0;
		}
		else if(mode == 3)
		{
			if (s.getSnakeHeadX() <= 0) s.setHX(59);
			if (s.getSnakeHeadX() > 60) s.setHX(1);
			if (s.getSnakeHeadY() <= 0) s.setHY(20);
			if (s.getSnakeHeadY() > 20)  s.setHY(1);
			if (s.eatSelf() == true) gameover = true;
			w.drawWall();
		}
		
		Sleep(speed);
	}
	return gameover;
}