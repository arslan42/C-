// ConsoleApplication12.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "module.h"



int main() {
	
	El_mas prt[] = { El_mas(2,7), El_mas(5,19), El_mas(8,9), El_mas(11,2), El_mas(14,21),El_mas(25,100) };
	
	int i, j, n, m, k;
	setlocale(0, "");

	Elemd *sd1 = new Elemd(1, prt[0]);
	Listd *spd, *s2d, sp;
	
	spd = new Listd();
	s2d = new Listd();
	n = 5;
	
	//dobavlyaem elementi s golovi
	cout << endl << " Dobavlyaem v nachalo spiska S2D" << endl<< endl;
	for (i = 0; i < n; i++)
		s2d->add_head(i, prt[i]);
	s2d->print_List();
	cout  << endl;
	
	//dobavlyaem elementi s konca
	cout << " Dobavlyaem v konec spiska SPD " << endl<<endl;
	for (i = 0; i < n; i++) spd->add(i, prt[i]);
	spd->print_List();
	
	//vstavlyaem elementi v spisok
	Elemd *sp1;
	sp1 = spd->first->next->next;
	spd->wstawka(sp1, prt[5], 21);
	cout << endl << "*** Vstavili novii element posle 3-go v SPD ***" << endl << endl;
	spd->print_List();
	cout <<endl << "*** Vstavili novii element posle 2-go v SPD ***" <<endl<< endl;
	sp1 = spd->first->next;
	spd->wstawka(sp1, prt[5], 23);
	spd->print_List();
	
	//udalyaem hvost
	spd->del_xwost();
	cout << endl << "*** Udalili hvost spiska spd ***" << endl << endl;
	spd->print_List();

	//udalyaem golovu
	spd->del_head();
	cout <<endl<< "*** Udalili golovu spiska spd ***" << endl << endl;
	spd->print_List();

	//destruktor
	cout <<endl<< "*** Osvobojdaem pamyat pod spd ***" << endl << endl;
	spd->~Listd();

	cout << endl << endl;
	system("pause");
	return 0;
}