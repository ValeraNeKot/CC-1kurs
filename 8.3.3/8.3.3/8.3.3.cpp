#include <math.h>
#include <iostream>
#include <locale.h>

using namespace std;

typedef double (*TypeFun)(double, double);

double y_fun(double, double);
double s_fun(double, double);
double r_fun(double, double);
void out_rez(TypeFun, double, double, double, double);

double y_fun(double x, double e) {
	return (x * x / 4 + x / 2 + 1) * exp(x / 2);
}

double s_fun(double x, double e) {
	double s, r; int k=1;
	s = 1; r = 1;
	while (fabs(s - y_fun(x, e)) >=  e) {
		r *= x / (2 * k);
		s += (k * k + 1) * r;
		k++;
	}
	cout <<"n = "<< k <<endl;
	return s;
}

double r_fun(double x, double e) {
	return fabs(s_fun(x,e) - y_fun(x,e));
}

int main() {
	double a, b, h, e;
	cout << "Enter a, b, h, e: \n";
	cin >> a >> b >> h >> e; cout << endl; if (cin.fail()) "ERROR"; else {
		cout << " 1-Y, 2-S, else |S-Y| \n"; int k; cin >> k; cout << endl;
		switch (k) {
		case 1: cout << "Y = \n"; out_rez(y_fun, a, b, h, e); break;
		case 2:  cout << "S = \n"; out_rez(s_fun, a, b, h, e); break;
		default:  cout << "|S-Y| = \n"; out_rez(r_fun, a, b, h, e);
		}
	}
}

void out_rez(TypeFun f, double a, double b, double h , double e) {
	double x; 
	for (x = a; x <= b;x+=h) {
		cout << f(x, e) << endl;
	}
}