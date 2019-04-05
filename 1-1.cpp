//	Даны точки плоскости своими координатами в виде двух одномерных массивов(случайные числа).
//	Точки плоскости рассортировать по возрастанию расстояния до прямой ax + by + c = 0.
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

void printPoint(int* X, int* Y, double* S, int N) {
	cout << "  X  Y " << "Расстояние\n\n";
	for (int i = 0; i < N; i++) cout << setw(3) << *(X + i) << setw(3) << *(Y + i) << ' ' << *(S + i) << endl;
	cout << endl;
}

void task(int *X, int *Y, double *S, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (*(S + j) > *(S + j + 1)) {
				swap(*(S + j), *(S + j + 1));
				swap(*(X + j), *(X + j + 1));
				swap(*(Y + j), *(Y + j + 1));
			}
		}
	}
}

void length(double* S, int* X, int* Y, int size, double a, double b, double c) {
	while (size > 0) { *(S++) = (abs(*(X++)*a + *(Y++)*b + c) / sqrt((a*a) + (b*b))); size--; }
}

void randomArray(int* arr, int size, int range) {
	srand(time(0));
	for (int i = 0; i < size; i++) *(arr + i) = rand() % range;
}

void deleteMemory(void* arr) {
	delete[] arr;
	arr = nullptr;
}

int* getMemoryInt(int size) {
	int* arr = new int[size];
	if (!arr) exit(1);
	return arr;
}

double* getMemoryDouble(int size) {
	double* arr = new (nothrow) double[size];
	if (!arr) exit(1);
	return arr;
}

void numbers(int& range, int& size, double& a, double& b, double& c) {
	cout << "\nКоэффиценты квадратного уравнения: ";
	cin >> a >> b >> c;
	cout << "\nДиапазон значений: ";
	cin >> range;
	cout << "\nРазмер массива: ";
	cin >> size;
}

int main() {

	setlocale(LC_ALL, "Russian");
	int size, range;
	double a, b, c;
	numbers(range, size, a, b, c);
	int* arrX = getMemoryInt(size);
	int* arrY = getMemoryInt(size);
	double* arrT = getMemoryDouble(size);
	randomArray(arrX, size, range);
	randomArray(arrY, size, range);
	length(arrT, arrX, arrY, size, a, b, c);
	printPoint(arrX, arrY, arrT, size);
	task(arrX, arrY, arrT, size);
	printPoint(arrX, arrY, arrT, size);
	deleteMemory(arrT);
	deleteMemory(arrX);
	deleteMemory(arrY);
	system("pause");
	return 0;
}
