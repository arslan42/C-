#pragma once
#include <iostream>
using namespace std;

class Baza_poisk {
protected:
	float a, b;
public:
	Baza_poisk() { a = 0; b = 0; }
	Baza_poisk(double av, double bv) { a = av; b = bv; }
	virtual double poisk(double(*f)(double x)) {
		cout << " predok poisk " << endl;
		return 0;
	}
	double get_a() { return a; }
	double get_b() { return b; }
	void set(double av, double bv) { a = av; b = bv; }
	//virtual double poisk(double (*f)(double x))=0;
};

class Met_xord :public Baza_poisk {
public:
	double poisk(double(*f)(double x)) {
		double d, xt, xp, fa, fb, fx, eps = 0.1e-13;
		int n;
		fa = f(a);
		fb = f(b);
		xt = a - fa*((b - a) / (fb - fa));
		d = 1;
		n = 0;
		fx = f(xt);
		while (fabs(fx) > eps && n < 10000) {
			if (fa*fx < 0) {
				b = xt;
				fb = fx;
			}
			else {
				a = xt;
				fa = fx;
			}
			xt = a - fa*((b - a) / (fb - fa));
			fx = f(xt);
			n++;
		} //cout<<endl<<" xord0 N "<<n<<endl;
		return xt;
	}

	Met_xord() { Baza_poisk(); }
	Met_xord(double av, double bv) :Baza_poisk(av, bv) {}

};

class Pol_Del :public Baza_poisk {
public:
	double poisk(double(*f)(double x)) {
		int i = 0;
		double c, eps = 0.1e-11;
		c = (a + b) / 2;
		while (fabs(f(c)) > eps && fabs(b - a) > eps && i < 50000) {
			c = (a + b) / 2;
			if (f(a)*f(c) < 0) b = c;
			else a = c;
			i++;
		}
		return c;
	}
	Pol_Del() { Baza_poisk(); }
	Pol_Del(double av, double bv) :Baza_poisk(av, bv) {}
};

class Met_newton :public Baza_poisk {
public:
	double poisk(double(*f)(double x)) {
		double xp, xt, d, h, fp, pfa, pfb, eps = 0.1e-12;
		int i = 0;
		h = 0.1e-11;
		//pfa=(f(a+h)-2*f(a)+f(a-h)/(2*h);
		//pfb=(f(b+h)-2*f(b)+f(b-h))/(2*h);
		d = 1; xp = a; i = 0;
		while (fabs(d) > eps && i < 200) {
			fp = (f(xp + h) - f(xp)) / h;
			if (fabs(fp) > 0.1e-11)
				xt = xp - f(xp) / fp;
			else break;
			d = (xt - xp);
			xp = xt;//tekushee perepisivaetsa v predidushee
			i++;
		}
		return xt;
	}
	Met_newton() { Baza_poisk(); }
	Met_newton(double av, double bv) :Baza_poisk(av, bv) {}
};

//Modul poiska kornya i extremuma

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
	Point *p; int n;
public:
	Point *p_in;
	Point *tabul(double(*f)(double x)) {
		double h, x, y;
		int i;
		for (i = 0, h = (b - a) / n, x = a; i < n; i++) {
			y = f(x);
			x += h;
			p[i] = Point(x, y);
		}
		return p;
	}
	
	void Destroy() {
		if (n > 0) { delete[]p; n = 0; }
	}

	Baza_tab() { a = 0; b = 0; n = 0; }
	Baza_tab(double av, double bv, int nv) {
		a = av; b = bv; n = nv; p = new Point[n];
	}
	~Baza_tab() { cout << " DESTROY! " << endl; Destroy(); }
	int get_n() { return n;}
	float get_a() { return a; }
	float get_b() { return b; }
};

class Interval_nul :public Baza_tab {
public:
	int kol_in;
	Point *p_in;
	Point *interwal_nul() {
		int i, j;
		Point *dt;
		dt = new Point[n];
		for(i=0,j=0;i<n-1;i++)
			if (p[i].get_y()*p[i + 1].get_y() < 0) {
				dt[j].set(p[i].get_x(), p[i + 1].get_x());
				j++;
			}
		p_in = new Point[j];
		for (i = 0; i < j; i++) p_in[i] = dt[i];
		kol_in = j;
		delete[]dt;
		return p_in;
	}
	
	Interval_nul() :Baza_tab() {}
	Interval_nul(double av, double bv, int nv) :Baza_tab(av, bv, nv) { kol_in = 0; }
	~Interval_nul() { cout << " DESTROY Interval_nul " << endl; Destroy(); 
	Baza_tab::~Baza_tab();
	}
	void Destroy() { if (kol_in > 0) { delete[]p_in; kol_in = 0; } }
};

class Interval_extrum_max :public Baza_tab {
public:
	int kol_in;
	Point *pm;
	Point *extrum_max() {
		int i, j;
		Point *dt;
		dt = new Point[n];
		for(i=1,j=0;i<n-1;i++)
			if (p[i].get_y() > p[i + 1].get_y() && p[i].get_y() > p[i - 1].get_y()) {
				dt[j].set(p[i - 1].get_x(), p[i + 1].get_x());
				j++;
			}
		pm = new Point[j];
		for (i = 0; i < j; i++) pm[i] = dt[i];
		kol_in = j; delete[]dt;
		return pm;
	}

	Interval_extrum_max() :Baza_tab() {}
	Interval_extrum_max(double av, double bv, int nv) :Baza_tab(av, bv, nv) { kol_in = 0; }

	void Destroy() { if (kol_in = 0) { delete[]pm; kol_in = 0; } }
	~Interval_extrum_max() { cout << " DESTROY Interval_extrum_max " << endl; Destroy(); 
	//Baza_tab::~Baza_tab();
	}
};

