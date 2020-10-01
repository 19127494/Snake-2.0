#include "Header.h"
#include "Dh.h";

int prevX, prevY;
int prevXb, prevYb;
char previp = 'd';

void PointSnake::performPointSnake(const bool& a) {
	gotoXY(x, y);
	if (a == 1)
		cout << "O";
	else
		cout << "o";
}

void PointSnake::deletePointSnake() {
	gotoXY(x, y);
	cout << " ";
}

Snake::Snake() {
	sh.setX(30);
	sh.setY(10);
	sp_arr.resize(0);
}

void Snake::addSnakePart() {
	PointSnake ps;
	if (sp_arr.empty()) {
		ps.setX(sh.getX());
		ps.setY(sh.getY());
	}
	sp_arr.push_back(ps);
}

void Snake::moveSnakeHead() {
	prevX = sh.getX(), prevY = sh.getY();
	if (_kbhit()) {
		previp = _getch();
	}
	switch (previp)
	{
	case 'w':
		sh.setY(sh.getY() - 1);
		break;
	case 'a':
		sh.setX(sh.getX() - 1);
		break;
	case 's':
		sh.setY(sh.getY() + 1);
		break;
	case 'd':
		sh.setX(sh.getX() + 1);
		break;
	default:
		break;
	}
	gotoXY(prevX, prevY);
	cout << " ";
	sh.performPointSnake(1);
}

void Snake::moveSnake() {
	bool flag = false;
	moveSnakeHead();
	if (!sp_arr.empty())
		for (vector<PointSnake>::iterator it = sp_arr.begin(); it != sp_arr.end(); it++) {
			(*it).deletePointSnake();
			if (flag == true) {
				prevX = (*it).getX();
				prevY = (*it).getY();
				(*it).setX(prevXb);
				(*it).setY(prevYb);
				flag = false;
			}
			else {
				prevXb = (*it).getX();
				prevYb = (*it).getY();
				(*it).setX(prevX);
				(*it).setY(prevY);
				flag = true;
			}
			(*it).performPointSnake(0);
		}
}

bool Snake::eatSelf() {
	if (!sp_arr.empty())
		for (vector<PointSnake>::iterator it = sp_arr.begin(); it != sp_arr.end(); it++) {
			if ((*it).getX() == sh.getX() && (*it).getY() == sh.getY())
				return true;
		}
	return false;
}