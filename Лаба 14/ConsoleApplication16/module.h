#pragma once
#include "stdafx.h"
#include "math.h"
#include <iostream>
using namespace std;

class Elem {
public:
	int n;
	Elem * next, *prev;
	Elem() { next = 0; prev = 0; n = 0; }
	virtual void print() {
		cout << " Elem count " << this->n << endl;
	}
	virtual ~Elem() {}
};

class List {
public:
	Elem * first, *last, *cur;
	List() { first = 0; last = 0; cur = 0; }
	
	void add(Elem * temp){
		if (first == 0) {
			temp->prev = 0; temp->next = 0;
			first = temp; last = temp;
		}
		else {
			last->next = temp; temp->prev = last;
			last = temp; temp->next = 0;
		}
	}

	void add_head(Elem * temp) {
		if (first == 0) {
			temp->prev = 0; temp->next = 0;
			first = temp; last = temp;
		}
		else {
			temp->prev = 0; temp->next = first;
			first->prev = temp; first = temp;
		}
	}

	void print_List() { cur = first;
	while (cur != 0) { cur->print(); cur = cur->next; }
	}

	void max_rect() {
		Elem *a;
		a = first;
		cur = first->next;
		while (cur != 0) {
			if (a < cur) { a = cur; }
			cur = cur->next;
		}
		 a->print();
		
	}
	

};

class Tnum :public Elem {
public:
	float num;
	virtual void print() { cout << " Tnum num = " << this->num << endl; }
	Tnum() {}
	Tnum(float x) :Elem() { num = x; }

};

class Tstr :public Elem {
public:
	char *st;
	virtual void print() { cout << " Tstr st = " << this->st << endl; }
	Tstr() {}
	Tstr(char *s) :Elem() { st = new char[strlen(s) + 1];
	strcpy(st, s); st[strlen(s) + 1] = '\0';
	}

};

class Rect : public Elem {
	double d, a, s;
public:
	Rect() {}
	virtual void print() { cout << " Rect area =  " << area() << endl; }
	Rect(double d1, double h) :Elem() { d = d1; a = h; }
	double area() { return s = d*a; }
	Rect & operator>(Rect &a) {

		if (a.area() > this->area()) { return a; }
		else { return *this; }
	}

};

class Box : public Rect {
	double z, v;
public:
	Box() {}
	Box(double d, double s, double z1) :Rect(d, s) { z = z1; v = 0; }
	virtual void print() {
		cout << " Box volume =  " << vb() << endl;
	}
	double vb() {
		v = area()*z; return v;
	}
	Box & operator>(Box &a) {
		
		if (a.vb() > this->vb()) { return a; }
		else { return *this; }
	}

};

typedef double(*fun) (double x);
double f1(double x) { return x*sin(x); }
double f2(double x) { return -3 * x*cos(x); }

class Baza_Int :public Elem {
protected: float a, b, eps;
		   fun f;
public: 
	virtual double integral() { return 0; }
	virtual void print() { cout << " Baza Int = " << endl; }
	Baza_Int() {}
	Baza_Int(double av, double bv, int nv, fun f1) { a = av; b = bv; n = nv; f = f1; eps = 0.1e-3; }

};

class Int_Rect :public Baza_Int {
public:
	double s;
	double integral() {
		double s, sp, h, y, d;
		long int i, n; n = 50;
		sp = 1; d = 1;
		while (fabs(d) > eps) {
			for (i = 0, h = (b - a) / n, s = 0; i < n; i++) {
				y = f(a + h*i); s += y*h;
			}
			d = s - sp; sp = s; n = n * 2;
		}
		return s;
	}


	void print() { cout << " Int Rect = " << integral() << endl; }
	Int_Rect() { Baza_Int(); }
	Int_Rect(double av, double bv, int nv, fun f1) :Baza_Int(av, bv, nv, f1) {}
};

class Int_trap :public Baza_Int {
public:
	double s;
	double integral() {
		double s, sp, h, y, d;
		long int i, n; n = 50;
		sp = 1; d = 1;
		while (fabs(d) > eps) {
			h = (b - a) / n; s = (f(a) + f(b))*(h / 2);
			for (i = 1; i < n - 1; i++) { y = f(a + h*i); s += y*h; }
			d = s - sp; sp = s; n = n * 2;
		}
		return s;
	}
	void print() { cout << " Int trap = " << integral() << endl; }
	Int_trap() { Baza_Int(); }
	Int_trap(double av, double  bv, int nv, fun f1) :Baza_Int(av, bv, nv, f1) {}
};
class Int_Parabol : public Baza_Int {
public:
	double s;
	double integral() {
		double s, sp, h, y, d;
		long int i, n; n = 50; ; sp = 1; d = 1;
		while (fabs(d)>eps) {
			h = (b - a) / n;
			for (i = 1, s = (f(a) + f(b))*(h / 3); i<n - 1; i++) {
				y = f(a + h*i);
				if (i % 2) s += 2 * y*(h / 3);
				else s += 4 * y*(h / 3);
			}
			d = s - sp; sp = s; n = n * 2;
		}
		return s;
	}
	void print() { cout << " Int Parabol = " << integral() << endl; }
	Int_Parabol() { Baza_Int(); }
	Int_Parabol(double av, double  bv, int nv, fun f1) :Baza_Int(av, bv, nv, f1) {}
};