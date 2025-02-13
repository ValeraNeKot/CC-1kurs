#include <iostream>
#include <string.h>
#include <stdio.h>
#include <windows.h>
using namespace std;

int main() {
	char S[50];
	int r=0, i,j=1,n,k, puzir,r0=0, nach[20];
		gets_s(S);
		r = strlen(S);
		nach[0] = 0;
		for (i = 0; i < r; i++) {
			if (S[i] == ' ') {
				if (S[i + 1] != ' '){
					nach[j] = i + 1;
					j++; }
			}
		}
		for (i = 0; i < j; i++) {
			if (S[nach[i]]<='Z' && S[nach[i]]>='A') {
				S[nach[i]] = (char)(S[nach[i]] + 32);
			}
		}
	for (i = 0; i < j - 1; i++) {
		for (n = j - 1; n >=i+1; n--) {
			if (S[nach[n]] < S[nach[n - 1]]) {
				puzir = nach[n];
				nach[n ] = nach[n-1];
				nach[n - 1]= puzir;
			}
		}
	}
	strcat_s(S, " \0");
	for (n = 0; n < j; n++) {
		k = nach[n];
		while (S[k] != ' ') {
			cout << S[k];
			k++;
		}
		cout << endl;
	}
}