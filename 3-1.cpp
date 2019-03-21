//Определить, сколько слов в строке начинается с прописной буквы. Вывести их на экран.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstring>
#include <clocale>



using namespace std;

const int MAX = 1000;
char Sep[] = " ,.!?():;";

char* inputStr(char* str) {
	char buf[MAX];
	cin.getline(buf, MAX);
	str = new (nothrow) char[strlen(buf) + 1];
	if (!str) {
		cout << "No memory";
		exit(1);
	}
	str = strcpy(str, buf);
	return str;
}

bool isSeparator(char* str,unsigned int i, char* Sep) {
	for (unsigned int j = 0; j < strlen(Sep); ++j) {
		if (str[i] == Sep[j]) return 1;
	}
	return 0;
}

void task(char* str) {
	for (unsigned int i = 0; i < strlen(str); ++i) {
		
		if (isSeparator(str, i, Sep)) continue;
		if (islower(str[i])) {
			while (!isSeparator(str, i , Sep)) {
				cout << str[i];
				++i;
			}
			cout << " ";
		}
		else {
			while (!isSeparator(str, i, Sep)) ++i;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(CP_UTF8);
	char* str = nullptr;
	cout << "Enter string \n";
	str = inputStr(str);
	task(str);
	delete[] str;
	str = nullptr;
	system("pause");
	return 0;
}