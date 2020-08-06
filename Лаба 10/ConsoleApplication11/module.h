#pragma once

#include <iostream>
using namespace std;
int ac[] = { 8,21,5,9,7,4,23,1,9,5,21,8 };

template <class T>
class Matrix {
	T **a;
	int n, m;
public:
	Matrix() { n = 0; m = 0; a = 0; }
	~Matrix() {
		if (n > 0) for (int i = 0; i < n; i++) delete[]a[i];
		if (a != 0)delete a; n = 0; m = 0; cout << " DESTRUCTION! " << endl;
	}
	Matrix(int n1, int m1) {
		n = n1; m = m1; a = new T*[n];
		for (int i = 0; i < n; i++)
			a[i] = new T[m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = 0;
	}
	Matrix(const Matrix &); // Konstruktor kopirovaniya
	Matrix & Matrix::operator=(const Matrix &r);
	Matrix * operator+(Matrix &r);
	Matrix & transponirov();
	Matrix * operator*(const Matrix &r);
	void setMatrix_const();
	void getMatrix();
	int get_n(); 
	int get_m();
	double gaus_t();

	friend ostream &operator<<(ostream &out, const Matrix <T> &r) {
		for (int i = 0; i < r.n; i++) {
			for (int j = 0; j < r.m; j++)
				out << r.a[i][j] << " ";
			out << std::endl;
		}
		return out;
	}

	friend istream & operator>>(istream & in, Matrix<T> &r) {
		for (int i = 0; i < r.n; i++)
			for (int j = 0; j < r.m; j++)
				in >> r.a[i][j];
		return in;
	}

};

/*
template <class T>
Matrix<T>::Matrix(int n1, int m1){
	n=n1;m=m1; a=new T*[n];
	for(int i=0;i<n;i++) a[i]=new T[m];
}
*/

template <class T> void Matrix<T>::setMatrix_const() {
	for (int i = 0, k = 0; i < n; i++)
		for (int j =0 ; j < m; j++)
			a[i][j] = ac[k++];
}

template <class T> void Matrix<T>::getMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << " " << a[i][j];
		cout << std::endl;
	}
}

template <class T> int Matrix<T>::get_n() { return n; }
template <class T> int Matrix<T>::get_m() { return m; }

template <class T> Matrix<T>::Matrix(const Matrix<T> &r) {
	int i, j;
	//n=r.n; m=r.n; a=new T*[n]; for(i=0;i<n;i++) a[i]=new T[m];
	Matrix<T>::Matrix(r.n, r.m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = r.a[i][j];
}

template <class T>
Matrix<T> & Matrix<T>::operator=(const Matrix <T> &r) { //operator prisvaivaniya
	if(&r!=this){ //ne samoprisvaivanie
		if (n != r.n || m != r.m) {
			Matrix<T>::~Matrix();
			/*n=r.n; m=r.m; a=new T*[n]; for(int i=0;i<n;i++) a[i]=new T[m]; */
			Matrix<T>::Matrix(r.n, r.m);
		} 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a[i][j] = r.a[i][j];
		return *this;
	
	}
}

template <class T>
Matrix<T> * Matrix<T>::operator+(Matrix<T> &r) {
	Matrix *z;
	z = new Matrix<T>(n, m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			z->a[i][j] = a[i][j] + r.a[i][j];
	return z;
}

template <class T>
Matrix<T> * Matrix <T>::operator*(const Matrix &r) {
	Matrix *z; 
	int k;
	z = new Matrix<T>(n, r.m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < r.m; j++)
			for (k = 0, z->a[i][j] = 0; k < m; k++)
				z->a[i][j] += a[i][j] * r.a[k][j];
	return z;

}
template <class T>
Matrix<T> & Matrix<T>::transponirov() {
	int i, j;
	Matrix *fp = new Matrix<T>(m, n);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			fp->a[j][i] = a[i][j];
	return *fp;
}

template <class T> double Matrix<T>::gaus_t() {
	int i, j, k, l, jmax, flag;
	double det, buf, t;

	for(k=0;k<n-1;k++)
		for(i=k+1;i<n;i++)
			if (a[k][k] != 0) {
				buf = a[i][k] / a[k][k];
				for (j = k; j < n; j++)
					a[i][j] = a[i][j] - a[k][j] * buf;
			}
			else {
				cout << " net resheniya " << endl;
				return 0;
			}
			for (i = 0, det = 1; i < n; i++)
				det *= a[i][j];
			return det;
}
