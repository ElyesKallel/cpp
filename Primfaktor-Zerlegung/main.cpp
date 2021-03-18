#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long n;
	cout << "Geben Sie die Zahl n: ";
	cin >> n;

	vector<long> vec;

	//Vector ausfüllen;

	for (long i = 2; i < n; i++)
	{
		vec.push_back(i);
	}

	//Primzahlen durch Algorithmus des Erasthenes;

	for (size_t i = 0; i < vec.size(); i++)
	{
		if (vec[i] != 0)
		{
			size_t k = vec[i] + i;
			while (k < vec.size())
			{
				vec[k] = 0;
				k = k + vec[i];
			}
		}
	}
	//Alle 0 entfernen;
	auto it = vec.begin();
	while (it != vec.end())
	{
		if (*it == 0)
			it = vec.erase(it);
		else it++;
	}

	cout << endl;
	//Zerlegung Berechnen
	cout << n << "=";
	for (size_t i = 0; i < vec.size(); i++)
	{
		long p = vec[i];
		while (fmod(n, p) == 0)
		{
			n = n / p;
			cout << p << "*";
		}
	}
	cout << endl;
	return 0;
	//Beim Größe Zahlen braucht mein Rechner viel zeit um das Ergebnisse zurückzugeben.
	//Ich habe fmod statt %(modulo) benutzt weil Werten von typ Long nicht mit % berechnet werden können.
	//Ich habe die Variable(i) als type 'size_t' definiert weil die Funktion   vector<>::size()  size_t zurückgibt. 

}