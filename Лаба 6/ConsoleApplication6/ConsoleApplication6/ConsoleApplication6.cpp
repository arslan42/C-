// ConsoleApplication6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "module.h"
#include <iostream>
using namespace std;

int main()
{
	int i, n;
	Point *tw;
	Box xt;
	xt = Box(6, 8, 9);
	cout << "*** OB`EM KOROBKI = " << xt.vb() << " ***" << endl;

	Baza_tab v = Baza_tab(0, 9, 100);
	tw = v.tabul(f1);

	//metod pryamougolnikov
	Int_Rect *fz = new Int_Rect(0, 9, 100);
	fz->tabul(f1);
	cout << endl<<"*** Metod pryamougolnikov = "<<fz->integral()<<" ***" << endl;

	//metod trapecii
	Int_trap *fz1 = new Int_trap(0, 9, 100);
	fz1->tabul(f1);
	cout <<endl<<"*** Metod trapecii = "<< fz1->integral()<<" ***"<<endl<<endl;

	system("pause");


    return 0;
}

