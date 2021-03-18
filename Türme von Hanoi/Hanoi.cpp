#include "pch.h"
#include "Hanoi.h"
#include <iostream>

using namespace std;


Hanoi::Hanoi(int h)
{
	height = h;
	counter = 0;
	Pfeiler[0] = new int[height];
	Pfeiler[1] = new int[height];
	Pfeiler[2] = new int[height];

	for (int i = 0; i < h; i++)
	{
		Pfeiler[0][i] = height - i;
		Pfeiler[1][i] = 0;
		Pfeiler[2][i] = 0;
	}
	Top[0] = Pfeiler[0][height - 1]; // Top[0]=1;
	Top[1] = 0;
	Top[2] = 0;
}

void Hanoi::setzeTurm(int h, int von, int nach, int uber)
{
	counter++;
	if (h == 1)
	{
		setzeScheibe(von, nach);
		return;
	}

	setzeTurm(h - 1, von, uber, nach);
	print();
	setzeScheibe(von, nach);
	print();
	setzeTurm(h - 1, uber, nach, von);
	print();
}

void Hanoi::setzeScheibe(int von, int nach)
{
	seekTop();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (Pfeiler[nach][j] == 0)
			{
				Pfeiler[nach][j] = Top[von];
				break;
			}
		}
		break;
	}
	seekTop();
	delTop(von, nach);
	seekTop();
}

void Hanoi::delTop(int von , int nach)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < height; j++)
		{
			if (Pfeiler[von][j]==Top[nach])
			{
				Pfeiler[von][j] = 0;
			}
		}
}

void Hanoi::seekTop()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < height; j++)
		{
			if (Pfeiler[i][j] != 0)
			{
				Top[i] = Pfeiler[i][j];
			}
		}
}

void Hanoi::print()
{
	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << Pfeiler[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl << "Iteration wurde " << counter << " mal aufgeruft ." << endl << endl;
}

Hanoi::~Hanoi()
{
}