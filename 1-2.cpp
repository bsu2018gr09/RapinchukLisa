#include <iostream>

using namespace std;

int* newArray(int* pA, int *n) {
	cout << "Enter n " << '\n';
	cin >> *n;
	pA = new (nothrow) int[*n];
	if (!pA) cout << "Could not allocate memory" << '\n';
	return pA;
}

int* deleteA(int* pA) {
	delete[] pA;
	pA = nullptr;
	return pA;
}

void inputA(int *pA, int n)
{
	for (int* p = pA; p < pA + n; p++) {
		cout << "Enter " << p - pA << " numder" << endl;
		cin >> *p;
	}
}

void printA(int *A, int n) {
	for (int* p = A; p < A + n; p++) {
		cout << *p << " ";
	}
	cout << '\n';
}

void foo(int *A, int n) {
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
	int n;
	int* pA = nullptr;
	pA = newArray(pA, &n);
	cout << pA << '\n';

	inputA(pA, n);
	printA(pA, n);
	cout << '\n';
	foo(pA, n);
	printA(pA, n);
	deleteA(pA);
	system("pause");
	return 0;
}
