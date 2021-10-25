#define _USE_MATH_DEFINES // for C++

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


enum class ActionChoice
{
	two,
	three
};

int main() {
	setlocale(LC_ALL, "Russian");
	double a, b, c;
	std::cout << "Введите первую переменную a и вторую переменную b ";
	std::cin >> a >> b;

	std::cout << "Выберите способ перемены значений (без новой переменной=0 , с использованием новой переменной=1" << endl;
	int input;
	std::cin >> input;
	const auto choice = static_cast<ActionChoice>(input);

	switch (choice)
	{
	case ActionChoice::two:
	{
		a = a + b;
		b = a - b;
		a = a - b;
		std::cout << "Переменные были заменены друга на друга, теперь a= " << a << ", а b= " << b;
		break;
	}
	case ActionChoice::three:
	{
		c = a + b;
		a = c - a;
		b = c - b;
		std::cout << "Переменные были заменены друга на друга, теперь a= " << a << ", а b= " << b;
		break;
	}

	}

	return 0;
}