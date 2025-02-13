#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	double z1, z2, b, pi=3.1415926;
	cout << "Enter b = "; cin >> b;
	if (cin.fail())
	{
		printf("ERROR");
	}
	else
	{
		z1 = cos(3. / 8 * pi - b / 4) * cos(3. / 8 * pi - b / 4) - cos(11. / 8 * pi + b / 4) * cos(11. / 8 * pi + b / 4);
		z2 = sqrt(2) / 2 * sin(b / 2);
		cout << "Result is z1 = " << z1 << endl;
		cout << "Result is z2 = " << z2 << endl;
	}
}