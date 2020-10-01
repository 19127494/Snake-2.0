#include "Header.h"
#include "Dh.h";

void P_Snake::move()
{
	while (true)
	{
		gotoXY(x, y);
		if (whereY() < 1 || whereY() > 19)break;
		int key = _getch();

		int x1 = x;
		int y1 = y;

		if(key == 119)
		{
			y1--;
			gotoXY(x1, y1);
			cout << "0";
			gotoXY(x, y);
			cout << " ";
			y = y1;
		}
		if(key == 115)
		{
			y1++;
			gotoXY(x1, y1);
			cout << "0";
			gotoXY(x, y);
			cout << " ";
			y = y1;
		}
		if (key == 97)
		{
			x1--;
			gotoXY(x1, y1);
			cout << "0";
			gotoXY(x, y);
			cout << " ";
			x = x1;;
		}
		if (key == 100)
		{
			x1++;
			gotoXY(x1, y1);
			cout << "0";
			gotoXY(x, y);
			cout << " ";
			x = x1;
		}
	}
}

