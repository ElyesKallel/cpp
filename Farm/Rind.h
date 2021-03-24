#pragma once
#include "Tier.h"
class Rind : public Tier
{
public:
	Rind(string name, int iDNr, double gewicht, double preis);
	void fuettern(double menge);
	void artikulieren();
	int MilchGeben();
	~Rind();
};

