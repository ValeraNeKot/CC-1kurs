#include <iostream>
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>

using namespace std;
struct user {
	string login, password; bool role;
};

user* add_user(user* , int* );



int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	user* p; int n; cin >> n;
	p = new user[n];
	for (int i = 0; i < n; i++) {
		p[i].login = "pepe";
		p[i].password = "pepe";
		p[i].role = i;
	}
	p = add_user(p, &n);
	for (int i = 0; i < n; i++) cout<< p[i].login<<"  "<<p[i].password<<"  "<<p[i].role<<endl;
}

user* add_user(user* old_arr, int* n) {
	int p = *n + 1;
	user* new_arr;
	new_arr = new user[p];
	char k;
	for (int i = 0; i < p - 1; i++)  new_arr[i] = old_arr[i];
	cout << " Введите логин : ";
	cin >> new_arr[p - 1].login;
	cout << " Введите пароль : ";
	cin >> new_arr[p - 1].password;
	cout << " Выберите роль  администратор - 1 иначе пользователь : ";
	cin >> k;
	if (k == '1') new_arr[p - 1].role = 1;
	else new_arr[p - 1].role = 0;
	delete[]old_arr; (*n)++;
	return new_arr;

}