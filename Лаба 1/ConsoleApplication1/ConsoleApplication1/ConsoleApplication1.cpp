// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include "module.h"

int main() {
	const int n = 5;
	int *arr=new int[n];
	int chooseMenu = 1;
	int chooseUser;
	srand((unsigned)time(NULL));
	arr = setRandomMatrix(arr, n);

	while (chooseMenu) {
		cout << endl;
		printMenu();
		cin >> chooseUser;
		if (chooseUser == 1) {
			cout << "*** Vibrana sortirovka 1 ***" << endl;
			sort1(arr, n);
			chooseMenu = 0;
		} else
		if (chooseUser == 2) {
			cout << "*** Vibrana sortirovka 2 ***" << endl;
			sort2(arr, n);
			chooseMenu = 0;
		} else
		if (chooseUser == 3) {
			cout << "*** Vibrana sortirovka 3 ***" << endl;
			sort3(arr, n);
			chooseMenu = 0;
		}
		else
			cout << "*** Vvedite korrektnii nomer sortirovki ***" << endl;
	}
	
	printMatrix(arr, n);

	int num = arr[4];
	cout <<endl<< "*** Element massiva #4=" << num << " ***" << endl;
	int index = get_index(arr, n, num);
	cout <<endl<< "*** Index chisla " << num << " - " << index << " ***" << endl;
	delete[]arr;
	

	system("pause");
	return 0;
}