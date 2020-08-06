// ConsoleApplication8.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "module.h"
#include <iostream>
using namespace std;

typedef double(*fun)(double x);
double f1(double x) { return x*sin(x); }
double f2(double x) { return x*sin(x) + x*cos(x); }
double f3(double x) { return x*cos(x) + 3; }


int main()
{
	int i, k, j, n, m;

	Baza_poisk *zpf;
	double s, x, a, b, shag;
	a = 8; b = 10;
	zpf = new Met_xord(a, b);
	s = zpf->poisk(f1);
	cout << endl << " koren xord=" << s << ", f(x)=" << f1(s) << endl;
	zpf = new Met_newton(a, b);
	s = zpf->poisk(f1);
	cout << endl << " koren newton " << s << " f(x)=" << f1(s) << endl;
	zpf = new Pol_Del(a, b);
	s = zpf->poisk(f1);
	cout << endl << " pol del =" << s << ", f(x)" << f1(s) << endl;
	
	Point *tv1, *t0, *t1e;
	Interval_nul *pf;
	pf = new Interval_nul(-30, 30, 50);
	tv1 = pf->tabul(f1);
	t0 = pf->interwal_nul();
	cout << " interwal nul() " << endl;
	for (i = 0; i < pf->kol_in; i++)
		cout << (t0 + i)->get_x() << " " << t0[i].get_y() << endl;

	for (i = 0; i < pf->kol_in; i++)
		cout << i << " " << (t0 + i)->get_x() << " " << t0[i].get_y() << endl;
	cout << " kol " << pf->kol_in << endl;

	for (i = 0; i < pf->kol_in; i++) {
		zpf = new Met_xord((t0 + i)->get_x(), (t0 + i)->get_y());
		s = zpf->poisk(f1);
		cout << endl << " Met_xord " << i << " s=" << s << " f(x)=" << f1(s) << endl;
	}

	pf->~Interval_nul();

	Interval_extrum_max * te;
	te = new Interval_extrum_max(-30, 30, 50);
	tv1 = te->tabul(f2);
	t0 = te->extrum_max();

	cout << " interwal ekxerm " << te->kol_in << endl;
	for (i = 0; i < te->kol_in; i++)
		cout << (t0 + i)->get_x() << " " << t0[i].get_y() << endl;
	te->~Interval_extrum_max();

	Baza_tab **fz;
	m = 3;
	fz = new Baza_tab*[m];
	cout << " Baza_tab masiv " << endl;
	for (i = 0, a = -30, shag = 20, b = a + shag; i < m; i++, a += 20, b = a + shag) {
		fz[i] = new Baza_tab(a, b, 10);
		t1e = fz[i]->tabul(f1);
		cout << " Baza tab " << endl;
		for (j = 0; j < fz[i]->get_n(); j++)
			cout << t1e[j].get_x() << " " << t1e[j].get_y() << endl;
	}
	for (i = 0; i < m; i++)
		fz[i]->~Baza_tab();
	//fun mas_f[]={f1,f2,f3};

	
	system("pause");
    return 0;
}

