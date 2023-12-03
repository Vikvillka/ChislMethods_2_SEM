#include <iostream>
using namespace std;

int main() {
	setlocale(0, "rus");

	double e = 0.001, x1 = -1, x2 = 1, x0 = 1, counter = 0;
	do
	{
		x1 = x2;
		x2 = x1 - (pow(x1, 3) + 2 * x1 + 4)/(3*pow(x1,2)+2);

		counter++;
		cout << x1 << endl;

	} while (abs(x2 - x1) > e && counter < 100);
	cout << counter;
}