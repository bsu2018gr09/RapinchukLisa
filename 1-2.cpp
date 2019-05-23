//Неотрицательные элементы (случайные числа) массива А(N), где N=100000 переставить в конец массива, сохраняя порядок следования. 
//Отрицательные элементы расположить в порядке убывания. Дополнительный массив не использовать.

#include <iostream>
#include <clocale>

using namespace std;

int* newArray(int* pA, int *n) {
	cout << "Введите n " << '\n';
	cin >> *n;
	pA = new (nothrow) int[*n];
	if (!pA) cout << "Ошибка выделения памяти" << '\n';
	return pA;
}

int* deleteA(int* pA) {
	delete[] pA;
	pA = nullptr;
	return pA;
}

void randomInitArray(int *pA, int n)
{
	int max, min;
	cout << "Введите диапазон значений";
	cin >> min >> max;
	if (min > max) swap(min, max);
	for (int* p = pA; p < pA + n; p++) {
		*p = min + rand()%(max-min+1);
	}
}

void printA(int *A, int n) {
	for (int* p = A; p < A + n; p++) {
		cout << *p << " ";
	}
	cout << '\n';
}

void task(int *A, int n) {
	for (int* p = A; p < A + n; ) {
		if (*p < 0) {
			for (int* pp = p; (pp > A); pp--) {
				if (*(pp - 1) >= 0 || *(pp - 1) < *pp)
					swap(*pp, *(pp - 1));
			}
		}
		p++;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	int n;
	int* pA = nullptr;
	pA = newArray(pA, &n);
	randomInitArray(pA, n);
	printA(pA, n);
	cout << '\n';
	task(pA, n);
	printA(pA, n);
	deleteA(pA);
	system("pause");
	return 0;
}