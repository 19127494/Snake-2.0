#include "Header.h"
#include "Dh.h";

char previp = 'd';

void PointSnake::performPointSnake(const bool& a) {
	gotoXY(x, y);
	if (a == 1)
		cout << "O";
	else
		cout << "o";
}

Snake::Snake() {
	sh.setX(30);
	sh.setY(10);
	sp_arr.resize(0);
}

Snake::~Snake() {
	/*if (!sp_arr.empty())
		for (vector<PointSnake*>::iterator it = sp_arr.begin(); it != sp_arr.end(); it++)
			if ((*it) != NULL)
				delete (*it);*/
}

void Snake::addSnakePart(PointSnake ps) {
	sp_arr.push_back(ps);
}

void Snake::performSnake()  {
	sh.performPointSnake(1);
}

void Snake::moveSnakeHead() {
	int prevX = sh.getX(), prevY = sh.getY();
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
	performSnake();
}