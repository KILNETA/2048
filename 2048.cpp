#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int Score =  0 ;
int number[4][4] = {0};
int add=0;
int step = 0;

void Give_number();
void Map_Main();
void Up();
void Down();
void Right();
void Left();

int main()
{
	Give_number();//�H���o��
	Map_Main();
	bool validInput = true;
	while (validInput) // ����C���}�l
	{
		int button = 0;

		while (1) // Ū�����a���� // ����ާ@ 
		{
			button = _getch();// Ū�����a���� 
			if (button != 0)
			{
				break;
			}
		} // Ū�����a���� 
		system("cls"); // �M��
		switch (button) // �P�_���a�����J�����G 
		{
		case 119: //�� W 
			Up();
			step++;
			Give_number();
			break;

		case 115: //�� S 
			Down();
			step++;
			Give_number();
			break;

		case 97:   //�� A 
			Left();
			step++;
			Give_number();
			break;

		case 100: //�� D 
			Right();
			step++;
			Give_number();
			break;

		case 27: //���a�����C�� 
			cout << endl;
			cout << "                                        �U���A�Ӫ��� �t�t" << endl << endl;
			validInput = false;
			break;

		default: //�L���� 
			break;
		}
		Map_Main();
		add = 0;
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if(number[y][x]==2048){cout << "You are winner"; validInput = false;}
			}
		}
	}
}
/*============================================================ �o�ƨ禡*/
void Give_number()
{
	int array[16] = { 0 };
	int num = 0;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			if (number[y][x] != 0) { array[num] = 1; }
			num++;
		}
	}
	srand(time(NULL));
	while (1)
	{
		int givedata= rand() % 2;
		int num = rand() % 16;
		if (array[num] == 0)
		{
			int Y = num/4%4;
			int X = num%4;
			if (givedata) { number[Y][X] = 4; }
			else { number[Y][X] = 2; }
			break;
		}
		else
		{
			if (num < 16) { num++; }
			else { num = 0; }
		}
	}
}
/*============================================================ �a�Ϩ禡*/
void Map_Main() // �a�Ϩ禡
{
	cout << endl << "�@�@�@�@�@�@�@�@ ��������" << endl << endl;
	cout << "�@ Score : " << setw(7) << left << Score;
	cout << "+" << setw(4) << left << add;
	cout <<"�@�@�@�@step : "<< step <<endl << endl;
	cout << "�@�СССС@" << "�СССС@" << "�СССС@" << "�СССС@" << endl;
	for (int y = 0; y < 4; y++)
	{
		cout << "�U";
		for (int x = 0; x < 4; x++)
		{
			cout << "�@" << setw(4) << left << number[y][x] << "�@�U";
		}
		cout << endl;
		cout << "�@�СССС@" << "�СССС@" << "�СССС@" << "�СССС@" << endl;
	}
	cout << endl << "�@�@W�GUp�@A�GLeft�@S�GDown�@D�GRight"<<endl;
}
/*============================================================ ����禡*/
void Up() //���W��
{
	for (int X = 0; X < 4; X++)
	{
		for (int Y = 0; Y < 4; Y++)
		{
			for (int NY = Y; NY < 4; NY++)
			{
				if (number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y!=NY)
				{ number[Y][X] += number[Y][X]; number[NY][X] = 0; Score += number[Y][X]; add += number[Y][X]; break;}
				else { if (number[Y][X] == 0 && number[NY][X] != 0) 
				{ number[Y][X] = number[NY][X]; number[NY][X] = 0;  } }
			}
		}
	}
}
void Down() //���U��
{
	for (int X = 0; X < 4; X++)
	{
		for (int Y = 3; Y > 0; Y--)
		{
			for (int NY = Y; NY > -1; NY--)
			{
				if (number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY) 
				{ number[Y][X] += number[Y][X]; number[NY][X] = 0; Score += number[Y][X]; add += number[Y][X]; break; }
				else { if (number[Y][X] == 0 && number[NY][X] != 0) 
				{ number[Y][X] = number[NY][X]; number[NY][X] = 0;  } }
			}
		}
	}
}
void Left() //������
{
	for (int Y = 0; Y < 4; Y++)
	{
		for (int X = 0; X < 4; X++)
		{
			for (int NX = X; NX < 4; NX++)
			{
				if (number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX)
				{ number[Y][X] += number[Y][X]; number[Y][NX] = 0; Score += number[Y][X]; add += number[Y][X]; break; }
				else { if (number[Y][X] == 0 && number[Y][NX] != 0) 
				{ number[Y][X] = number[Y][NX]; number[Y][NX] = 0; } }
			}
		}
	}
}
void Right() //���k��
{
	for (int Y = 0; Y < 4; Y++)
	{
		for (int X = 3; X > 0; X--)
		{
			for (int NX = X; NX > -1; NX--)
			{
				if (number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX)
				{ number[Y][X] += number[Y][X]; number[Y][NX] = 0; Score+= number[Y][X]; add += number[Y][X]; break; }
				else { if (number[Y][X] == 0 && number[Y][NX] != 0) 
				{ number[Y][X] = number[Y][NX]; number[Y][NX] = 0;  } }
			}
		}
	}
}

