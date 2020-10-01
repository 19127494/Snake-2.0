#pragma once
#ifndef _HEADER_
#define _HEADER_
#include <iostream>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <ctime>
using namespace std;

void gamePlay();
class Wall
{
protected:
	int width;
	int height;
public:
	Wall();
	Wall(int W, int H);
	void drawWall();

	int getWidth() { return width; }
	int getHeight() { return height; }
};

class Point {
protected:
	int x, y;
public:
	Point() { x = y = 0; }
	Point(int x, int y) {
		setX(x);
		setY(y);
	}
	~Point() {}

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getX() { return x; }
	int getY() { return y; }
};

class Bait : public Point {
public:
	Bait() { x = y = 0; }
	Bait(int x, int y) {
		setX(x);
		setY(y);
	}
	~Bait() {}

	void randBait();
	void performBait();
	void deleteBait();
};

class PointSnake : public Point {
public:
	PointSnake() { x = y = 0; }
	PointSnake(int x, int y) {
		setX(x);
		setY(y);
	}
	~PointSnake() {}

	void performPointSnake(const bool&);
};

class Snake {
private:
	PointSnake sh;
	vector<PointSnake> sp_arr;
public:
	Snake();
	~Snake();

	void addSnakePart(PointSnake);

	int getSnakeHeadX() { return sh.getX();	}
	int getSnakeHeadY() { return sh.getY(); }
	void performSnake();
	void moveSnakeHead();
};

class P_Snake : public Point
{
public:
	P_Snake() { x = 1; y = 1; }
	void move();
};

#endif