#pragma once
#include <iostream>
using namespace std;
class Rect {
protected:
	double d1, sh, s;
public:
	Rect() {}
	Rect(double d, double ch) {
		d1 = d; sh = ch; s = 0;
	}
	double get() { return d1; }
	virtual double area() { s = d1*sh; return s; }
};

class Box :public Rect {
	double z, v;
public:
	Box() {}
	Box(double d, double shr, double z1) :Rect(d, shr) {
		z = z1; v = 0;
	}
	double area() { s = 4 * z*d1 + 2 * d1*sh; return s; }
	double vb() { v = Rect::area()*z; return v; }
	void print() { cout << "*** Ploshad S= ***" << s << endl; }
	friend double sum(Box *a);
	
};

class Prizma :public Rect {
	double z, v;
public:
	Prizma() {}
	Prizma(double d, double shr, double z1) :Rect(d, shr) { z = z1; v = 0; }
	double area() { s = (4 * z*d1 + 2 * d1*sh) / 2; return s; }
	double vb() { v = Rect::area()*z; return v / 2; }
	void print() { cout << "*** Ploshad S= ***" << s << endl; }
};

//drujestvennaya funkciya
double sum(Box *a) { return a->z + a->v; }

class Baza_Integral{
protected:
	float a, b, eps;
public:
	Baza_Integral() {
		a = 0; b = 0; eps = 0.1e10;
	}
	Baza_Integral(double av, double bv, double es) {
		a = av; b = bv; eps = es;
	}
	virtual double poisk_integral(double(*f)(double x)) {
		cout << "*** PREDOK POISK ***" << endl;
		return 0;
	}
	double get_a() { return a; }
	double get_b() { return b; }
};

double f1(double x) { return x*sin(x); }

class Int_trap_eps :public Baza_Integral {
public:
	double poisk_integral(double(*f)(double x)) {
		double s, sp, h, y, d;
		long int i, n; n = 50;
		sp = 1; d = 1;
		while (fabs(d) > eps) {
			h = (b - a) / n;
			s = (f(a) + f(b))*(h / 2);
			for (i = 1; i < n - 1; i++) {
				y = f(a + h*i);
				s += y*h;
			}
			d = s - sp;
			sp = s;
			n = n * 2;
		}
		return s;
	}
	Int_trap_eps() { Baza_Integral(); }
	Int_trap_eps(double av, double bv, double es) :Baza_Integral(av, bv, es) {}
};

class Int_rect_eps :public Baza_Integral {
public:
	double poisk_integral(double(*f)(double x)) {
		double s, sp, h, y, d;
		long int i, n; n = 50; sp = 1; d = 1;
		while (fabs(d) > eps) {
			h = (b - a) / n;
			for (i = 0, s = 0; i < n; i++) { y = f(a + h*i); s += y*h; }
			d = s - sp; sp = s; n = n * 2;
		}
		return s;
	}

	Int_rect_eps() { Baza_Integral(); }
	Int_rect_eps(double av,double bv,double es):Baza_Integral(av,bv,es){}
};

class Int_Parabol_eps :public Baza_Integral {
public:
	double integral(double(*f)(double x)) {
		double s, sp, h,y, d;
		long int i, n; n = 50; sp = 1; d = 1;
		while (fabs(d) > eps) {
			h = (b - a) / n;
			for (i = 1, s = (f(a) + f(b))*(h / 3); i < n - 1; i++) {
				y = f(a + h*i);
				if (i % 2)s += 2 * y*(h / 3);
				else s += 4 * y*(h / 3);
			}
			d = s - sp; sp = s; n = n * 2;
		}
		return s;
	}

	Int_Parabol_eps() { Baza_Integral(); }
	Int_Parabol_eps(double av, double bv, double es) :Baza_Integral(av, bv, es) {}
};