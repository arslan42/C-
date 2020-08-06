// ConsoleApplication9.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "module.h"
using namespace std;


int main()
{
	int i, j, n, m;

	Matrix at(2, 2), *ft;
	Matrix bt(2, 2);
	Matrix rt = Matrix(2, 2);
	Matrix *ct, *dt;

	//zapolnenie AT konstantnimi znacheniyami
	cout << "*** Matrix AT: ***" << endl<<endl;
	at.setMatrix_const();
	at.getMatrix();

	//podshet kolichestva nulei
	cout <<endl<< "*** Kolichestvo nulei v strokah matrix AT: ***" << endl << endl;
	ft = at.Kol_0();
	ft->getMatrix();

	//transponirovanie
	bt = at.transponirov();
	cout <<endl<< "*** Transponirovannaya matrix AT: ***" << endl<<endl;
	cout << bt;

	//vichitanie matrix
	cout <<endl<< "*** Raznost matrix AT-BT ***" << endl<<endl;
	rt = at - bt;
	cout << rt;

	/*//increment matrix
	at++;
	cout << endl << "*** Increment matrix AT: ***" << endl<<endl;
	at.getMatrix();
	*/

	//kopirovanie matrix
	Matrix zt(at);
	cout << endl << "*** Kopirovanie matrix AT -> ZT ***" << endl<<endl;
	cout << zt;

	//summa matrix
	cout <<endl<< "*** Summirovanie matrix AT+BT= ***" << endl<<endl;
	dt = at + bt;
	dt->getMatrix();

	//raznost matrix
	cout << endl << "*** Raznost matrix AT-BT= ***" << endl << endl;
	rt = at - bt;
	rt.getMatrix();

	//proizvedenie matrix
	cout << endl << "*** Proizvedenie matrix AT*BT= ***" << endl << endl;
	ct = at*bt;
	ct->getMatrix();
	//cout << *ct;
	//rt = *dt - bt;
	//rt.getMatrix();
	//cin>>at; cout<<at;
	cout << endl;
	at.~Matrix();
	ct->~Matrix();


	cout << endl << endl;
	system("pause");
    return 0;
}

