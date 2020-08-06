#pragma once
#include <iostream>
using namespace std;

int ac[] = { 8,0,0,0,7,4,23,1,9,5,21,8 };

class Matrix {
	int **a;
	int n, m;
public:
	Matrix() { n = 0; m = 0; }
	Matrix(int n1, int m1) {
		n = n1; m = m1;
		a = new int*[n];
		for (int i = 0; i < n; i++) a[i] = new int[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) a[i][j] = 0;
	}
	~Matrix() {
		if (n > 0) 
			for (int i = 0; i < n; i++) delete[]a[i];
		if (a != 0) delete a; n = 0; m = 0;
		cout << " DESTRUCT! " << endl;
	}

	Matrix (const Matrix &);//konstruktor kopirovaniya
	Matrix & operator=(const Matrix &);//prisvaivanie
	Matrix * operator+(const Matrix &);
	Matrix * operator*(const Matrix &);
	Matrix & operator-(const Matrix &);
	//Matrix operator-(const Matrix &);
	Matrix * Kol_0();
	void setMatrix();
	void setMatrix_const();
	void getMatrix();
	int get_n();
	int get_m();
	
	//peregruzka operatora-

	Matrix & operator++();
	Matrix & transponirov();
	friend ostream & operator<<(ostream &out, const Matrix &r);
	friend istream & operator>>(istream & in, Matrix &);

};

//metodi
	//konstruktor kopirovaniya
Matrix::Matrix(const Matrix &r) {
	int i, j;
	n = r.n; m = r.m;
	a = new int*[n];
	for (i = 0; i < n; i++) a[i] = new int[m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = r.a[i][j];
}

//operator prisvaivaniya
Matrix & Matrix::operator=(const Matrix &r) {
	if (&r != this) { //ne samoprisvaivanie
		if (n != r.n || m != r.m) {
			Matrix::~Matrix();
			n = r.n; m = r.m;
			a = new int*[n];
			for (int i = 0; i < n; i++) a[i] = new int[m];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = r.a[i][j];
		return *this;
	}
}

Matrix & Matrix::transponirov() {
	int i, j;
	Matrix *fp = new Matrix(m, n);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			fp->a[j][i] = a[i][j];
	return *fp;
}

void Matrix::setMatrix() {
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> a[i][j];
}

void Matrix::setMatrix_const() {
	for (int i = 0, k = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = ac[k++];
}

void Matrix::getMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << " " << a[i][j];
		cout << std::endl;
	}
}

int Matrix::get_n() { return n; }
int Matrix::get_m() { return m; }

Matrix * Matrix::operator+(const Matrix &r) {
	Matrix *z;
	z = new Matrix(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			z->a[i][j] = a[i][j] + r.a[i][j];
	return z;
}

Matrix * Matrix::Kol_0() {
	Matrix *z; 
	z = new Matrix(n, 1);
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (a[i][j] == 0)
				(z->a[i][0])++;
	return z;
}

Matrix * Matrix::operator*(const Matrix &r) {
	Matrix *z;
	int k;
	z = new Matrix(n, r.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < r.m; j++)
			for (k = 0, z->a[i][j] = 0; k < m; k++)
				z->a[i][j] += a[i][j] * r.a[k][j];
	return z;
}

Matrix & Matrix::operator++() {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j]++;
	return *this;
}

//peregruzka operatora -
Matrix & Matrix::operator-(const Matrix &fp1) {
	int i, j;
	if (n == fp1.n && m == fp1.m) {
		Matrix *fp;
		fp = new Matrix(n, m);
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				fp->a[i][j] = a[i][j] - fp1.a[i][j];
		return *fp;
	}
}

ostream &operator<<(ostream &out, const Matrix &r) {
	for (int i = 0; i < r.n; i++) {
		for (int j = 0; j < r.m; j++)
			out << r.a[i][j] << " ";
		out << std::endl;
	}
	return out;
}

istream & operator>>(istream & in, Matrix &r) {
	for (int i = 0; i < r.n; i++)
		for (int j = 0; j < r.m; j++)
			in >> r.a[i][j];
	return in;
}

/*
Matrix Matrix::operator-(const Matrix &fp1){
	int i,j;
	if(n==fp1.n && m=fp1.m)
		Matrix *fp; 
		fp=new Matrix(n,m);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				fp->a[i][j]=a[i][j]-fp1.a[i][j];
	
	return *fp;
}
*/
