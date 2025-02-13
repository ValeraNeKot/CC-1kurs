#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double z, a, b, y, x, f.; int d ;
    cout << "Enter z, a, b, x "; cin >> z>>a>>b>>x;
    cout << "Choose one of the options and enter its number: 1)f=2*x; 2)f=x*x; 3)f=3/x "; cin >> d;
    switch (d)
    {
    case 1: printf("f=2*x\n"); f = 2 * x; break;
    case 2: printf("f=x*x\n"); f = x * x; break;
    case 3: printf("f=x/3\n"); f = x / 3; break;
    default: printf("ERROR");
    }
    if(cin.fail()||(log(fabs(x))+f) == 0)
    {
        cout << "ERROR";
    }
    else
        if (z > 0)
        {
            printf("z>0\n");
            x = 1 / (z * z + 2 * z);
            y = (2.5 * a * exp(-3 * x) - 4 * b * x * x) / (log(fabs(x) + f));
            cout << "Result is y = " << y << endl;

        }  
        else 
        {
            printf("z<=0");
            x = 1 - z * z * z;
            y = (2.5 * a * exp(-3 * x) - 4 * b * x * x) / (log(fabs(x) + f));
            cout << "Result is y = " << y << endl;
        }
 
}