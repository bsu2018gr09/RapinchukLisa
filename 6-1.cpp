// Класс вектор в n-мерном пространстве. n задается как глобальная константа.
#include<iostream>

using namespace std;

const int n(5);

class Vector
{
public:
	Vector() : v{0}
	{
		cout << "constructor 1\n";
	};

	Vector(double a) {
		for (int i = 0; i < n; ++i) v[i] = a;
		cout << "constructor 2\n";
	};
	
	Vector(const Vector &other) {
		for (int i = 0; i < n; ++i) v[i] = other.v[i];
		cout << "copy constructor\n";
	};
	~Vector()
	{
		cout << "destructor\n";
	};
	
	const Vector& operator = (const Vector &other)
	{
		for (int i = 0; i < n; ++i) v[i] = other.v[i];
		return *this;
	};

	
	Vector operator + (const Vector& other) 
	{
		Vector tmp;
		for (int i = 0; i < n; ++i) tmp.v[i] = v[i] + other.v[i];
		return tmp;
	};

	Vector operator - (const Vector& other)
	{
		Vector tmp;
		for (int i = 0; i < n; ++i) tmp.v[i] = v[i] - other.v[i];
		return tmp;
	};

	Vector operator * (const double a)
	{
		Vector tmp;
		for (int i = 0; i < n; ++i) tmp.v[i] = v[i]*a;
		return tmp;
	};

	double operator * (const Vector& other)
	{
		double m{ 0 };
		for (int i = 0; i < n; ++i) m = m + v[i]*other.v[i];
		return m;
	};

	Vector operator / (const double a)
	{
		if (!a) {
			cout << "error!";
			return 0;
		}
		Vector tmp;
		for (int i = 0; i < n; ++i) {
			tmp.v[i] = v[i] / a;
		}
		return tmp;
	};

	friend ostream& operator << (ostream & stream, const Vector& a)
	{
		stream << '(';
		for (int i = 0; i < n - 1; i++) {
			stream << a.v[i] << ',';
		}
			stream << a.v[n-1] << ')' << '\n';
		return stream;
	};

	friend istream& operator >> (istream& stream, Vector& a) {
		for (int i = 0; i < n; i++) {
			stream >> a.v[i];
		}
		return stream;
	};

private:
	double v[n];
};

int main()
{

	Vector a{ 8 }, b{ 1 }, c, d{ b };
	cout << "a = " << a;
	cout << "b = " << b;
	cout << "c = " << c;
	cout << "d = " << d;
	cin >> c;
	cout << "c = " << c;

	Vector* p;
	p = &a;
	cout <<"*p = " << *p;
	cout <<"*p * 2 = "<< *p * 2; 

	Vector* pointer;
	pointer = new (nothrow) Vector[n];
	for (int i = 0; i < n; i++) {
		pointer[i] = b * i;
	}
	for (int i = 0; i < n; i++) {
		cout << pointer[i];
	}
	Vector sum{ 0 };
	for (int i = 0; i < n; i++) {
		sum = sum + pointer[i];
	}
	cout << "sum = "<< sum;

	delete[] pointer;
	pointer = nullptr;
	cout << pointer << '\n';

	cout <<" c*2 = " << c * 2;
	cout <<" c/2 = " << c / 2;
	cout <<" c+b = " << c + b;
	cout <<" c*b = " << c*b << '\n';  
	system("pause");
	return 0;
}