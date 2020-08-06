#pragma once
#include <iostream>
using namespace std;

//opisanie strukturi Point, Okr

struct point { double x, y, r; };
struct okr{ point cent; float rad; };
struct line { double k, b, r; point t1, t2; };

void vivod_to(int n, point *a);
double rast(point &t1, point &t2);
int prov(okr &t1, okr &t2);
line lin_fun(point &t1, point &t2);
typedef double(*fun)(double x);

double rast0(point &t1) { return sqrt(t1.x*t1.x + t1.y*t1.y); }
double rast(point &t1, point &t2) {
	return sqrt(((t1.x - t2.x)*(t1.x - t2.x) + (t1.y - t2.y)*(t1.y - t2.y)));
}
int prov(okr &t1, okr &t2) {
//vizov funkcii rast()
	if (rast(t1.cent, t2.cent) < (t1.rad + t2.rad)) return 1;
	if (rast(t1.cent, t2.cent) < t1.rad || rast(t1.cent, t2.cent) < t2.rad) return 0;
	if (rast(t1.cent, t2.cent) > (t1.rad + t2.rad)) return -1;
}

line lin_fun(point &t1, point &t2) {
	line t;
	t.t1 = t1;
	t.t2 = t2;
	t.k = (t1.y - t2.y) / (t1.x - t2.x);
	t.b = t1.y - t.k*t1.x;
	t.r = rast(t.t1, t.t2);
	return t;
}

void form_r(int n, point *z, double **a) {
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++) {
			
			*(*(a + i) + j) = rast(*(z + i), *(z + j));
			
		}
}

void vvod_to(int n, point *a) {//vvod
	int i; point *p;
	for (i = 0, p = a; i < n; p++, i++)
		cin >> p->x >> p->y;
}

void vivod_to(int n, point *a) {
	int i; point *p;
	cout << "*** Massiv ***" << endl;
	for (i = 0, p = a; i < n; p++, i++)
		cout << " x=" << p->x << ", y=" << p->y << " " << endl;
}

int ** form_okr(int n, okr *z) {
	int i, j; int **a;
	a = new int*[n];
	for (i = 0; i < n; i++)
		*(a + i) = new int[n];
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			*(*(a + i) + j) = prov(*(z + i), *(z + j));//vizov funkcii proverki polojeniya
	return a;
}

line ** form_matr_line(int n, point *z) {
	int i, j;
	line **a;
	a = new line *[n];
	for (i = 0; i < n; i++)
		*(a + i) = new line[n];
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			*(*(a + i) + j) = lin_fun(*(z + i), *(z + j));//vizov proverki polojeniya
	return a;
}

double f1(double x) { return x*sin(x); }
double f0(double x) {
	if (cos(x / 2))return sin(x / 2) / cos(x / 2) - x;
}
double f3(double x) { return exp(x / 5) - x; } //x*x-0.04
double f2(double x) { return atan(x) - 0.5 + (x - 1)*(x - 1)*(x - 1); }
double f4(double x) { return cos(x)*x; }

point * tabul(double a, double b, int n, double(*f)(double x)) {
	double h, x, y;
	int i;
	point *p = new point[n];
	//for(i=0,h=(b-a)/n;i<n;i++)
	//{p[i].x=a+h*i; p[i].y=f(p[i].x);}
	for (i = 0, h = (b - a) / n, p[0].x = a; i < n; i++) {
		p[i].y = f(p[i].x);
		p[i + 1].x = p[i].x + h;
	}
	return p;
}



