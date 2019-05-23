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

int getNextGap(int gap)
{
	gap = (int)gap / 1.25;
	if (gap < 1)
		return 1;
	return gap;
}

void combSort(double* S, int* X, int*Y, int n) {
	int gap = n;
	bool swapped = true;

	while (gap != 1 || swapped == true)
	{
		gap = getNextGap(gap);

		swapped = false;

		for (int i = 0; i < n - gap; i++)
		{
			if (S[i] > S[i + gap])
			{
				swap(S[i], S[i + gap]);
				swap(X[i], X[i + gap]);
				swap(Y[i], Y[i + gap]);
				swapped = true;
			}
		}
	}
}

void calculateLength(double* S, int* X, int* Y, int size, double a, double b, double c) {
	while (size > 0) {
		*(S++) = (abs(*(X++)*a + *(Y++)*b + c) / sqrt((a*a) + (b*b))); 
		size--; }
}


void randomInitArray(int *A, int N, int max, int min) {
	for (int i = 0; i < N; i++) *(A + i) = (rand() % max + min);
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

void writeNumbers(int& max, int& min, int& size, double& a, double& b, double& c) {
	cout << "\nКоэффиценты квадратного уравнения: ";
	cin >> a >> b >> c;
	cout << "\nДиапазон значений: ";
	cin >> min >> max;
	if (min > max) swap(min, max);
	cout << "\nРазмер массива: ";
	cin >> size;
}

int main() {

	setlocale(LC_ALL, "Russian");
	int size, max, min;
	double a, b, c;
	writeNumbers(max, min, size, a, b, c);
	int* arrX = getMemoryInt(size);
	int* arrY = getMemoryInt(size);
	double* arrT = getMemoryDouble(size);
	randomInitArray(arrX, size, max, min);
	randomInitArray(arrY, size, max, min);
	calculateLength(arrT, arrX, arrY, size, a, b, c);
	printPoint(arrX, arrY, arrT, size);
	combSort(arrT, arrX, arrY, size);
	printPoint(arrX, arrY, arrT, size);
	deleteMemory(arrT);
	deleteMemory(arrX);
	deleteMemory(arrY);
	system("pause");
	return 0;
}