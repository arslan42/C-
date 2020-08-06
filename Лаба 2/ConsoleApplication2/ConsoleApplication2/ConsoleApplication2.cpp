// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "module.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russia");
	int i, j, k, t, m, n, l;
	int ac[] = { 17,-1,5,17,66,10,16,5,0,34,0,14,2,0,15,-9,-14,-40,0,
				3,0,65,0,2,7,-31,90,51,12,-3,9,0,-8,18,23,0,14,58,
				93,46,25,66,21,42 };
	int **a, *b, **x;
	int *s, *ind;
	double **xp, sp;
	n = 5;

	//chtenie iz massiva konstant
	cout << "\n*** iz konstant ***";
	b = new int[n];
	for (i = 0, k = 0; i < n; i++)
		b[i] = ac[k++];
	printmas(b, n);

	//swap1
	swap(&b[0], &b[n - 1]);
	cout << endl<<endl << "*** Swap 1 ***";
	printmas(b, n);

	//swap2
	cout << endl << endl << "*** Swap 2 ***";
	swap(b + 1, b + (n - 1));
	printmas(b, n);

	//swaps(b+1,b+(n-1));printmas(b,n);

	//scalar
	k = scalar(b, b, n);
	cout << endl << endl << "*** Scalar k="<<k;
	//scalar1
	scalar1(b, b, &l, n);
	cout << endl << endl << "*** Scalar1 l=" << l;

	//sortirovka vstavkoi
	sort_wst(b, n);
	cout << endl << endl << "*** Sortirovka vstavkoi ***";
	printmas(b, n);

	//matrix
	cout << endl << endl << "*** Vvedite kolichestvo strok i stolbcov matrix ***" << endl;
	cin >> n >> m;
	a = new int*[n];
	for (i = 0; i < n; i++)
		*(a + i) = new int[m];
	for (i = 0, k = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = ac[k++];
	cout << "*** Matrix iz konstant ***" << endl << endl;
	print_matr(a, n, m);

	//sortirovka strok matrix
	sort_strok_wst(a, n, m);
	cout << endl << "*** Matrix posle sortirovki strok ***" << endl;
	print_matr(a, n, m);

	//summa matrix
	x = sum_matr(a, a, n, m);
	cout << endl << "*** Summa matrix A+A ***" << endl;
	print_matr(x, n, m);

	//vvod matrix
	n = 2;
	xp = new double *[n];
	for (i = 0; i < n; i++)
		*(xp + i) = new double[n];
	cout << endl << "*** Vvedite matrix " << n << "X" << n<<" ***"<<endl;
	wwod1_Matr(xp, n, n);
	print_matr(xp, n, n);



	cout << endl << endl;
	system("pause");
    return 0;
}

