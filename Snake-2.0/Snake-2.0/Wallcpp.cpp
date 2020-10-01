#include "Header.h"
#include "Dh.h";

Wall::Wall()
{
	width = 60;
	height = 20;
}
Wall::Wall(int W, int H)
{
	width = W;
	height = H;
}
void Wall::drawWall()
{
	for (int i = 1; i <= width; i++)
	{
		gotoXY(i, 0);
		cout << "-";
		gotoXY(i, height + 1);
		cout << "-";
	}
	for (int i = 1; i <= height; i++)
	{
		gotoXY(0, i);
		cout << "|";
		gotoXY(width + 1, i);
		cout << "|";
	}
}