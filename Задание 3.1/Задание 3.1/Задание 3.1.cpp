#define _USE_MATH_DEFINES


#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

bool isCalculated(const double x) {
	return x >= numeric_limits<double>::min();
}

double Calculate(const double x) {
	return 3 * x + 4 * log(x) - 5;
}


int main()
{
	const auto left = 2.0;
	const auto right = 4.0;
	const auto step = 0.2;

	auto x = left;
	cout << " x" << setw(15) << "y\n";

	while ((x < right) || (abs(x - right) < step))
	{
		if (isCalculated(x))
		{
			const auto y = Calculate(x);
			cout << setw(10) << setprecision(2) << x << setw(15)
				<< setprecision(5) << y << endl;
		}
		else
		{
			cout << setw(10) << setprecision(2) << x << setw(15)
				<< "not defined" << endl;
		}
		x += step;

	}
	return 0;
}