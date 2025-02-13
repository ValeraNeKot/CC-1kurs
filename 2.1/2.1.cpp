#include <iostream>
# include <math.h>
using namespace std;

int main()
{
	double z, x{}, y;
	cout << "Enter z\n"; cin >> z;
	if (cin.fail()||log(fabs(x))+x==0)
	{
		printf("ERROR\n");
	}
	else
		if (z > 0)
		{
			printf("z>0\n");
			x = 1 / (z * z + 2 * z);
		}
		else
		{
			printf("z<=0\n");
			x = 1-z*z*z;
		}
	y = (2 * exp(-3 * x) - 4 * x * x) / (log(fabs(x)) + x);
	cout << "Result is y = " << y << endl;
}
