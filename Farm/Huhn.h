#pragma once
#include "Tier.h"
class Huhn : public Tier
{

public:
	Huhn(string name, int iDNr, double gewicht, double preis);
	void fuettern(double menge);
	void artikulieren();
	int EierLegen();
	~Huhn();
};

