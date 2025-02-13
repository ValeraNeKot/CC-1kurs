#include <iostream>
#include<math.h>

using namespace std;

double y(int);
double p(int);

int main(){
	int n;
	do {
		cout << "n>0 !\n"; cin >> n; 
	} while (n < 1);
	cout <<"y(n)=" << y(n) << endl;
	cout <<"p(n)=" << p(n);
}

double y(int n) {
	if (n > 1) return 1. / (n + y(n - 1));
	else if(n==1) return 1. / (1.+1./2);
}
double p(int n) {
	int i; double r = 1. + 1. / 2;
	for (i = 1; i <= n; i++) {
		r = 1 / (i + r);
	}
	return r;
}