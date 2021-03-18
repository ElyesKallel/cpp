#pragma once
class Hanoi
{
	int height;
	int *Pfeiler[3];
	int Top[3];
	int counter;
public:

	Hanoi(int h);
	void setzeTurm(int h, int von, int nach, int uber);
	void setzeScheibe(int von, int nach);
	void print();
	void seekTop();
	void delTop(int von, int nach);
	~Hanoi();
};

