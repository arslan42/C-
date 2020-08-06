
#include "stdafx.h"
#include "module.h"

int main() {
	int i, j, n, m; 
		double s, d;
	
	Matrix<double> zt(1, 1);
	cout << "*** Vvedite matrix 1X1 ***" << endl;
	cout << endl << " ";
	cin >> zt;
	cout << endl << endl << "*** Matrix zt: ***" << endl << endl << zt;

	Matrix<int> at(2, 2);

	Matrix<int> *ct;
	ct = new Matrix<int>(2, 2);
	ct->setMatrix_const();
	cout  << endl << "*** Funkciya getMatrix() matrix CT ***" << endl<<endl;
	ct->getMatrix();

	at = *ct;
	cout << endl << "*** CT->AT ***" << endl << endl;
	cout << at;

	d = at.gaus_t();
	cout <<endl<< "*** GAUS d=" << d << " ***" << endl << endl;

	Matrix<int> pt(2, 2);
	cout << "*** Matrix PT - transponirovannaya matrix AT ***" << endl;
	pt = at.transponirov();
	cout << pt<<endl;

	ct = at*pt;
	at = *ct;
	cout << "*** PROIZVEDENIE MATRIX AT*PT ***" <<endl<< endl;
	cout << at;
	
	cout << endl << endl;
	system("pause");
	return 0;
}