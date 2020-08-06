#pragma once
#include <iostream>
using namespace std;

template <class T>
void printmas(T *f, int n) {
	int i;
	cout << "*** Massiv ***" << endl;
	for (i = 0; i < n; i++)
		cout << f[i] << " ";
}

template <class T>
void scalar1(T *a, T *b, T *s, int n) {
	int i, j;
	for (i = 0, *s = 0; i < n; i++)
		*s += (a[i] * b[i]);
}

template <class T>
T scalar(T *a, T *b, int n) {
	int i, j;
	T s;
	for (i = 0, s = 0; i < n; i++)
		s += (a[i] * b[i]);
	return s;
}

template <class T>
T sum_el(T *a, int m) {
	int sum, j;
	for (j = 0, sum = 0; j < m; j++)
		sum += a[j];
	return sum;
}

template <class T>
void swap(T *x, T *y) {
	T buf;
	buf = *x;
	*x = *y;
	*y = buf;
}


void swaps(int &x, int &y) {
	int buf;
	buf = x;
	x = y;
	y = buf;
}

void swap_mas(int *x, int *y, int n) {
	int i;
	for (i = 0; i < n; i++)
		swap((x + i), (y + i));
}

template <class T>
void swap_mas(T *x, T *y, int n) {
	int i;
	for (i = 0; i < n; i++)
		swap((x + i), (y + i));
}

template <class T>
void sort_pob(T *a, int n) {
	int i, flag;
	flag = 1;
	while (flag) {
		flag = 0;
		for(i=0;i<n-1;i++)
			if (a[i] > a[i + 1]) {
				swaps(a[i], a[i + 1]);
				flag = 1;
			}
	}
}

template <class T>
void sort_wst(T *a, int n) {
	int i, j, k, flag;
	T buf;
	for (i = 1; i < n; i++) {
		//do indeksa i-1 chast massiva otsortirovana
		buf = a[i];//element dlya vstavki
		j = 0;
		//cikl poiska mesta dlya vstavki
		while ((j < i - 1) && (buf >= a[j]))
			j++;
		if (buf <= a[j]) {
			//sdvig elementov v otsortirovannoi chasti massiva
			//dlya vstavki ot granici (i-1) do a[j]
			for (k = i - 1; k >= j; k--) //sdvig vpravo
				a[k + 1] = a[k];
			a[j] = buf;//zapisivaetsya na mesto vstavki
		}
	}
}

int ** w_matr(int n, int m) {
	int i, j, **s;
	s = new int*[n];
	for (i = 0; i < n; i++)
		*(s + i) = new int[m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> s[i][j];
	return s;
}

template <class T>
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
	for (int i = 0; i < n; i++) {
		delete[]a[i];
		delete[]a;
	}
}

template <class T>
T **sum_matr(T **a, T **b, int n, int m) {
	int i, j;
	T **s;
	s = new T *[n];
	for (i = 0; i < n; i++)
		*(s + i) = new T[m];
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			*(*(s + i) + j) = *(*(a + i) + j) + *(*(b + i) + j);
	return s;
}

template <class T>
void sort_strok_wst(T **a, int n, int m) {
	int i,flag;
	for (i = 0; i < n; i++)
		sort_wst(a[i], m);
}

template <class T>
void wwod1_Matr(T **s, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> *(*(s + i) + j);
}