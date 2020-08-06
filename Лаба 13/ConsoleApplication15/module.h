#pragma once
#include <iostream>
using namespace std;

class El_mas {
public:
	int j, num;
	El_mas() {}
	El_mas(int x, int ip) { num = x; j = ip; }
	void print() { cout << " j= " << j << " num= " << num << endl; }

};

template <class T>
class Elem {
public:
	T data;
	int n;
	Elem *next, *prev;
	Elem(T d) { data = d; n = 0; next = 0; prev = 0; }
	void print() { data.print(); }
};

template <class T>
class List {
public:
	Elem<T> *first, *last, *cur;
public:
	List() { first = 0; last = 0; cur = 0; }
	void add(T temp);
	void add_head(T temp);
	void del_xwost();
	void del_head();
	int print_List_prev();
	void print_List();
	void del_List();
	void print_Lst() { cur = first; while (cur != 0) { cur->print(); cur = cur->next; } }
	Elem<T> & spisok(Elem<T> &a) {
		Elem *p;
		cur = first; while (cur != 0) { if (T = Rect) {p= new Elem()} }
	}

};

template <class T> void List<T>::add(T temp) {
	cur = new Elem<T>(temp);
	if (first) {
		last->next = cur;
		cur->prev = last;
		last = cur;
	}
	else {
		cur->prev = 0;
		cur->next = 0;
		first = cur;
		last = cur;
	}
}

template <class T> void List<T>::print_List() {
	cur = first;
	while (cur != 0) { cur->print(); cur = cur->next; }
}

template <class T> void List<T>::del_head() {
	Elem<T> *tmp;
	if (first->next) {
		tmp = first;
		first->next->prev = 0;
		first = first->next;
		delete tmp;
	}
	else if (first) {
		tmp = first;
		delete tmp;
		first = 0; last = 0;
	}
	else cout << " first=0 " << endl;
}

template <class T> void List<T>::del_xwost() {
	Elem<T> *tmp;
	if (last->prev) {
		tmp = last;
		last->prev->next = 0;
		last = last->prev;
		delete tmp;
	}
	else if (last) {
		tmp = last; delete tmp;
		first = 0; last = 0;
	}
	else cout << " last=0 " << endl;
}

template <class T> int List <T>::print_List_prev() {
	cur = last;
	int j = 0;
	while (cur != 0) {
		j++;
		cur->print();
		cur = cur->prev;
	}
	return j;
}

template <class T> void List<T>::del_List() {
	while (first && last) del_head();
}

class Rect {
	double d, a, s;

public: Rect() {}
		void print() { cout << " print TRect " << " d= " << d << " a= " << a << " s= " << area() << endl; }
		Rect(double d1, double h) { d = d1; a = h; }
		double area() { return s = d*a; }
		Rect & operator>(Rect &a) {

			if (a.area() > this->area()) { return a; }
			else { return *this; }
		}
};

class Tnum {
public:
	int num;
	void print() { cout << " print Tnum " << this->num << endl; }
	Tnum() {}
	Tnum(int x) { num = x; }
};

class Rebro {
public:
	int firstNum, lastNum, ves, metka;
	Rebro() {}
	Rebro(int fn, int ln, int vs, int m = 0) :firstNum(fn), lastNum(ln), ves(vs), metka(0) {}
	void print() { cout << " nodes " << firstNum << " " << lastNum << endl; }
};

template <class T, class Tr>
class Poisk_graf {
public:
	int flagys, flagnot;
	Tr incep, cel;
	List <Tr> listOpenNodes;
	List<T> sreb;
	Poisk_graf <T, Tr>() {}
	Poisk_graf <T, Tr>(List <T> p, Tr inw, Tr celw) {
		sreb = p;
		incep = inw;
		cel = celw;
		flagys = 1; flagnot = 1;
		listOpenNodes.add(incep);
	}
	int poisk_sh() {
		int i, j = 0, k, n;
		sreb.cur = sreb.first;
		while (flagys && flagnot) {
			while (sreb.cur) {
				if (listOpenNodes.first->data.num == sreb.cur->data.firstNum &&
					sreb.cur->data.lastNum == cel.num) {
					flagys = 0; listOpenNodes.print_List();
				}
				else
					if (listOpenNodes.first->data.num == sreb.cur->data.firstNum) {
						listOpenNodes.add(Tr(sreb.cur->data.lastNum));
						cout << " potomok " << sreb.cur->data.lastNum << endl;
						j++;

					}
				sreb.cur = sreb.cur->next;
			}
			if (!flagys) { cout << " cel " << endl; return 1; }
			else
				if (j == 0) { cout << " net cel "; flagnot = 0; return 0; }
				else {
					cout << " add= " << endl;
					listOpenNodes.print_Lst();
					listOpenNodes.del_head();
					listOpenNodes.print_Lst();
					sreb.cur = sreb.first; j = 0;
					cout << " cel shaga " << listOpenNodes.first->data.num << endl;
				}
		}
	}
};
