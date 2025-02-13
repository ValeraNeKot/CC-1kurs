#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double S, Y, A, r, k, n, h, a, b, x;
    cout << "Enter a, b, h, n \n"; cin >> a >> b >> h >> n;
    if (cin.fail())
    {
        printf("ERROR");
    }
    else {
        cout << "Y            S            A"<<endl;
        for (x = a; x <= b; x +=  h)
        {
            S = 1;
            r = 1;
            for (k = 1; k <= n; k++)
            {
                r*=x/(2*k);
                S += (k*k+1)*r;
            }
            Y = (x * x / 4 + x / 2 + 1) * exp(x / 2);
            A = fabs(Y - S);
            cout << Y << "    " << S << "    " << A << endl;
        }
    }
}
