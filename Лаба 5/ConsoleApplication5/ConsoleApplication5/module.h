#pragma once
#include <iostream>
using namespace std;

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



//vkluchenie Baza_tab
typedef double(*fun)(double x);
double f1(double x) { return x*sin(x); }
double f2(double x) { return x*sin(x) + x*cos(x); }
double f3(double x) { return x*cos(x) + 3; }

class Baza_tab {
	float a, b;
	int n;
public:
	Point *p;
	Point *p_in;
	int kol_in;
	Point *tabul(double(*f)(double x)) {
		double h, x,y;
		int i;
		for (i = 0, h = (b - a) / n, x = a; i < n; i++) {
			x += h;
			y = f(x);
			p[i] = Point(x, y);
		}
		return p;
	}

	Point * interwal_nul() {
		int i, j;
		Point *dt;
		dt = new Point[n];
		for(i=0,j=0;i<n-2;i++)
			if (p[i].get_y()*p[i + 1].get_y() < 0) {
				dt[j] = Point(p[i].get_x(), p[i + 1].get_x()); //set(p[i].get_x(),p[i+1].get_x());
				j++;
			}
		p_in = new Point[j];
		for (i = 0; i < j; i++) p_in[i] = dt[i];
		kol_in = j; delete dt; return p_in;
	}

	void Destroy() {
		if (n > 0) { delete[]p; n = 0; }
		if (kol_in > 0) { delete[]p_in; kol_in = 0; }
	}

	Baza_tab() { a = 0; b = 0; n = 0; kol_in = 0; }
	Baza_tab(double av, double bv, int nv) { a = av; b = bv; n = nv; p = new Point[n]; kol_in = 0; }

	~Baza_tab() { cout << " DESTROY! " << endl; Destroy(); }
	int get_n() { return n; }
	float get_a() { return a; }
	float get_b() { return b; }
};