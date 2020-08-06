// ConsoleApplication5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "module.h"
#include <iostream>
using namespace std;

int main(){
	int i, k, j, n, m;
	double xc[] = { 7,8,9,12,3,4,5,9,15,57,34,23 };
	double yc[] = { 11,23,2,4,5,16,7,18,19,23 };
	double kc[] = { 1,8,1,12,3,4,5,9,15,57 };
	double bc[] = { 12,23,12,4,5,16,7,18,19 };

	Point *b1, p;
	double a, b; int **c;
	n = 5; b1 = new Point[n];

	for (i = 0; i < n; i++)
		b1[i] = Point::Point(xc[i], yc[i]); //b1[i].set(xc[i],yc[i]);
	cout << "*** Getter ***" << endl;
	for (i = 0; i < n; i++)
		cout << endl<<" x="<< b1[i].get_x() << ", y=" << b1[i].get_y() << endl;

	Point p1, ps = b1[1];
	cout <<endl<< "*** Copy ***" << endl;
	cout << endl << " x=" << ps.get_x() << ", y=" << ps.get_y() << endl;
	
	p = b1[0];
	cout <<endl<< "*** Operaciya = ***" << endl;
	cout << endl << " x=" << p.get_x() << ", y=" << p.get_y() << endl;
	
	p1 = p + ps;
	cout << endl << endl << "*** Operaciya + ***" << endl;
	cout << endl << " x=" << p1.get_x() << ", y=" << p1.get_y() << endl;

	p = p + ps;
	cout << endl << endl << "*** Operaciya + ***" << endl;
	cout << endl << " x=" << p.get_x() << ", y=" << p.get_y() << endl;

	Baza_tab v = Baza_tab(0, 9, 100);
	Point *tw, *tv0;
	n = 50;

	tw = v.tabul(f1);
	cout << endl << "*** Tabulyaciya f(x)=x*sin(x) ***" << endl<<endl;
	for (i = 0; i < v.get_n(); i++)
		cout <<"Iteraciya="<< i << ", x=" << (tw + i)->get_x() << ", y=" << tw[i].get_y() << endl;

	tv0 = v.interwal_nul();
	cout <<endl<< "*** Funkciya interwal_nul()" << endl<<endl;
	for (i = 0; i < v.kol_in; i++)
		cout << "Iteraciya=" << i << ", x=" << (tv0 + i)->get_x() << ", y=" << tv0[i].get_y() << endl;
	
	Baza_tab *vt = new Baza_tab(0, 9, 100);
	n = 50;
	tw = vt->tabul(f2);
	cout<<endl<< "*** Tabulyaciya f(x)=x*sin(x)+x*cos(x) ***" <<endl<< endl;
	for (i = 0; i < vt->get_n(); i++)
		cout << "Iteraciya=" << i << ", x=" << (tw + i)->get_x() << ", y=" << tw[i].get_y() << endl;

	v.~Baza_tab(); vt->~Baza_tab();

	
	cout << endl;
	system("pause");
    return 0;
}

