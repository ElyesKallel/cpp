#include "pch.h"
#include "Heap.h"
#include<iostream>

using namespace std;

Heap::Heap(int k)
{
	kap = k;
	anz = 0;
	daten = (int *)malloc(k * sizeof(int));
}

void Heap::push(int wert)
{
	daten[anz] = wert;
	upheap(anz);
	anz++;
}

int Heap::pop()
{
	int temp = daten[0];
	daten[0] = daten[anz - 1];
	anz--;
	sickern(0);
	return temp;
}

void Heap::upheap(int idx)
{
	while (idx > 0)                               // solange ich nicht an der Wurzel bin ;
	{
		int idxP = (idx - 1) / 2;                   // Elternindex
		if (daten[idx] > daten[idxP])                  //Tauschen
		{
			int temp = daten[idxP];
			daten[idxP] = daten[idx];
			daten[idx] = temp;
		}
		idx = idxP;
	}
}

void Heap::sickern(int idx)
{
	if (idx <= (anz / 2))                                     
	{
		int idxL = (2 * idx) + 1;                            //linkesindex von idx;   
		int idxR = idxL + 1;                                 //Rechtsindex von idx;
		if (daten[idxL] >= daten[idx])                       //1ste Bedingung     
		{                           
			int temp = idx;                                  //Werte austauschen
			idx = idxL;
			idxL = temp;
			sickern(idxL);                                   //1ste Rekursion
		}
		if (daten[idxR] >= daten[idx])
		{
			int temp = idx;                                 //Werte austauschen
			idx = idxR;                 
			idxR = temp;
			sickern(idxR);                                    //Zweite Rekursion
		}
	}
}

void Heap::print()
{
	for (int i = 0; i < anz; i++)
	{
		cout << daten[i] << " ";
	}
	cout << endl;
}

void Heap::printb()
{
	int i = 0;
	int lc = 1;
	while (i < anz)
	{
		for (int j = 0; i < lc; j++)
		{
			cout << daten[i++] << " ";
			if (i >= anz)
			{
				break;
			}
		}
		cout << endl;
		lc = lc * 2;
	}
	cout << endl;
}

Heap::~Heap()
{
	free(daten);
}