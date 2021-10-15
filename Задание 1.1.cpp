#include <iostream> // Библиотека ввода - вывода

#include <cmath> // Библиотека математических функций для C++

using namespace std;

/**brief Функция для расчета a
*\param x Параметр x
*\param y Параметр y
*\param z параметр z
**/

double GetA(const double x, const double y, const double z);

/**brief Функция для расчета b
*\param x Параметр x
*\param y Параметр y
*\param z параметр z
**/

double GetB(const double x, const double y, const double z);

int main()

{

	const double x = 0.61;

	const double y = 3.4;

	const double z = 16.5;

	auto a = GetA(x, y, z);

	auto b = GetB(x, y, z);

	cout << "x = " << x << "; y = " << y << "; z = " << z << ";\n";

	cout << "a = " << a << "\nb = " << b << endl;

	return 0;
}

double GetA(double x, double y, double z) {

	return (pow(x, 3) * pow(tan((x + y) * (x + y)), 2) + z / sqrt(x + y)); /*функция, по которой мы получаем А*/

}

double GetB(double x, double y, double z) {

	return ((y * pow(x, 2) - z) / (exp(z * x) - 1)); /*Функция, по которой мы получаем B*/

}