#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream> 

using namespace std;

int Score =  0 ;
int size =  0 ;
int number[4][4] = {0};
int add=0;
int step = 0;
int fraction = 0;

int MaxScore =  0 ;
int Maxadd= 0 ;
int Maxstep = 0;
int Maxfraction = 0;

void Give_number(); //�H���o�� 2 or 4 
void Map_Main(); // �e�� 

void Up(); //�W 
void Down(); //�U 
void Right(); //�k 
void Left(); //�� 

bool ExamineW(); //�ˬdW��V���ʧ@ 
bool ExamineA(); //�ˬdA��V���ʧ@ 
bool ExamineS(); //�ˬdS��V���ʧ@ 
bool ExamineD(); //�ˬdD��V���ʧ@ 
int ExamineMaxfraction();

bool Read_SaveArchive(); // 
void Add_SaveArchive(); //
void Save_SaveArchive(); // 

int main()
{
	while(Read_SaveArchive());
	
	Give_number();//�H���o��
	Map_Main();
	
	int button = 0;
	
	bool validInput = true;
	while (validInput) // ����C���}�l
	{
		button = 0;

		while (1) // Ū�����a���� // ����ާ@ 
		{
			if (_kbhit()){
				button = _getch();// Ū�����a���� 
				if (button != 0)
				{
					break;
				}
			}
		} // Ū�����a���� 
		switch (button) // �P�_���a�����J�����G 
		{
		case 72: //�� W 
			if(-ExamineW()){break;}
			Up();
			step++;
			Give_number();
			system("cls"); // �M��
			if(MaxScore<Score||Maxadd<add||Maxstep<step){Save_SaveArchive();}
			Map_Main();
			break;

		case 80: //�� S 
			if(-ExamineS()){break;}
			Down();
			step++;
			Give_number();
			system("cls"); // �M��
			if(MaxScore<Score||Maxadd<add||Maxstep<step){Save_SaveArchive();}
			Map_Main();
			break;

		case 75:   //�� A 
			if(-ExamineA()){break;}
			Left();
			step++;
			Give_number();
			system("cls"); // �M��
			if(MaxScore<Score||Maxadd<add||Maxstep<step){Save_SaveArchive();}
			Map_Main();
			break;

		case 77: //�� D 
			if(-ExamineD()){break;}
			Right();
			step++;
			Give_number();
			system("cls"); // �M��
			if(MaxScore<Score||Maxadd<add||Maxstep<step||Maxfraction<fraction){Save_SaveArchive();}
			Map_Main();
			break;

		case 27: //���a�����C�� 
			cout << endl;
			cout << "                                        Good bye!" << endl << endl;
			validInput = false;
			break;

		default: //�L���� 
			break;
		}
		add = 0;
		
		fraction=ExamineMaxfraction();
		
		if( ExamineW() && ExamineS() && ExamineA() && ExamineD() )
		{
			cout << "�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@You are loser";
			validInput = false;
		}
		
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				if(number[y][x]==2048)
				{
					cout << "�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@You are winner";
					validInput = false;
				}
			}
		}
	}
	_sleep(30000);
	cout <<endl<< "Press any key to leave";
	while (1) // Ū�����a���� // ����ާ@ 
	{
		button = _getch();// Ū�����a���� 
		if (button != 0)
		{
			break;
		}
	} // Ū�����a���� 
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
	cout << "�@�@Record:"<< "�@�@fraction "<<Maxfraction <<endl<<endl; 
	cout << "�@ Score "<< setw(7) << left << MaxScore;
	cout << "�@+"<< setw(4) << left << Maxadd;
	cout << "�@�@�@  step "<< Maxstep <<endl<<endl;
	cout << "�@�СССС@" << "�СССС@" << "�СССС@" << "�СССС@" << endl;
	for (int y = 0; y < 4; y++)
	{
		cout << "�U";
		for (int x = 0; x < 4; x++)
		{
			if(number[y][x]==0){cout << "�@" << setw(4) << left << " " << "�@�U";}
			else{cout << "�@" << setw(4) << left << number[y][x] << "�@�U";}
		}
		cout << endl;
		cout << "�@�СССС@" << "�СССС@" << "�СССС@" << "�СССС@" << endl;
		
	}
	cout << "�@ Score : " << setw(7) << left << Score;
	cout << "+" << setw(4) << left << add;
	cout <<"�@�@�@�@step : "<< step <<endl;
	cout << endl << "�@�@�@�@�@�@Up�@���@�@�@�@�@�@�@Esc�GExit"<<endl;
	cout << endl << "�@�@�@�@Left ���@�@�� Right"<<endl;
	cout << endl << "�@�@�@�@�@�@�@�@�� Down"<<endl;
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
				if (number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y+1==NY
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y+2==NY && number[Y+1][X] == 0
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y+3==NY && number[Y+1][X] == 0&& number[Y+2][X] == 0)
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
				if (number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y-1==NY
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y-2==NY && number[Y-1][X] == 0
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y-3==NY && number[Y-1][X] == 0 && number[Y-2][X] == 0)
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
				if (number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X+1==NX
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X+2==NX && number[Y][X+1] == 0
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X+3==NX && number[Y][X+1] == 0 && number[Y][X+2] == 0)
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
				if (number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X-1==NX
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X-2==NX && number[Y][X-1] == 0
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X-3==NX && number[Y][X-1] == 0 && number[Y][X-2] == 0)
				{ number[Y][X] += number[Y][X]; number[Y][NX] = 0; Score+= number[Y][X]; add += number[Y][X]; break; }
				else { if (number[Y][X] == 0 && number[Y][NX] != 0) 
				{ number[Y][X] = number[Y][NX]; number[Y][NX] = 0;  } }
			}
		}
	}
}
bool ExamineW()
{
	for (int X = 0; X < 4; X++)
	{
		for (int Y = 0; Y < 4; Y++)
		{
			for (int NY = Y; NY < 4; NY++)
			{
				if (number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y+1==NY
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y+2==NY && number[Y+1][X] == 0
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y+3==NY && number[Y+1][X] == 0&& number[Y+2][X] == 0)
				{ return false;}
				else { if (number[Y][X] == 0 && number[NY][X] != 0) 
				{ return false;  } }
			}
		}
	}
	return true;
}
bool ExamineS()
{
	for (int X = 0; X < 4; X++)
	{
		for (int Y = 3; Y > 0; Y--)
		{
			for (int NY = Y; NY > -1; NY--)
			{
				if (number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y-1==NY
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y-2==NY && number[Y-1][X] == 0
				  ||number[Y][X] == number[NY][X] && number[Y][X] != 0 && Y != NY && Y-3==NY && number[Y-1][X] == 0 && number[Y-2][X] == 0)
				{ return false; }
				else { if (number[Y][X] == 0 && number[NY][X] != 0) 
				{ return false;  } }
			}
		}
	}
	return true;
}
bool ExamineA()
{
	for (int Y = 0; Y < 4; Y++)
	{
		for (int X = 0; X < 4; X++)
		{
			for (int NX = X; NX < 4; NX++)
			{
				if (number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X+1==NX
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X+2==NX && number[Y][X+1] == 0
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X+3==NX && number[Y][X+1] == 0 && number[Y][X+2] == 0)
				{ return false; }
				else { if (number[Y][X] == 0 && number[Y][NX] != 0) 
				{ return false; } }
			}
		}
	}
	return true;
}
bool ExamineD()
{
	for (int Y = 0; Y < 4; Y++)
	{
		for (int X = 3; X > 0; X--)
		{
			for (int NX = X; NX > -1; NX--)
			{
				if (number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X-1==NX
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X-2==NX && number[Y][X-1] == 0
				  ||number[Y][X] == number[Y][NX] && number[Y][X] != 0 && X != NX && X-3==NX && number[Y][X-1] == 0 && number[Y][X-2] == 0)
				{ return false; }
				else { if (number[Y][X] == 0 && number[Y][NX] != 0) 
				{ return false;  } }
			}
		}
	}
	return true;
}

