#include <iostream> 
#include <conio.h>
#include <string>
#include <string.h>
#include<iomanip>
using namespace std;


int main(){	
	setlocale(LC_ALL, "Russian");
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	int sp[4] = { 6, 8, 10, 17 }, i, j, fio;
	cout << left << setw(4) << " N" << left << setw(sp[0]) << "| ФИО" << left << setw(6) << "| Пол" << left << setw(16) << "| Дата рождения" << left << setw(sp[1]) << "| Город" << left << setw(sp[2]) << "| Диагноз" << left << setw(sp[3]) << "| Номер телефона" << "|" << endl;
	}