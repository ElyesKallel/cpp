#pragma once
#include "Tier.h"

class Katze : public Tier
{


public:

	Katze(string name,int iDNr, double gewicht,double preis);
	void fuettern(double menge);
	void artikulieren();
	int FaengtMaeuse();



	~Katze();
};

