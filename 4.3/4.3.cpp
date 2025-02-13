#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N, c, i=0, b=0;
	do
	{
		cout << "Enter N" << endl; cin >> N;
	}
	while (N < 0);
	if (cin.fail()) cout << "ERROR"; 
	else
	{
		int* a = new int[b];
		while (N > 0)
		{
			c = N % 10;
			a[i] = c * c;
			N = (N - c) / 10;
			cout << a[i] << endl;
			i++;
		}
		delete[]a;
	}
}