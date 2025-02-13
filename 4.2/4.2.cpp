#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int a[20], i, n, i_max = 0, sum = 0, i_oh = 21;
	do
	{
		cout << "Enter size of array(0<n<21)"; cin >> n;
	} while (n < 1 || n>20);
		if (i_max == n - 1) cout << "Max in last psition";
		else
		{
			for (i = 0; i < n; i++)
			{
				cin >> a[i];
				if (a[i] > a[i_max]) i_max = i;
				if (a[i] == 0) i_oh = i;	}
			if (cin.fail()) cout << "ERROR";
			else
			{
				if (i_oh == 21) cout << "No null element";
				else 
				{
					if (i_oh == 1 + i_max || i_oh == i_max - 1) 
					{
						cout << "The null element and the maximum element are adjacent";
					}
					else 
					{
						if (i_oh == i_max) cout << "The maximum element is the last null element";
						else {
							if (i_max < i_oh) for (i = i_max + 1; i < i_oh; i++) sum += a[i];
							else for (i = i_oh; i < i_max; i++) sum += a[i];
							cout << "Result sum = " << sum << endl;
						}
					}
				}
		}
	}
}