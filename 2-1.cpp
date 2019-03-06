//В массиве А(N,N) найти первую строку, не содержащую отрицательных элементов, и поменять её с последней строкой.

#include <iostream>;
#include <iomanip>;

using namespace std;

void giveMemory(int **&p, int N, int M) {
	p = new (nothrow) int *[N];
	for (int** pp = p; pp < p + N; pp++)
		*pp = new(nothrow) int[M];
}

int**  giveMemory(int N, int M) {
	int** p = new (nothrow) int *[N];
	for (int** pp = p; pp < p + N; pp++)
		*pp = new(nothrow) int[M];
	return p;
}

void free_array(int ** p, int N) {
	for (int** pp= p; pp < p + N; pp++)
		delete[] *pp;
	delete[] p;
}

void init_array(int ** a, int N, int M)
{
	for (int** pp = a; pp < a + N; pp++) {
		for (int* p = *pp; p < *pp + M; p++) {
			cout << "Line " << pp - a << ". Enter " << p - *pp << " number" << '\n';
			cin >> *p;
		}
	}
}

void print_array(int ** a, int N, int M) 
{
	for (int ** pp = a; pp < a + N; pp++) {
		for (int * p = *pp; p < *pp + M; p++) {
			cout << setw(5) << *p;
		}
		cout << '\n';
	}
	cout << '\n';
}

int** foo(int** a, int N, int M)
{
	
	for (int ** pp = a; pp < a + N; pp++) {
		bool flag(1);
		for (int * p = *pp; p < *pp + M; p++) {
			if (*p < 0) { 
				flag = 0;
				break; 
			}
		}
		if (flag) {
			swap(*pp, *(a + N - 1));
			break;
		}
	}
	return a;
}

int main()
{
	int** p = nullptr;
	int N;
	cin >> N;
	p = giveMemory(N, N);
	init_array(p, N, N);
	print_array(p, N, N);
	p = foo(p, N, N);
	print_array(p, N, N);
	free_array(p, N);
	system("pause");
	return 0;
}
