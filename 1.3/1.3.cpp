#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double x, y, z, b,m,n;
    cout << "Enter x, y, z "; cin >> x >> y >> z;
    if (cin.fail())
    {
        cout << "Error";
    }
    else
    {
        if (x + y != 0)
        {
            m = pow(abs(x), 1. / 3);
            n = abs(x - y);
            b = pow(y, m) + pow(cos(y), 3) * n * (1 + sin(z) * sin(z) / sqrt(x + y)) / (exp(n) + x / 2);
            cout << "Result is b = " << b << endl;
        }
        else
        {
            cout << "Error";
        }
    }
}