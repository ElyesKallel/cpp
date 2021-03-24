#include "Huhn.h"



Huhn::Huhn(string name, int iDNr, double gewicht, double preis) : Tier(name, iDNr, gewicht, preis)
{
	this->tierart = "Huhn";
}

void Huhn::fuettern(double menge)
{
	double zusatzGewicht = ((menge * 25) / 100);
	gewicht = gewicht + zusatzGewicht;
}

void Huhn::artikulieren()
{
	cout << "------------------" << endl;
	cout << endl;
	cout << "Ich heisse " << name << ", meine Id Nr. lautet: " << getID() << " und ich wiege " << gewicht << " kg." << endl;
	cout << "Als " << tierart << " kann ich " << this->EierLegen() << " Eier pro Tag legen." << endl;
	cout << endl;
	cout << "------------------" << endl;
}

int Huhn::EierLegen()
{
	int Eier = 0;
	Eier = ((double)gewicht / 3.0f);
	return (int)Eier;
}

Huhn::~Huhn()
{
}
