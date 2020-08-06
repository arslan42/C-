#pragma once
#include <iostream>
using namespace std;

class Point {
	double x, y;
public:
	double rast() { return sqrt(x*x + y*y); }
	double rast_t(Point &t1) { return sqrt((t1.x - x)*(t1.x - x) + (t1.y - y)*(t1.y - y)); }
	void move(Point &dt) {
		this->x += dt.x;
		this->y += dt.y;
	}
	double get_x() { return x; }
	double get_y() { return y; }
	Point() { x = 0; y = 0; }
	Point(double xv, double yv) {
		x = xv;
		y = yv;
	}
	Point wra_Point(double da);
	void set(double xv, double yv) { x = xv; y = yv; }
};

//opisanie metoda klassa
Point Point::wra_Point(double da) {
	Point t;
	t.x = x*cos(da);
	t.y = y*sin(da);
	return t;
}

class Line {
	double k, b;
	Point t1, t2;
public:
	Line() {};
	Line(double kv, double bv) {
		k = kv;
		b = bv;
	}
	void set(double kv, double bv) { k = kv; b = bv; }
	double get_k() { return k; }
	double get_b() { return b; }

	double point_x() { return -k / b; }
	double point_y() { return b; }
	int prov(Line &l1) {
		if (k == l1.k && b == l1.b) return -1;
		else if (k == l1.k) return 0;
		else return 1;
	}
	int prov_t(Point &t) {
		if (t.get_y() > t.get_x()*k + b) return 1;
		else if (t.get_y() == t.get_x()*k + b) return 0;
		else return -1;
	}
};

class Okr {
	double r;
	Point centr;
public:
	int prov(Okr &pt) {
		double r1;
		Point t;
		t = pt.centr;
		/*
		r1=centr.rast_t(pt.centr);
		if(r1<pt.r+r) return 1;
		else if (r1<pt.r || r1<r) return 0;
		else return -1;
		*/
		if (centr.rast_t(pt.centr) < r + pt.r) return 1;
		if (centr.rast_t(pt.centr) < pt.r ||
			centr.rast_t(pt.centr) < r) return 0;
		if (centr.rast_t(pt.centr) > r + pt.r) return -1;
	}

	int prov_t(Point &t1) {
		double x1, x2;
		x1 = t1.get_x() - centr.get_x();
		x2 = t1.get_y() - centr.get_y();
		if ((x1*x1 + x2*x2) < r*r) return 1;
		else return 0;
	}

	Point get_c() { return centr; }
	double get_r() { return r; }
	Okr() {}
	Okr( Point pt, double rv){centr = pt; r = rv; } 
	Okr(Okr &pt1) {
		centr = pt1.centr; r = pt1.r;
	}
	void set(Point pt, double rv) { centr = pt; r = rv; }

};

double **matr_rast(Point *b, int n) {
	double **a;
	int i, j;
	a = new double*[n];
	for (i = 0; i < n; i++)
		a[i] = new double[n];
	for (i = 0; i < n-1; i++)
		for (j = i + 1; j < n; j++)
			a[i][j] = b[i].rast_t(b[j]);
	return a;
}

template <class T>
int **matr_prov(T *b, int n) {
	int **a;
	int i, j;
	a = new int*[n];
	for (i = 0; i < n; i++)
		a[i] = new int[n];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			a[i][j] = b[i].prov(b[j]);
	return a;
}

template<class T>
void print_matr(T **a, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

template <class T>
void del_matr(T **a, int n, int m) {
	for (int i = 0; i < n; i++)
		delete[]a[i];
	delete[]a;
}
