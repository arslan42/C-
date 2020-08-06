// ConsoleApplication4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "module.h"
using namespace std;

int main()
{
	int i, j, n, m;
	double xc[] = { 7, 8, 9, 12, 3 };
	double yc[] = { 11, 23, 2, 4, 5 };
	double kc[] = { 1, 8, 1, 12, 3 };
	double bc[] = { 12, 23, 12, 4, 5 };
	Point *b1, p;
	double **a;
	int **c;
	n = 5;
	b1 = new Point[n];
	for (i = 0; i < n; i++)
		b1[i].set(xc[i], yc[i]);
	cout << "*** Vivod massiva konstant Point s pomosh`u getterov ***" << endl;
	for (i = 0; i < n; i++)
		cout << b1[i].get_x() << " " << b1[i].get_y() << endl;
	//delete b1;


	Line *z1;
	z1 = new Line[n];
	for (i = 0; i < n; i++)
		z1[i].set(kc[i], bc[i]);
	cout <<endl<< "*** Vivod massiva konstant Line s pomosh`u getterov ***" << endl;
	for (i = 0; i < n; i++)
		cout << z1[i].get_k() << " " << z1[i].get_b() << endl;
	
	
	c = matr_prov(z1, n);
	cout << "*** Matrix Sootvetstvii ***" << endl;
	print_matr(c, n, n);

	p.set(20, 15);
	cout << endl<< "Proverka " << i << "-go elementa na ravenstvo s p(20,15) : resultat " << z1[i].prov_t(p) << endl;

	system("pause");
    return 0;
}

