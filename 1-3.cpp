//Элементы массива А(N), значения которых – простые числа, расположить в порядке возрастания, 
//не нарушая порядка следования других элементов.

#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iomanip>

using namespace std;


void writeNumbers(int* min, int* max, int* size) {
	cout << "Диапазон чисел: \n";
	cin >> *min >> *max;
	if (*min > *max) swap(*min, *max);
	cout << "Размер массива: ";
	cin >> *size;
}

void randomInitArray(int* arr, int n, const int min, const int max) {
	srand(time(0)); 
	for (int* p = arr; p < arr + n; p++) {
		*p = min + rand() % (max - min + 1);
	}
}

void printArray(int* arr, const int size) {
	for (int i = 0; i < size; i++) cout << setw(4) <<*(arr + i) << " ";
	cout << endl;
}

bool isPrime(int n) {
	if (abs(n) == 2) return true;
	else if (abs(n) <= 1 || abs(n) == 0) return false;
	int end = sqrt(abs(n));
	for (int i = 2; i <= end; i++) if (n%i == 0) return false;
	return true;
}


void deleteMemory(int* arr) {
	delete[] arr;
	arr = nullptr;
}

int* getMemory(int size) {
	int* arr = new (nothrow) int[size];
	if (!arr) exit(1);
	return arr;
}

void sort(int* arr, const int size) {
	for (int i = 0; i < size; i++) {
		int* now = nullptr;
		int* bf = nullptr;
		for (int* j = arr; j < arr + size; j++) {
			if (now && isPrime(*j) && (*j < *now)) { swap(*now, *j);	bf = now; now = j; }
			else if (isPrime(*j)) { bf = now; now = j; }
		}
	}
}

int main() {

	setlocale(LC_ALL, "Russian");
	int size, min, max;
	writeNumbers(&min, &max, &size);
	int* Arr = getMemory(size);
	randomInitArray(Arr, size, min, max);
	printArray(Arr, size);
	sort(Arr, size);
	printArray(Arr, size);
	deleteMemory(Arr);
	system("pause");
	return 0;
}