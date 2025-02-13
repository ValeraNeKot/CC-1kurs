#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <io.h>
#include <windows.h>
#include <stdlib.h>
#include<string.h>

using namespace std;

struct stud {
	char fio[40], adr[20];
	int grup, oz[3];
	double sr_oz;
} ;

struct p
{
	int l;
	int r;
};

int Sozdat();
void Prosmotr(int);
void Dobawit();
void Zadanie(int);
bool flopen(const char*);
void qsort(stud*, int);
void Poisk(int);

FILE* f;
char file[20] = "";

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int k, m, n=0;
	for (k = 0; k < 20; k++) {
		cout << "___________________________________________________________________________"<<endl;
		cout << "Выберите действие:" << endl;
		cout << "1) Создать файл и ввести студентов" << endl;
		cout << "2) Вывод списка студентов на экран" << endl;
		cout << "3) Добавить студента" << endl;
		cout << "4) Кол - во студентов из Минска со средним баллом > 4,5" << endl;
		cout << "5) Вывести информацию про студента" << endl;
		cout << "Иначе: Выход"<<endl;
		cin >> m;
		switch (m) {
		case 1: n = Sozdat(); break;
		case 2: Prosmotr(n); break;
		case 3: Dobawit(); n++; break;
		case 4: Zadanie(n); break;
		case 5: Poisk(n); break;
		default: cout << "Конец!\n"; return 0;
		}
	}
}

int Sozdat() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int n = 0, i; stud buf; double sum;
	if (!flopen("wb+")) return 0;
		cout << "Введите кол - во студентов :"; 
		do cin >> n; while (n < 0);
	for (i = 0; i < n; i++) { 
		cout << "--------------------------\nФИО: "; cin>>buf.fio;
		if (buf.fio[0] <= 'я' && buf.fio[0] >= 'а') {
			buf.fio[0] = (char)(buf.fio[0] - 32);}
		cout << "Город проживания: "; cin >> buf.adr;
		if (buf.adr[0] <= 'я' && buf.adr[0] >= 'а') {
			buf.adr[0] = (char)(buf.adr[0] - 32);	}
		cout << "Номер группы: "; cin >> buf.grup;
		cout << "Математика: "; cin >> buf.oz[0];
		cout << "Физика: "; cin >> buf.oz[1];
		cout << "Информатика: "; cin >> buf.oz[2];
		sum = buf.oz[0] + buf.oz[1] + buf.oz[2];
		buf.sr_oz =(double)sum / 3;
		fwrite(&buf, sizeof(stud), 1, f);	
	}
	fclose(f);
	return n;
}

void Prosmotr(int n) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	stud* spisok;	int i;
	if (!flopen("rb")) return;
	n = _filelength(_fileno(f)) / sizeof(stud);  
	spisok = new stud[n];
	fread(spisok, sizeof(stud), n, f); 
	for (i = 0; i < n; i++) {
		cout << endl <<"ФИО: " << spisok[i].fio <<endl;
		cout <<"Адрес: " << spisok[i].adr <<endl;
		cout <<"Номер группы: " << spisok[i].grup <<endl;
		cout << "Средний балл: " << spisok[i].sr_oz<< endl;
	}
	fclose(f);
}

void Dobawit() {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	stud buf; double sum;
	if (!flopen("ab+")) return;
	else {
		cout << "ФИО: ";  cin>>buf.fio;
	if (buf.fio[0] <= 'я' && buf.fio[0] >= 'а') {
			buf.fio[0] = (char)(buf.fio[0] - 32);	}
		cout << "Город проживания: "; cin >> buf.adr;
	if (buf.adr[0] <= 'я' && buf.adr[0] >= 'а') {
			buf.adr[0] = (char)(buf.adr[0] - 32);}
		cout << "Номер группы: "; cin >> buf.grup;
		cout << "Математика: "; cin >> buf.oz[0];
		cout << "Физика: "; cin >> buf.oz[1];
		cout << "Информатика: "; cin >> buf.oz[2]; cout << endl;
	    sum = buf.oz[0] + buf.oz[1] + buf.oz[2];
		buf.sr_oz = (double)sum / 3;
		fwrite(&buf, sizeof(stud), 1, f);
		fclose(f);
	}
}

