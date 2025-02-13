#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c, z1, z2, pi = 3.14159226;
    cout << "Enter a = "; cin >> a;
    if (cin.fail()||tan(3. / 2 * pi - a)==0)
    {
        printf("ERROR");
    }
    else
    {
        b = sin(4 * a);
        c = cos(2 * a);
        z1 = sin(4 * a) / (1 + cos(4 * a)) * cos(2 * a) / (1 + cos(2 * a));
        z2 = 1 / tan(3. / 2 * pi - a);
        cout << "Result is z1 = " << z1 << endl;
        cout << "Result is z2 = " << z2 << endl;
    }
}