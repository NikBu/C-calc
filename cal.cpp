#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
using namespace std;

const double Pi = 3.1415926535; //Объявляем значение числа Пи

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

bool Maths(stack <Leksema>& Stack_n, stack <Leksema>& Stack_o, Leksema& item) { //Математическая функция, которая производит расчеты
	//Функция имеет тип bool, чтобы при возникновении какой-либо ошибки возвращать "false"
	double a, b, c;
	a = Stack_n.top().value; //Берется верхнее число из стека с числами
	Stack_n.pop(); //Удаляется верхнее число из стека с числами
	switch (Stack_o.top().type) {  //Проверяется тип верхней операции из стека с операциями
	case '+': //Если тип верхней операции из стека с операциями сложение
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a + b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item); //Результат операции кладется обратно в стек с числами
		Stack_o.pop();
		break;

	case '-':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = b - a;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '^':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = pow(b, a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '*':
		b = Stack_n.top().value;
		Stack_n.pop();
		c = a * b;
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case '/':
		b = Stack_n.top().value;
		if (a == 0) {
			cerr << "\nНа 0 делить нельзя!\n";
			return false;
		}
		else {
			Stack_n.pop();
			c = (b / a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 's':
		c = sin(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 'c':
		c = cos(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	case 't':
		if (cos(a) == 0) {
			cerr << "\nНеверный аргумент для тангенса!\n";
			return false;
		}
		else {
			c = tan(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 'g':
		if (sin(a) == 0) {
			cerr << "\nНеверный аргумент для котангенса!\n";
			return false;
		}
		else {
			c = ctg(a);
			item.type = '0';
			item.value = c;
			Stack_n.push(item);
			Stack_o.pop();
			break;
		}

	case 'e':
		c = exp(a);
		item.type = '0';
		item.value = c;
		Stack_n.push(item);
		Stack_o.pop();
		break;

	default:
		cerr << "\nОшибка!\n";
		return false;
		break;
	}
	return true;
}


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
