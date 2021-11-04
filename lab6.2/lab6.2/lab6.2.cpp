// lab6.2.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 19

#include <iostream>
#include <time.h>

using namespace std;

int *ArrayBuilder(int *a, const int size, const int i);
int MaxOddElement(int *a, const int size, const int i, int max);
void PrintArray(int *a, const int size, const int i);

int main() {
	srand((unsigned)time(NULL));

	int *a, n, max = 0;
	cout << "Enter n: "; cin >> n;
	
	a = new int[n];
	a = ArrayBuilder(a, n, 0);

	cout << "\nArray: ";
	PrintArray(a, n, 0);
	
	max = MaxOddElement(a, n, 0, max);
	if (max != 0)
		cout << "\nMax odd element: " << max << endl;
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

int MaxOddElement(int *a, const int size, const int i, int max) {
	if (i >= size) {
		return max;
	}
	else {
		if (a[i] % 2 == 1) {
			if (max == 0) max = a[i];
			else if (a[i] > max) max = a[i];
		}

		return MaxOddElement(a, size, i + 1, max);
	}
}

void PrintArray(int *a, const int size, const int i) {
	if (i < size) {
		cout << a[i] << " ";
		PrintArray(a, size, i + 1);
	}
	else
		cout << endl;
}