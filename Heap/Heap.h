#pragma once
class Heap
{
	int kap;
	int anz;
	int *daten;

public:
	Heap(int k);
	void push(int wert);
	int pop();
	void upheap(int idx);
	void sickern(int idx);
	void print();
	void printb();
	~Heap();
};