int ExamineMaxfraction()
{
	int max=0;
	for (int Y = 0; Y < 4; Y++)
	{
		for (int X = 0; X < 4; X++)
		{
			if(number[Y][X]>max){max=number[Y][X];}
		}
	} 
	return max;
} 

bool Read_SaveArchive()
{
	int ErrorData;
	fstream file("SaveArchive.txt",ios::in | ios::binary);
	if (!file)
	{
		Add_SaveArchive();
		return true;
	}
	else
	{
		file.eof();
    	file >> MaxScore;
    	file.eof();
		file >> Maxadd;
		file.eof();
		file >> Maxstep;
		file.eof();
		file >> Maxfraction;
    	file.close(); 
		return false;
	}
}
void Add_SaveArchive()
{
    ofstream fout("SaveArchive.txt");
    fstream file;
    file.open("SaveArchive.txt", ios::out);
    
	file << "0" <<endl;
	
    file << "0" <<endl;
	
	file << "0" <<endl;
	
	file << "0" <<endl;
}

void Save_SaveArchive()
{
	fstream file;
	file.open("SaveArchive.txt", ios::out | ios::trunc);
	if (!file)
	{
		Add_SaveArchive();
	}
	
	if(MaxScore<Score){MaxScore=Score;file << Score <<endl;}
	else{file<<MaxScore<<endl;}
	
    if(Maxadd<add){Maxadd=add; file << add <<endl;}
	else{file<<Maxadd<<endl;}
	
	if(Maxstep<step){Maxstep=step; file << step <<endl;}
	else{file<<Maxstep<<endl;}
	
	if(Maxfraction<fraction){Maxfraction=fraction; file << fraction <<endl;}
	else{file<<Maxfraction<<endl;}
	
    file.close(); 
	return;
}
