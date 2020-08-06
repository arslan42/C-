// ConsoleApplication15.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include "module.h"
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int indc[] = { 5,8,10,15,20 }; int indc1[] = { 3,8,11,15,19 };
	int i, j, n, m, k; ;
	setlocale(0, "");

	List<Tnum> spi;
	Tnum p[] = { Tnum(57), Tnum(245), Tnum(1234),Tnum(8),Tnum(937),Tnum(998) };
	for (i = 0; i<6; i++) spi.add(p[i]);
	cout << "*** Spisok Tnum ***" << endl;
	spi.print_Lst(); 
	cout << endl;

	Rect pr[] = { Rect(5,7),Rect(4,5),Rect(12,34),Rect(15,14) };
	List<Rect> spr;
	for (i = 0; i<4; i++) spr.add(pr[i]); 
	cout << "*** Spisok Rect ***" << endl;
	spr.print_Lst();
	cout << endl;

	//Graf
	Rebro reb[] = { Rebro(0,1,5), Rebro(1,2,5), Rebro(2,6,5), Rebro(0,4,5),
		Rebro(0,3,5), Rebro(3,2,5), Rebro(4,9,5), Rebro(9,6,5),
		Rebro(3,5,5), Rebro(6,5,5), Rebro(7,8,5) };
	List<Rebro> sreb;
	for (i = 0; i<9; i++) sreb.add(reb[i]);
	cout << "*** Spisok Reber ***" << endl;
	sreb.print_Lst();
	cout << endl; //List of rebro`s

	Tnum incep(0); Tnum cel(6);
	int flagys = 1, flagnot = 1;
	List <Tnum> listOpenNodes;
	listOpenNodes.add(incep); //add start to list
	sreb.cur = sreb.first;
	j = 0;
	while (flagys && flagnot) {
		while (sreb.cur) {
			if (listOpenNodes.first->data.num == sreb.cur->data.firstNum &&
				sreb.cur->data.lastNum == cel.num) {
				flagys = 0;
				cout << endl << " istok " << sreb.cur->data.firstNum <<
					" cel stock " << sreb.cur->data.lastNum << endl;
				listOpenNodes.print_List();
			}
			else if (listOpenNodes.first->data.num == sreb.cur->data.firstNum) {
				listOpenNodes.add(Tnum(sreb.cur->data.lastNum));
				cout << endl << " potomok " << sreb.cur->data.lastNum << endl;
				j++;
			}
			sreb.cur = sreb.cur->next;
		}
		if (!flagys) {
			cout << " cel istok " << incep.num;
		//incep.print();/listOpenNodes.first->data.num<<endl;
		}
		else if (j == 0) { flagnot = 0; cout << " net cel "; }
		else {
			cout << endl << " listOpenNodes " << endl;
			listOpenNodes.print_Lst();
			listOpenNodes.del_head();
			cout << endl << " del_head()" << endl;
			listOpenNodes.print_Lst();
			sreb.cur = sreb.first;
			j = 0;
			cout << endl << " cel shaga " << listOpenNodes.first->data.num << endl;
		}
	}

	Poisk_graf<Rebro, Tnum> pgraf;
	Tnum wist, wst; wist = Tnum(0); wst = Tnum(5);
	pgraf = Poisk_graf<Rebro, Tnum>(sreb, wist, wst);
	pgraf.poisk_sh(); cin >> i;

	return 0;
}

