#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void printMenu() {
	cout << "*** Viberite kak otsortirovat massiv" << endl;
	cout << "- vvedite 1 dlya sort1" << endl;
	cout << "- vvedite 2 dlya sort2" << endl;
	cout << "- vvedite 3 dlya sort3" << endl;
}

void swap1(int *a, int *b) {
	int buf;
	buf = *a;
	*a = *b;
	*b = buf;
}

void swap2(int &a, int &b) {
	int buf;
	buf = a;
	a = b;
	b = buf;
}

void sort1(int *arr, int N) {
	int flag;
	do {
		flag = 0;
		for (int i = 0; i < N - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap2(arr[i], arr[i + 1]);
				flag = 1;
			}
		}
	} while (flag);
}

void sort2(int *arr, int N) {
	int buf;
	for (int i = 1; i < N; i++) {
		buf = arr[i];
		int j = 0;
		while (j < i - 1 && buf >= arr[j]) {
			j++;
		}
		if (buf <= arr[j]) {
			for (int k = i - 1; k >= j; k--) {
				arr[k + 1] = arr[k];
				arr[k] = buf;
			}
		}
	}
}

void sort3(int *arr, int N) {
	int buf;
	for (int i = 1; i < N; i++) {
		buf = arr[i];
		int j = 0;
		while (j < i - 1 && buf >= arr[j])
			j++;
		if (buf <= arr[j])
			for (int k = i - 1; k >= j; k--) {
				swap2(arr[k + 1], arr[k]);
				arr[k] = buf;
			}
	}
}

int get_index(int *arr, int N, int num) {
	if (N > 4) {
		int index = -1;
		for (int i = 0; i < N; i++) {
			if (arr[i] == num) {
				index = i;
				break;
			}
		}
		return index;
	}
}
int *setRandomMatrix(int *arr, int N) {
	cout << "*** Randomnii massiv: ***" << endl;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % 10;
		cout << arr[i] << ' ';
	}
	cout << endl;
	return arr;
}
void printMatrix(int *arr, int N) {
	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';
	cout << endl << endl;
};