// lab6.2.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 19

#include <iostream>
#include <time.h>

using namespace std;

int *ArrayBuilder(int *a, const int size, const int i);
int MaxOddElement(int *a, const int size, const int i, int max, int indexMax);
void PrintArray(int *a, const int size, const int i);

int main() {
	srand((unsigned)time(NULL));

	int *a, n, index = -1;
	cout << "Enter n: "; cin >> n;
	
	a = new int[n];
	a = ArrayBuilder(a, n, 0);

	cout << "\nArray: ";
	PrintArray(a, n, 0);
	
	index = MaxOddElement(a, n, 0, 0, index);
	if (index != -1)
		cout << "\nMax odd element: " << a[index] << endl;
	else
		cout << "\nThere is no odd element in array.\n";

	return 0;
}

int* ArrayBuilder(int *a, const int size, const int i) {
	if (i >= size)
		return a;
	else {
		a[i] = rand() % 2001 - 1000;
		return ArrayBuilder(a, size, i + 1);
	}
}

int MaxOddElement(int *a, const int size, const int i, int max, int indexMax) {
	if (i >= size)
		return indexMax;
	else if (a[i] % 2 != 0)
		if (indexMax == -1) {
			max = a[i];
			indexMax = i;
		}
		else if (a[i] > max) {
			max = a[i];
			indexMax = i;
		}

	return MaxOddElement(a, size, i + 1, max, indexMax);
}

void PrintArray(int *a, const int size, const int i) {
	if (i < size) {
		cout << a[i] << " ";
		PrintArray(a, size, i + 1);
	}
	else
		cout << endl;
}