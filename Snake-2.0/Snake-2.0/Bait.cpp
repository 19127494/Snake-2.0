#include "Header.h";
#include "Dh.h";

void Bait::randBait() {
	srand(time(NULL));
	x = rand() % 60 + 1;
	y = rand() % 20 + 1;
}

void Bait::performBait() {
	gotoXY(x, y);
	cout << "M";
}

void Bait::deleteBait() {
	gotoXY(x, y);
	cout << " ";
}