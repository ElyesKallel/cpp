#include "pch.h"
#include <iostream>
#include "Hanoi.h"

using namespace std;

//beim erste setzturm braucht T(n-1)  ==> Bewege n-1 scheibe auf Hilf position 
//beim setzScheibe braucht Z:B ein constante C   ==> Bewege Größte scheibe auf Ziel Position
//beim zweite aufruf von setzturm T(n-1)  ==> Bewege n-1 Scheibe von Hilfposition auf Zielposition
//Das heißt T(n)=2*T(n-1)+c; 
//   und    T(0)=0;                  ==> d.h  T(n)=((2^n)-1).C      (C soll sein 1sec)
//                                          T(5)=31sec
//                                           T(20)=12Tage
//                                            T(64)=585Milliarden Jahre  XD
//  Die rekursive version ist praktisch nur für kleine n möglich .

int main()
{
	int h;
	cout << "Geben Sie bitte die Hoehe der Tuerme ein: ";
	cin >> h;
	Hanoi play(h);

	cout << endl << "############# Vor dem Hanoi #############" << endl;
	play.print();

	cout << endl << "############# Nach dem Hanoi #############" << endl << endl;
	play.setzeTurm(h, 0, 1, 2);
	play.print();
	cout << endl;


	system("pause");
	return 0;
}