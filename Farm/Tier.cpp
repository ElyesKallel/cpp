#define _CRT_SECURE_NO_WARNINGS
#include "Tier.h"
#include<ctime>



Tier::Tier(string tName, int id, double startgewicht, double tpreis)
{
	name = tName;
	gewicht = startgewicht;
	preis = tpreis;
	this->tierart = "";

	time_t erg = time(NULL);
	this->geburt = asctime(localtime(&erg));

}

int Tier::getCurrentMaxNumber()
{
	return currentMaxNumber;
}

int Tier::getID()
{
	return iDNr;
}


void Tier::artikulieren()
{
}

void Tier::fuettern(double menge)
{
}

Tier::~Tier()
{
}