void Zadanie(int n) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int i, k = 0, p=0; stud* buf, *nerf;
	buf = new stud[n];
	if (!flopen("rb")) return;
	fread(buf, sizeof(stud), n, f);
	fclose(f);
	for (i = 0; i < n; i++) {
		if (!strcmp(buf[i].adr, "Минск") && buf[i].sr_oz >= 4.5) {
			k++;
		}
	}
	nerf = new stud[k];
	k = 0;
	for (i = 0; i < n; i++) {
		if (!strcmp(buf[i].adr, "Минск") && buf[i].sr_oz >= 4.5) {
			nerf[k] = buf[i];
			k++;
		}
	}
	for (i = 0; i < k; i++) {
		cout << nerf[i].fio << endl;
	}
	cout <<"Найдено студентов: " << k << endl;
	cout << " Введите 1 для выбора способа сортировки QuickSort (быстрая сортировка), иначе метод прямого выбора" << endl; cin >> p;
	if (p == 1) qsort(nerf, k);
	else {
		int min; stud temp;
		for (int i = 0; i < k - 1; i++)
		{
			min = i; 
			for (int j = i + 1; j < k; j++) 
			{
				if (strcmp(nerf[j].fio, nerf[min].fio)<0)
					min = j;  
			}
			temp = nerf[i];
			nerf[i] = nerf[min];
			nerf[min] = temp;
		}
	}
	for (i = 0; i < k; i++) {
		cout << nerf[i].fio << endl;
	}
}


void qsort(stud* st, int n)
{
    p  stack[20];
	int i, j, left, right, s = 0; char x[20];
	stud t;
	stack[s].l = 0; stack[s].r = n - 1;
	while (s >=0)
	{
		left = stack[s].l; right = stack[s].r;
		s--;
		while (left < right)
		{
			i = left; j = right; strcpy(x,st[(left + right) / 2].fio);
			while (i <= j)
			{
				while (strcmp(st[i].fio,x) < 0) i++;
				while (strcmp(st[j].fio, x) > 0) j--;
				if (i <= j) {
					t = st[i]; st[i] = st[j]; st[j] = t;
					i++; j--;
				}
			}
			if ((j - left) < (right - i))
			{
				if (i < right) { s++; stack[s].l = i; stack[s].r = right; }
					right = j;
			}
			else {
				if (left < j) { s++; stack[s].l = left; stack[s].r = j; }
				left = i;
			}
		}
	}
}

void Poisk(int n) {
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int i=0,j=n-1,m; stud* buf; char x[40];
	buf = new stud[n];
	if (!flopen("rb")) return;
	fread(buf, sizeof(stud), n, f);
	fclose(f);
	qsort(buf, n);
	cout << "Введите искомое фио\n"; cin >> x;
	if (x[0] <= 'я' && x[0] >= 'а') {
		x[0] = (char)(x[0] - 32);
	}
	while (i < j) {
		m = (j + i) / 2;
		if (strcmp(x, buf[m].fio) > 0) i = m + 1;
		else j = m;
	}
	if (strcmp(buf[i].fio, x) == 0) {
		cout << "ФИО: " << buf[i].fio << endl;
		cout << "Номер группы: " << buf[i].grup << endl;
		cout << "Город проживания: " << buf[i].adr << endl;
		cout << "Средний балл за экзамены: " << buf[i].sr_oz << endl;
	}
	else cout << "Такой студент не найден" << endl;
}

bool flopen(const char* r)
{

	if (!strlen(file))
	{
		cout << "введите имя файла \n";
		cin >> file;
	}
	if (fopen_s(&f, file, r)) 
	{
		cout << "Ошибка!\n";
		return false;
	}
	else return true;
}

