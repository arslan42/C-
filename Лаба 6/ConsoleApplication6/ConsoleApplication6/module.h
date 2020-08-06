#pragma once
#include <math.h>
#include <iostream>
using namespace std;

typedef double(*fun)(double x);
double f1(double x) { return x*sin(x); }
double f2(double x) { return -3 * x*cos(x); }

class Point {
	double x, y;
public:
	double rast() { return sqrt(x*x + y*y); }
	Point operator+(Point &t) {
		this->x = this->x + t.x;
		this->y = this->y + t.y;
		return *this;
	}
	Point *operator*(Point &t) {
		this->x *= t.y;
		this->y *= t.y;
		return this;
	}

	int operator>(Point &t) {
		if (this->x > t.x && this->y > t.y) return 1;
		else return 0;
	}

	Point operator=(Point &t) {
		this->x = t.x;
		this->y = t.y;
		return *this;
	}

	void move(Point &dt) {
		this->x += dt.x;
		this->y += dt.y;
	}

	double get_x() { return x; }
	double get_y() { return y; }

	Point() { x = 0; y = 0; }
	Point(double xv, double yv) { x = xv; y = yv; }
	Point(Point &t) { x = t.x; y = t.y; }
	Point wra_Point(double da) {
		Point t;
		t.x = x*cos(da);
		t.y = y*sin(da);
		return t;
	}
	void set(double xv, double yv) { x = xv; y = yv; }
};

class Baza_tab {
	float a, b;
protected:
	int n;
	Point *p;
public:
	Point * tabul(double(*f)(double x)){
		double h, x, y;
		int i;
		h = (b - a) / n;
		for (i = 0; i < n; i++) {
			x = a + h*i; y = f(x);
			p[i] = Point(x, y);
		}
		return p;
	}

	Baza_tab() { a = 0; b = 0; n = 1; }
	Baza_tab(double av, double bv, int nv) { a = av; b = bv; n = nv; p = new Point[n]; }
	int get_n() { return n;}
	float get_a() { return a; }
	float get_b() { return b; }
};

class Int_Rect :public Baza_tab {
public:
	double integral() {
		double s, h, x, y;
		int i;
		h = (p[n - 1].get_x() - p[0].get_x()) / n;
		for (i = 0, s = 0; i < n; i++) {
			s += p[i].get_y()*h;
		}
		return s;
	}
	Int_Rect() { Baza_tab::Baza_tab(); }
	Int_Rect(double av, double bv, int nv) :Baza_tab(av, bv, nv) {}

};

class Int_trap :public Baza_tab {
public:
	double integral() {
		double s, h, x, y;
		int i;
		h = (get_b() - get_a()) / n;
		s = ((p[n - 1].get_y()*p[0].get_y()));
		for (i = 1; i < n - 1; i++)
			s += p[i].get_y()*h;
		return s;
	}

	Int_trap() { Baza_tab::Baza_tab(); }
	Int_trap(double av, double bv, int nv) :Baza_tab(av, bv, nv) {}
};

class Rect {
	double d1, sh, s;
public:
	Rect() {}
	Rect(double d, double ch) { d1 = d; sh = ch; s = 0; }
	double area() { s = d1*sh; return s; }
};

class Box :public Rect {
	double z, v;
public:
	Box() {}
	Box(double d, double shr, double z1) :Rect(d, shr) { z = z1; v = 0; }
	double vb() { v = Rect::area()*z; return v; }
};