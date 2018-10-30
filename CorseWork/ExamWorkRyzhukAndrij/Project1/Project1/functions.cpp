#include "Header.h"

const int field_size = 10;
#define n field_size 
bool field0[n][n];
char field[n][n];


void minusfield(char z = '*')
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			field[i][j] = z;
			field0[i][j] = 0;
		}
	}
}

void plusmine(int count)
{
	srand(time(0));
	for (int i = 0; i < count;)
	{
		int x,y;
		x = rand() % n;
		y = rand() % n;

		if (!field0[x][y])
		{
			field0[x][y] = 1;
			i++;
		}
		
	}
}

void showfield()
{   
	
		
		for (int i = 0; i < n; i++)
			cout << i << " ";
		cout << "\n ____________________\n";
		for (int i = 0; i < n; i++) {
		
			cout << (char)(i + 65) << ' ';
			for (int j = 0; j < n; j++) {
			cout << field[i][j] << " ";
		}
		cout << endl;
	}

}

bool boom(int x, int y)
{
	int count = 0;
	if (field0[x][y])
		return false;

	for (int i = x - 1; i <= x + 1 && i < n; i++) {
		for (int j = y - 1; j <= y + 1 && j < n; j++) {
			if (i >= 0 && j >= 0)
				count += field0[i][j];
		}
	}
	field[x][y] = count + 0x30; // 0x30 - код нуля в т. ASCII
	return true;
	
}

void saper()
{
mitka:
	system("cls");
	system("color 70");
	minusfield();

	cout << "Enter count of mines - 5[easy] 7[hard] 10[ultra-hard] or [your num] ";
	int count;
	cin >> count;
	plusmine(count);
	char x;
	int y;
	do {
		showfield();
		cout << endl << "Make your shot please: ";
		cin >> x >> y;
		x = x - 65;
		

	} while (boom(x, y));

	cout << "Good Game Well Played! You lose( " << endl;

	unsigned short menu;
	cout << "Do you want to play 1 more game? YES[1] NO[0] : ";
	cin >> menu;

	if (menu == 1)
		goto mitka;
	
	
	
	

}