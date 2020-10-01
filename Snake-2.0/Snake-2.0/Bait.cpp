#include "Header.h";
#include "Dh.h";

void Bait::randBait(bool fl) {
	srand(time(NULL));
	x = rand() % 60 + 1;
	y = rand() % 20 + 1;
	performBait(fl);
}

void Bait::performBait(bool fl) {
	gotoXY(x, y);
	if (!fl) {
		SetColor(15);
		cout << "M";
	}
	else
	{
		SetColor(4);
		cout << "W";
	}
}

void Bait::deleteBait() {
	gotoXY(x, y);
	cout << " ";
}