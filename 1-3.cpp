﻿//Элементы массива А(N), значения которых – простые числа, 
//расположить в порядке возрастания, не нарушая порядка следования других элементов.

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;


void writeArray(int* arr, const int size) {
	for (int i = 0; i < size; i++) cout << *(arr + i) << " ";
	cout << endl;
}

bool isSimple(int n) {
	if (abs(n) == 2) return true;
	else if (abs(n) <= 1 || abs(n) == 0) return false;
	int end = sqrt(abs(n));
	for (int i = 2; i <= end; i++) if (n%i == 0) return false;
	return true;
}

void numbers(int& a, int& b, int& size) {
	cout << "Диапазон чисел (a,b): ";
	cin >> a >> b;
	cout << "Размер массива: ";
	cin >> size;
}

void randomArray(int* arr, int size, const int min, const int max) {
	srand(time(0));
	for (int i = 0; i < size; i++) *(arr + i) = rand() % 10;
}

void deleteMemory(int* arr) {
	delete[] arr;
	arr = nullptr;
}

int* getMemory(int size) {
	int* arr = new int[size];
	if (!arr) exit(1);
	return arr;
}

void sort(int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		int* now = nullptr;
		int* bf = nullptr;
		for (int* j = arr; j < arr + size; j++) {
			if (now && isSimple(*j) && (*j < *now)) { swap(*now, *j);	bf = now; now = j; }
			else if (isSimple(*j)) { bf = now; now = j; }
		}
	}
}

int main() {

	setlocale(LC_ALL, "Russian");
	int size, min, max;
	numbers(min, max, size);
	int* arr = getMemory(size);
	randomArray(arr, size, min, max);
	writeArray(arr, size);
	sort(arr, size);
	writeArray(arr, size);
	deleteMemory(arr);
	system("pause");
	return 0;
}
