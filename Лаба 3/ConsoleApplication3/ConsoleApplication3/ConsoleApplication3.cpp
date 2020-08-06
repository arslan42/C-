// ConsoleApplication3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "module.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0, j, k = 0, d1, n, m;

	//zadanie massiva struktur konstantami
	struct point temp[6] = { {20,10},{177,10},{35,14},
								{15,9},{34,14},{45,14} };
	n = 6; //cin>>n;

	//opisanie dinamicheskih massivov
	point *masp = new point[n];
	okr *mas_ok;
	mas_ok= new okr[n];
	line **matr_line;
	double **rt, **d;
	point *p, t0; int **p_okr;

	cout << "*** Vvod tochek***" << endl<<endl;
	for (i = 0, p = masp; i < n; p++, i++) {
		p->x = temp[i].x;
		p->y = temp[i].y;
	}

	//varianti zadaniya massiva: chtenie koordinat iz tochek massiva konstant
	for (i = 0, p = masp; i < n; p++, i++) {
		p->x = temp[i].x;
		p->y = temp[i].y; //dostup po ukazately

		//2-oi variant dostupa po ukazately
		//(masp+i)->x=temp[i].x; 
		//(masp+i)->y=temp[i].y;
		//dostup po indeksu
		//masp[i].x=temp[i].x;
		//masp[i].y=temp[i].y;
	}

	vivod_to(n, masp);//vizov funkcii vvoda massiva tochek

	matr_line = form_matr_line(n, masp);
	cout <<endl<< "*** Matrix Line ***" << endl;
	for (i = 0; i < n - 1; i++) {
		for (j = i + 1; j < n; j++)
			//cout<<(*(*(matr_line+i)+j)).k<<" ";
			cout << (*(matr_line + i) + j)->b << " ";
		cout << endl;
	}

	//videlenie pamyati pod matricu rasstoyanii
	rt = new double *[n];
	

	//videlyaetsa oblast pamyato pod massiv ukazatelei *(rt+i) - i element
	for (i = 0; i < n; i++) 
		*(rt + i) = new double[n];
		//vizov funkcii formirovaniya matrici rasstoyanii
		
		form_r(n, masp, rt);//vivod matrici rasstoyanii
		
		cout <<endl<< "*** Matrix rasstoyanii ***" << endl;
		for (i = 0; i < n-1; i++) {
			for (j = i + 1; j < n; j++)
				cout << *(*(rt + i) + j) << " ";
			cout << endl;
		}
	

	//vichislenie rasstoyaniya ot kajdoi tochki do nachala koordinat
	t0.x = 0;
	t0.y = 0; //zadanie koordinat
	for (i = 0, p = masp; i < n; p++, i++)
		p->r = rast(t0, *p);
	//zadanie massiva okrujnostei
	for (i = 0; i < n - 1; i++) {
		(mas_ok + i)->cent = *(masp + i);
		(mas_ok + i)->rad = 50;//cin>>(mas_ok+i)->rad;
	}

	//vizov funkcii opredeleniya polojeniya okrujnostei
	p_okr = form_okr(n, mas_ok);
	//vivod matrici polojeniya
	cout <<endl<< "*** OKR ***" << endl;
	n = 20;
	p = tabul(-5, 5, n, f1);
	vivod_to(n, p);
	system("pause");
    return 0;
}

