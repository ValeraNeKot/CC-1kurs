#include <stdio.h>
#include <math.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

struct Stack { 
	int info;
	Stack* next;
} *begin, * t;

Stack* InStack(Stack*, int);
void View(Stack*);
void Del_All(Stack**);
//--------------- Функция добавления элемента в Стек ------------------------
Stack* InStack(Stack* p, int in) {
	Stack* t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}
//----------------- Функция просмотра Стека----------------------------------
void View(Stack* p) {
	Stack* t = p;
	while (t != NULL) {
		cout << " " << t->info << endl;
		t = t->next;
	}
}
//----------------------- Функция освобождения памяти -----------------------
void Del_All(Stack** p) {
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	int p = 0;
	while (TRUE) {
		cout << "Меню:-----------------------------\n";
		cout << "1)Создать\n";
		cout << "2)Добавить\n";
		cout << "3)Вывод на экран\n";
		cout << "4)Заменить первый элемент средним арифметическим\n";
		cout << "иначе:Выход\n";
		cin >> p;
		switch (p) {
		case 1:break;
		case 2:break;
		case 3:break;
		case 4:break;
		default: cout << "Конец!"; return;
		}
	}
}
