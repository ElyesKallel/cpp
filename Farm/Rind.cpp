#include "Rind.h"



Rind::Rind(string name, int iDNr, double gewicht, double preis) : Tier(name, iDNr, gewicht, preis)
{
	this->tierart = "Rind";
}

void Rind::fuettern(double menge)
{
	double zusatzGewicht = ((menge * 5) / 100);
	gewicht = gewicht + zusatzGewicht;
}

void Rind::artikulieren()
{
	cout << "------------------" << endl;
	cout << endl;
	cout << "Ich heisse " << name << ", meine Id Nr. lautet: " << getID() << " und ich wiege " << gewicht << " kg." << endl;
	cout << "Als " << tierart << " kann ich " << this->MilchGeben() << " Liter Milch /Tag geben." << endl;
	cout << endl;
	cout << "------------------" << endl;
}

int Rind::MilchGeben()
{
	int Milch = 0;
	Milch = ((double)gewicht / 10.0f);
	return (int)Milch;
}

Rind::~Rind()
{
}
