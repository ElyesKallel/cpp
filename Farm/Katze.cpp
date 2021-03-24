#include "Katze.h"



Katze::Katze(string name, int iDNr, double gewicht, double preis) : Tier(name, iDNr, gewicht, preis)
{
	this->tierart = "Katze";
}

void Katze::fuettern(double menge)
{
	double zusatzGewicht = ((menge * 15) / 100);
	gewicht = gewicht + zusatzGewicht;
}

void Katze::artikulieren()
{
	cout << "------------------" << endl;
	cout << endl;
	cout << "Ich heisse " << name << ", meine Id Nr. lautet: " << getID() << " und ich wiege " << gewicht << " kg." << endl;
	cout << "Als " << tierart << " kann ich "<< this->FaengtMaeuse() <<" Maüse pro Tag fangen." << endl;
	cout << endl;
	cout << "------------------" << endl;
}

int Katze::FaengtMaeuse()
{
	int Maeuese = 4, n = 0;
	double Normalgewicht = 4;
	n = gewicht - Normalgewicht;
	if (gewicht <= Normalgewicht)
	{
		return Maeuese = 4;
	}
	else if (gewicht > Normalgewicht)
	{
		for (int i = 0; i < n; i++)
		{
			Maeuese = Maeuese - ((Maeuese * 25) / 100);
		}
		if (Maeuese < 0)
			Maeuese = 0;
	}

	return Maeuese;
}

Katze::~Katze()
{
}
