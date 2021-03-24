#pragma once
#include<iostream>
#include<string>

using namespace std;

class Tier
{
	const int iDNr = 0;
	static int currentMaxNumber;


public:
	
	Tier(string tName, int id, double startgewicht, double tpreis);
	~Tier();
	int getID();
	static int getCurrentMaxNumber();
	virtual void artikulieren();
	virtual void fuettern(double menge);

	string name;
	string geburt;
	string tierart;
	double gewicht;
	double preis;

	
};

