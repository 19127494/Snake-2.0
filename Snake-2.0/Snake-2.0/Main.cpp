#include "Header.h"
#include "Dh.h"
int speed = 50;
int mode = 1;
void menu()
{
	while (true)
	{
		system("cls");
		cout << " 0 to start\n";
		cout << " 1 to choose map\n";
		cout << " 2 to set speed\n";
		cout << " Another key to exit\n\n";
		cout << " Enter your option: ";
		char op;
		cin >> op;
		system("cls");
		if(op=='0')
		{
			int score = 0;
			bool over = gamePlay(speed,score,mode);
			if(over)
			{
				system("cls");
				gotoXY(40, 10);
				cout << "GAME OVER!";
				gotoXY(39, 11);
				cout << "Your score: " << score;
			}
		}
		else if(op=='1')
		{
			cout << " Mode 1: normal \n";
			cout << " Mode 2: can bite body \n";
			cout << " Mode 3: ignore wall \n\n";
			cout << " Enter your choice: ";
			cin >> mode;
		}
		else if (op == '2')
		{
				cout << " Enter 1 to 10 lv: ";
				int op2;
				cin >> op2;
				speed = op2 * 50;
		}
		else break;
		gotoXY(0, 26);
		system("pause");
	}
}
int main()
{
	//gamePlay(200);
	menu();
	
	gotoXY(0, 25);
	cout<<endl;
	
	return 0;
}