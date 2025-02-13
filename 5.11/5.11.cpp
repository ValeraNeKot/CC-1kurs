#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, m, i, j, k=0; double** a;
	cout << "Enter n and m "; cin >> n >> m;

	if (cin.fail()) cout << "ERROR";
	else
	{
		while (m < 2)
		{
			cout << "Array size is not enought"; cin >> n >> m;
		}
		a = new double *[n];
		for (i = 0; i < n; i++)
			a[i] = new double [m];
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cout << "a[" << i << "][" << j << "]="; cin >> a[i][j];
					if (j > 1 && a[i][j - 2] < a[i][j - 1] && a[i][j - 1] < a[i][j])
						k ++;
				
			}
		}
		cout << k << endl;
		for (i = 0; i < n; i++) delete[]a[i];
		delete[]a;
	}
}