// ConsoleApplication16.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "module.h"
#include <iostream>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	int i, j, n; char st1[60], *sa;
	float d[] = {78,45,78,77,93,17,8};
	char *mas[] = { "asdff","aerty","ddd" };

	setlocale(0, "");

	List sp,kp; Elem *p, *k;
	p = new Tnum(57); sp.add(p);
	p = new Tnum(57777); sp.add(p);
	p = new Tnum(192); sp.add(p);

	sa = "asdfg"; //or cin>>st1;

	p = new Tstr(sa); sp.add(p);

	p = new Rect(5, 7); sp.add(p);
	p = new Box(5, 7, 4); sp.add(p);

	p = new Tnum(57); sp.add_head(p);
	
	cout << "*** Spisok ***" << endl<<endl;
	sp.print_List();

	p = new Int_Rect(0, 9, 250, f1); sp.add(p);
	p = new Int_trap(0, 9, 250, f1); sp.add(p);
	p = new Int_Rect(-9, 9, 350, f1); sp.add(p);
	p = new Int_trap(-9, 9, 350, f1); sp.add(p);
	p = new Int_Parabol(-9, 9, 350, f1); sp.add(p);




	cout << endl << "*** Spisok ***" << endl << endl;
	sp.print_List();
	cout << endl;
	
	
	p = new Rect(1, 1); kp.add(p);
	p = new Rect(3, 1); kp.add(p);
	p = new Rect(1, 4); kp.add(p);
	p = new Rect(3, 2); kp.add(p);
	p = new Rect(7, 2); kp.add(p);

	kp.max_rect();
	

	cout << endl << endl;
	system("pause");
	return 0;
}