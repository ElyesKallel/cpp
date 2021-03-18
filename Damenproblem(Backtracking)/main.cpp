#include "pch.h"
#include <iostream>

using namespace std;

void print(int **board, int N)                                  //print fonction
{
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << board[i][j] << "  ";
		}
		cout << endl << endl;
	}
	cout << endl;
}

bool Platzfrei(int **board, int reihe, int spalte, int N)                  
{
	int i, j;
	for (i = 0; i < spalte; i++)
	{
		if (board[reihe][i])
			return false;
	}
	for (i = reihe, j = spalte; i >= 0 && j >= 0; i--, j--)
	{
		if (board[i][j])
			return false;
	}
	for (i = reihe, j = spalte; j >= 0 && i < N; i++, j--)
	{
		if (board[i][j])
			return false;
	}
	return true;
}

bool PlatziereDame(int **board, int spalte, int N)
{
	if (spalte >= N)
		return true;

	for (int i = 0; i < N; i++)
	{
		if (Platzfrei(board, i, spalte, N))
		{
			board[i][spalte] = 1;
			//print(board, N);                                       //Schritt f�r Schritt
			if (PlatziereDame(board, spalte + 1, N))                
				return true;
			board[i][spalte] = 0;
			//print(board, N);                                       //Schritt f�r Schritt
		}
	}
	return false;
}

bool DamenProblem(int N)
{
	int **board = new int *[N];
	for (int i = 0; i < N; i++)
	{
		board[i] = new int[N];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			board[i][j] = 0;
		}
	}

	if (PlatziereDame(board, 0, N) == false)
	{
		cout << "Solution does not exist";
		return false;
	}

	print(board, N);
	return true;
}

int main()
{
	int N;
	cout << "Geben Sie bitte ein groesse N ein : ";
	cin >> N;

	DamenProblem(N);
	//Der Algorithmus hat O(n^2) als Komplexit�t

	system("pause");
	return 0;
}