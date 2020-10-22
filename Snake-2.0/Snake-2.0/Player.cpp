#include "Header.h"
#include "Dh.h"

int speed = 50;
int mode = 1;
void xx(int a[], char x, int t)
{

	for (int i = 0; i < 40; i++)
	{
		if (a[i])
		{
			Sleep(t);
			int cl = rand() % 20 + 1;
			SetColor(cl);
			cout << x;
		}
		else
		{
			Sleep(t);
			cout << " ";
		}
	} cout << endl;
}
void drawSnaKe()
{
	int a[50] = { 0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,1,1 };
	int b[50] = { 1,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0 };
	int c[50] = { 0,1,0,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,1,0 };
	int d[50] = { 0,0,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,0,0,0 };
	int e[50] = { 1,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0 };
	int f[50] = { 0,1,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1 };


	gotoXY(30, 1);  xx(a, 's', 10); Sleep(40);
	gotoXY(30, 2);  xx(b, 'n', 15); Sleep(50);
	gotoXY(30, 3);  xx(c, 'a', 20); Sleep(60);
	gotoXY(30, 4);  xx(d, 'k', 25); Sleep(70);
	gotoXY(30, 5);  xx(e, 'e', 30); Sleep(80);
	gotoXY(30, 6);  xx(f, 's', 20); Sleep(200); system("cls"); Sleep(80);
	gotoXY(30, 1);  xx(a, 's', 0);
	gotoXY(30, 2);  xx(b, 'n', 0);
	gotoXY(30, 3);  xx(c, 'a', 0);
	gotoXY(30, 4);  xx(d, 'k', 0);
	gotoXY(30, 5);  xx(e, 'e', 0);
	gotoXY(30, 6);  xx(f, 's', 0); Sleep(200); system("cls"); Sleep(90);
	gotoXY(30, 1);  xx(a, 's', 0);
	gotoXY(30, 2);  xx(b, 'n', 0);
	gotoXY(30, 3);  xx(c, 'a', 0);
	gotoXY(30, 4);  xx(d, 'k', 0);
	gotoXY(30, 5);  xx(e, 'e', 0);
	gotoXY(30, 6);  xx(f, 's', 0); Sleep(200);
	SetColor(15);
}
void menu()
{
	drawSnaKe();
	Sleep(300); system("cls");

	while (true)
	{
		system("cls");
		SetColor(15);
		cout << "\t\t\t\t  Move like a snake, eat like a snake! \n";
		cout << " \n\t\t\t\t\t1 to start\n";
		cout << " \t\t\t\t\t2 to use"; SetColor(4); cout << " ''HACK MODE''\n"; SetColor(15);
		cout << " \t\t\t\t\t3 to set speed\n";
		cout << " \t\t\t\t\tAnother key to exit\n\n";
		cout << " \t\t\t\t\tEnter your option: ";
		char op;
		cin >> op;
		system("cls");
		if (op == '1')
		{
			int score = 0;
			bool over = gamePlay(speed, score, mode);
			if (over)
			{
				system("cls");
				gotoXY(40, 10);
				cout << "GAME OVER!";
				gotoXY(39, 11);
				cout << "Your score: " << score;
			}
		}
		else if (op == '2')
		{
			cout << " \t\t\t\t\t\tMODE\n";
			cout << " \n\t\t\t\t\tMode 1: normal \n";
			cout << " \t\t\t\t\tMode 2: can bite body \n";
			cout << " \t\t\t\t\tMode 3: ignore wall \n\n";
			cout << " \t\t\t\t\tEnter your choice: ";
			cin >> mode;
		}
		else if (op == '3')
		{
			cout << " \nEnter 1 to 10 lv: ";
			int op2;
			cin >> op2;
			speed = op2 * 50;
		}
		else break;
		gotoXY(0, 26);
		system("pause");
	}
}