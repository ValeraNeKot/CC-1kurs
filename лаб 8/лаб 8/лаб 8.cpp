#include <math.h>
#include <iostream>
#include <locale.h>

using namespace std;

typedef double (*TypeFun)(double, double,int&);

double y_fun(double, double,int&);
double s_fun(double, double,int&);
double r_fun(double, double,int&);
void out_rez(TypeFun, double, double, double, double,int&);

double y_fun(double x, double ep,int &n)
{
	double y;
	y =(x * x / 4 + x / 2 + 1) * exp(x / 2);
	return y;
}

double s_fun(double x,double ep,int &n)
{
	double s = 1, r = 1; int k = 1;
	while (fabs(s - y_fun(x, ep, &n)) >= ep)
	{
		r *= x / (2 * k);
		s += (k * k + 1) * r;
		k++;
	}
	n=k;
	return s;
}

double r_fun(double x, double ep,int &n )
{
	return fabs(y_fun(x,ep,&n)-s_fun(x,ep, &n));
}

void out_rez(TypeFun f, double a, double b, double h, double ep,int &n)
{
	for (double x = a; x <= b; x += h) {
		cout << f(x, ep, &n)<<endl;
	}

}

int main()
{
	double a, b, h, ep, n; int num;
	cout << "Enter a, b, h, ep\n ";
	cin >> a >> b >> h >> ep; n = h;
	if (cin.fail()) "ERROR"; 
	else {
		TypeFun ff;
		char text[3][10] = { "function","summa","raznoct" };
		cout << "Functions: 1 - y, 2 - s, else |s-y|" << endl;
		cin >> num;
		switch (num) {
		case 1: ff = y_fun; num = 0; break;
		case 2: ff = s_fun; num = 1; break;
		default: ff = r_fun; num = 2;
		}
		cout << "Result to " << text[num] << endl;
		out_rez(ff, a, b, h, ep,&n);
	}
}