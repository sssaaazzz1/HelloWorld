#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void vyvod(vector<int> v)
{
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
}

//1. Вставка в конец
void push_back(int x, vector<int> &v) {
	for (int i = 0; i < x; i++)
	{
		int y; cout << i+1<< " число: "; cin >> y;
		v.push_back(y);
	}
}
//2. Вставка в любое место
void insert(int a, vector<int> &v) {
	int c, b;
	cout << "В какой индекс вектора вставить? "; cin >> c;
	cout << "Вводите числа через enter: ";
	for (int i = 0; i < a; i++)
	{cin >> b;
		v.insert(v.begin() + (c - 1+i), b);
	}
}
//3. Арифметические операции
	//+
	void funq1(int x, vector<int> &v) {
		for (auto iter = v.begin(); iter != v.end(); ++iter)
			*iter += x;
	}
	//-
	void funq2(int x, vector<int> &v) {
		for (auto iter = v.begin(); iter != v.end(); ++iter)
			*iter -= x;
	}
	//*
	void funq3(int x, vector<int> &v) {
		for (auto iter = v.begin(); iter != v.end(); ++iter)
			*iter *= x;
	}
	//\/
	void funq4(int x, vector<int> &v) {
		for (auto iter = v.begin(); iter != v.end(); ++iter)
			*iter /= x;
	}
//4. Вывод

//5. Вывод в обратном порядке
void rvyvod(vector<int> v)
{
	for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
		cout << *iter << " ";
}
//6. Удаление элемента
void ydalenie(int x, vector<int> &v) {
	v.erase(v.begin() + (x - 1));
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int vybor, x, p;
	string c;
	vector<int> v = { 5, 4, 18, 3, 65, 43 };
	cout << "Исходный вектор: ";
	for (auto iter = v.begin(); iter != v.end(); ++iter)
		cout << *iter << " ";
	do {
		cout << "\nИзменение вектора:\n1 - вставить элемент в конец;\n";
		cout << "2 - вставка нескольких элементов в любое место;\n";
		cout << "3 - арифметические операции\n";
		cout << "4 - вывод вектора\n";
		cout << "5 - вывод вектора в обратном порядке\n";
		cout << "6 - Удаление элемента\n";
		cin >> vybor;
		switch (vybor) {
		case 1://Вставка в конец
			cout << "Сколько переменных вставить? "; cin >> x;
			push_back(x, v);
			vyvod(v); cout << endl; break;

		case 2://Вставка в любое место
			int a;
			cout << "Сколько элементов: "; cin >> a;
			insert(a, v);
			vyvod(v); cout << endl; break;

		case 3://Арифметические операции
			cout << "На какое число? "; cin >> x;
			cout << "Какую операцию? (+, -, *, /) "; cin >> c;
			if (c == "+")
				funq1(x, v);
			else if (c == "-")
				funq2(x, v);
			else if (c == "*")
				funq3(x, v);
			else if (c == "/")
				funq4(x, v);
			vyvod(v); cout << endl;
			break;

		case 4://Вывод вектора
			vyvod(v); cout << endl; break;

		case 5://Вывод в обратном порядке
			rvyvod(v); cout << endl; break;

		case 6://Удаление элемента
			cout << "Какой эелемент? "; cin >> x;
			ydalenie(x, v);
			vyvod(v); cout << endl;
		}
		cout << "Продолжить работу? (0 - Нет) "; cin >> p;
	} while (p != 0);
}