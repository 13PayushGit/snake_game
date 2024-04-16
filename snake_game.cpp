#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool gameOver;
int FruitX, FruitY, x, y;
const int width = 20 , height = 20;
enum eDirection{STOP =0 , UP , DOWN , LEFT , RIGHT};
eDirection dir;

void setup();
void Draw();
void Input();
void Logic();

void setup()
{
	gameOver = false;
	dir = STOP;
	x = width/2;
	y = height/2;
	FruitX = rand() % width;
	FruitY = rand() % height;
}

void Draw()
{
	system("cls");
	for(int i= 0 ; i < width+2 ; i++)
	{
		cout<<'#';
	}
	cout<<endl;
	for(int i= 0 ; i < height ; i++)
	{
		for(int j = 0 ; j < width+2 ; j++)
		{
			if( j==0 || j == width+1 )
			cout<<'#';
			else if( i==y && j==x )
			cout<<"O";
			else if( i==FruitY && j==FruitX)
			cout<<"F";
			else
			cout<<" ";
		}
		cout<<endl;
	}
	
	for(int i= 0 ; i < width+2 ; i++)
	{
		cout<<'#';
	}
}

void Input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'w':
				dir = UP;
				break;
			case 's':
			    dir = DOWN;
			    break;
			case 'a':
			    dir = LEFT;
			    break;
			case 'd':
			    dir = RIGHT;
				break;
			default:
			    break;				
		}
	}
}

void Logic()
{
	if(dir != STOP)
	{
		switch(dir)
		{
			case UP:
				--y;
				break;
			case DOWN:
				++y;
				break;
			case LEFT:
				--x;
				break;
			case RIGHT:
				++x;
				break;
			default:
			    break;				
		}
	}
	
	if( FruitY==y && FruitX==x )
	{
		FruitX = rand() % width;
	    FruitY = rand() % height;
	}
	
	else if ( y<0 || y==21 || x==0 || x==21)
	{
		if(y<0 && (x>=0 && x<=21))
		{
			y = 20;
		}
		else if( y==21 && (x>=0 && x<=21))
		{
			y = 0 ;
		}
		else if( x==0 && (y>0 && y<21))
		{
			x = 20;
		}
		else if( x==21 && (y>0 && y<21))
		{
			x = 1;
		}
		
	}
	
}

int main()
{
	setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(40);
	}
	
	return 0;
}
