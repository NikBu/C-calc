#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

const double Pi = 3,1415926535; //Объявляем значение числа Пи

double ctg(double x) { //Функция для расчета котангенса
	double a = cos(x);
	double b = sin(x);
	return (a / b);
}

struct Leksema //Структура, описывающая любое число или операцию
{
	char type; // 0 для чисел, "+" для операции сложения и т.д.
	double value; //Значение (только для чисел). У операций значение всегда "0"
};



int getRang(char Ch) { //Функция возвращает приоритет операции: "1" для сложения и вычитания, "2" для умножения и деления и т.д.
	if (Ch == 's' || Ch == 'c' || Ch == 't' || Ch == 'g' || Ch == 'e')return 4;
	if (Ch == '^')return 3;
	if (Ch == '+' || Ch == '-')return 1;
	if (Ch == '*' || Ch == '/')return 2;
	else return 0;
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "   Для испрользования числа Пи введите 'pi', для использования числа Е введите 'exp(1)'\n";
	cout << "   Введите выражение: ";
	char Ch; //Переменная, в которую будет записываться текущий обрабатываемый символ
	double value;
	bool flag = 1; //Нужен для того, чтобы программа смогла отличить унарный минус (-5) от вычитания (2-5)
	stack <Leksema> Stack_n; //Стек с числами
	stack <Leksema> Stack_o; //Стек с операциями
	Leksema item; //Объект типа Leksema
	
	cout << "   Ответ: " << Stack_n.top().value << endl; //Выводим ответ
	system("pause");
		return 0;
}