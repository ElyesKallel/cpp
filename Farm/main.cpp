#include<iostream>
#include"Tier.h"
#include"Katze.h"
#include"Huhn.h"
#include"Rind.h"

#define MAX 10

using namespace std;

int Tier::currentMaxNumber = 0;

void printTiere(Tier *Tab[])
{
	cout << "### Verfuegbar Tiere ###" << endl;
	for (int i = 0; i < MAX; i++)
	{
		if (Tab[i] != nullptr)
		{
			cout << "(" << i + 1 << ")-";
			Tab[i]->artikulieren();
		}
	}
	cout << "### Ende Verfuegbar Tiere ###" << endl;
}

void verkaufen(Tier *Tab[], int id)
{
	if ((id > 0) && (id < (Tier::getCurrentMaxNumber() + 1)))
	{
		Tier *p = Tab[id - 1];
		if (p != nullptr)
		{
			cout << "Tier:" << Tab[id - 1]->name << "wurde verkauft !" << endl;
			delete p;
			Tab[id] = NULL;
		}
		else
		{
			cout << "Tier :" << id << "wurde bereits früher verkauft !" << endl;
		}
	}
	else
	{
		cout << "Unerlaubtes tier !" << endl;
	}
}

void alleverkaufen(Tier *Tab[])
{
	for (int i = 0; i < Tier::getCurrentMaxNumber(); i++)
	{
		verkaufen(Tab, i + 1);
	}
}


int main(int argc, char *argv[])
{
	Tier *Tiere[MAX];

	for (int i = 0; i < MAX; i++)                      //Alle auf Nullptr initialisieren
	{
		Tiere[i] = nullptr;
	}

	int option = 0; 
	int tierart = 0;

	while (1 == 1)
	{
		cout << "******************************" << endl;
		cout << "Was moechten Sie tun?" << endl;
		cout << endl;
		cout << "1. Tier einkaufen" << endl;
		cout << "2. Tier verkaufen" << endl;
		cout << "3. Tier fuettern" << endl;
		cout << "4. Gesamte Tier artikulieren" << endl;
		cout << "5. beenden" << endl;
		cout << "******************************" << endl;

		cin >> option;

		switch (option)
		{
			case 1:
			{
				double preis = 0.00;
				double startgewicht = 0.00;
				string name;

				cout << "##### Tier einkaufen #####" << endl;
				cout << "Was moechten Sie einkaufen?" << endl;
				cout << "1 --> Katze, 2 --> Huhn, 3 --> Rind" << endl;
				cout << "Tierart : " << endl;
				cin >> tierart;
				cout << "Gewicht : ";
				cin >> startgewicht;
				cout << "Preis : ";
				cin >> preis;
				cout << "Name : ";
				cin >> name;

				int Nr = Tier::getCurrentMaxNumber();

				switch (tierart)
				{
					case 1:
						Tiere[Nr] = new Katze(name, Nr, startgewicht, preis);
						break;
					case 2:
						Tiere[Nr] = new Huhn(name, Nr, startgewicht, preis);
						break;
					case 3:
						Tiere[Nr] = new Rind(name, Nr, startgewicht, preis);
						break;
				}
				Nr++;
				break;
			}
			case 2:
			{
				int tier = 0;
				cout << "##### Tier verkaufen #####" << endl;
				if ((tier > 0) && (tier < (Tier::getCurrentMaxNumber() + 1)))
				{
					printTiere(Tiere);
					cout << "Welches Tier soll verkauft werden ? : ";
					cin >> tier;
					cout << endl;
					verkaufen(Tiere, tier);
				}
				else
				{
					cout << "Es gibt kein Tier zu verkaufen !!" << endl;
				}
				break;
			}
			case 3:
			{
				int tier = 0;
				double menge;
				cout << "##### Tier fuettern #####" << endl;
				if ((tier > 0) && (tier < (Tier::getCurrentMaxNumber() + 1)))
				{
					printTiere(Tiere);
					cout << "Welches Tier soll gefuettert werden ? : ";
					cin >> tier;
					cout << endl;
					cout << "Wie viel soll gefuettert werden ? : ";
					cin >> menge;
					cout << endl;
					Tiere[tier - 1]->fuettern(menge);
				}
				else
				{
					cout << "Unerlaubtes Tier !" << endl;
				}
				break;
			}
			case 4:
			{
				printTiere(Tiere);
				break;
			}
			case 5:
			{
				alleverkaufen(Tiere);
				_CrtDumpMemoryLeaks();
				system("pause");
				exit(0);
				break;
			}
		}
	}
	return 0;
}