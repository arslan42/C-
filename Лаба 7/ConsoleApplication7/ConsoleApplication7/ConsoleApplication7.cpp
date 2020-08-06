// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "module.h"
using namespace std;

int main()
{
	int i, j, n, m;
	Baza_Integral *zpf, *zpf1;
	double s, x, a, b;
	//metod trapecii
	zpf = new Int_trap_eps(-3, 3, 0.00001);
	s = zpf->poisk_integral(f1);
	cout<< endl << "*** METOD TRAPECII = " << s <<" ***"<< endl;

	//metod pryamougolnikov
	zpf1 = new Int_rect_eps(-3, 3, 0.00001);
	s = zpf1->poisk_integral(f1);
	cout << endl << "*** METOD PRYAMOUGOLNIKOV = " << s << " ***" << endl;

	//metod parabol
	zpf = new Int_Parabol_eps(-3, 3, 0.00001);
	s = zpf1->poisk_integral(f1);
	cout << endl << "*** METOD PARABOL = " << s << " ***" << endl;

	//nasledovanie
	Rect *zf;
	zf = new Rect(7, 2);
	cout <<endl<<"*** PLOSHAD PRYAMOUGOLNIKA = "<< zf->area()<<" ***" << endl;

	zf = new Box(7, 2, 6);
	cout << endl<< "*** PLOSHAD KVADRATA = " << zf->area() << " ***" << endl;

	zf = new Prizma(7, 2, 6);
	cout <<endl<<"*** PLOSHAD PRIZMI = "<< zf->area() <<" ***"<< endl;
	
	//friend funkciya
	Box *t;
	t = new Box(7, 2, 6);
	s = sum(t);
	cout << endl << " FRIEND Funkciya (summa storon) = " << s <<endl<< endl;
	system("pause");
    return 0;
}

