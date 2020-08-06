// ConsoleApplication13.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "module.h"
#include <iostream>
using namespace std;

int main() {
	int indc[] = { 5, 8, 10, 15, 20 };
	int indc1[] = { 3, 8, 11, 15, 19 };
	int i, j, m, n, k;
	setlocale(0, "");

	List *sp, *sp1, *sps;

	n = 5;
	sp = new List();
	for (i = 0; i < n; i++) sp->add(i);
	cout << "*** Spisok sp ***" << endl << endl;
	sp->print_List();
	cout << endl << endl;

	sp1 = new List();
	/*
	for (i = 0; i < n; i++) sp1->add(indc1[i]);
	cout << "*** Spisok sp1 ***" << endl << endl;
	sp1->print_List();
	cout << endl<<endl;
	*/
	sps = new List();
	/*
	for (i = n - 1; i >= 0;i--) sps->add(indc[i]);
	cout << "*** Spisok sps ***" << endl<<endl;
	sps->print_List();
	cout << endl << endl;
	*/
	//wstawka chisla
	sp->cur = sp->first->next; sp->wstawka(sp->cur, 17);
	cout << "*** Spisok sp posle wstawki chisla 17 posle 2-go elementa ***" << endl << endl;
	sp->print_List();
	cout << endl << endl;

	//udalenie zwena
	sp->cur = sp->first->next->next->next;
	sp->del_zweno(sp->cur);
	cout << "*** Spisok sp posle udaleniya 4-go elementa ***" << endl << endl;
	sp->print_List();
	cout << endl << endl;

	//udalenie xwosta i golovi
	sp->del_xwost();
	sp->del_head();
	cout << "*** Spisok sp posle udaleniya golovi i hvosta ***" << endl << endl;
	sp->print_List();
	cout << endl << endl;

	sp->del_List();
	//razrejennie massivi
	for (i = 0; i < n; i++) sp->add(i);
	for (i = 0; i < n; i++) sp1->add(i);
	cout << "***Spisok SP ***" << endl << endl;
	sp->print_List();
	cout << endl << endl;

	//Massiv 1
	sp->cur = sp->first;
	for (i = 0; i < n; i++) {
		sp->cur->dat = El_mas(indc[i], i + 4);
		sp->cur = sp->cur->next;
	}

	cout << endl << " Massiv 1 " << endl;
	sp->cur = sp->first;
	cout << "*** SP BEGIN" << endl;
	while (sp->cur) {
		cout <<  " j=" << sp->cur->dat.num << ", el=" << sp->cur->dat.j << endl;
		sp->cur = sp->cur->next;
	}
	
	cout << " SP END ***" << endl;

	//Massiv 2
	sp1->cur = sp1->first;
	for (i = 0; i < n; i++) {
		sp1->cur->dat = El_mas(indc[i], i + 2);
		sp1->cur = sp1->cur->next;
	}
	cout << endl << " Massiv 2 " << endl;
	cout << "*** SP1 BEGIN " << endl;
	sp1->cur = sp1->first;
	while (sp1->cur) {
		cout << " j=" << sp1->cur->dat.num << ", el=" << sp1->cur->dat.j << endl;
		sp1->cur = sp1->cur->next;
	}
	cout << " SP1 END***" << endl;

	m = 2 * n;
	//spisok SPS
	for (i = 0; i < m; i++) sps->add(i);
	cout << endl << "*** Spisok Sps ***" << endl << endl;
	sps->print_List();

	cout << endl <<endl<< " Podschet summi " <<endl<< endl;
	j = sum_raz_mas(sp, sp1, sps);
	cout << " j=" << j << endl<<endl;

	cout << "*** ITOG ***" << endl << endl;;
	sps->cur = sps->first;
	for (i = 0; i < j; i++) {
		cout << " j= " << sps->cur->dat.num << ", el=" << sps->cur->dat.j << endl;
		sps->cur = sps->cur->next;
	}
	cout << endl << endl;
	system("pause");
	return 0;
}