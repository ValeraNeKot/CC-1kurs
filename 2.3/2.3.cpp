#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double max{}, min{}, F{}, x, y, a;
    cout << "Enter x, y, a\n"; cin >> x >> y >> a;
    if (cin.fail())
    {
        printf("ERROR");
    }
    else
    {
        if(a<0)
        {
            min = x * x < y* y ? x * x : y * y;
            F = min + a;
            cout << "Result is F = " << F << endl;
        }
        else
            if (a == 0)
            {
                if (y > x) max = y;
                else max = x;
                if (a > max) max = a;
                F = max;
                cout << "Result is F = " << F << endl;
            }
            else
            {
                F = fabs(x - y) + y * (x + sqrt(a * a * a));
                cout << "Result is F = " << F << endl;
            }
    }
}