
#include <iostream>
using namespace std;

struct Stack {
	int info;
	Stack* next;
};

struct val {
	int in;
	val* prev, * next;
};

// Сортировки и поиск
void vstavki(int*, int);
void vibor(int*, int);
void qsort(int*, int, int);
int interpolationSearch(int* arr, int n, int x);
void obmen(val**, val**);
void Create(val** b, val** e, int info);

void Add(int kod, val** b, val** e, int info)
{
	val* t = new val;
	t->in = info;
	if (kod == 0)//с конца
	{
		t->prev = NULL;
		t->next = *b;
		(*b)->prev = t;
		*b = t;
	}
	else if (kod == 1)
		//с начала(нормальная очередь)
	{
		t->next = NULL;
		t->prev = *e;
		(*e)->next = t;
		*e = t;
	}
}

void ViewP(val* b);
void ViewQ(val* b);

//билетики пошли
void b1(Stack**);// Поменять 1 и максимальный элементы 
int Fibonacci(int n)
{
	if (n == 0 || n == 1) return n;
	else return Fibonacci(n - 1) + Fibonacci(n - 2);
}
//стеки ебанные 
void View(Stack* p)
{

	while (p != NULL) {
		cout << " " << p->info << endl;
		p = p->next;
	}
}
Stack* InStack(Stack* p, int i) {
	Stack* t = new Stack;
	t->info = i;
	t->next = p;
	return t;
}

int main(){
	int n, i, inf;  Stack* st = NULL; val* b, * e;
	cout << "n = ";
	cin >> n; cout << endl; 
	Create(&b, &e, n);
	for (i = 0; i < n; i++) {
		cin >> inf;
		Add(0, &b,&e, inf);
	}
	obmen(&b, &e);
	ViewP(b);
	ViewQ(e);
}

void ViewP(val* b){
	cout << "-----------------------\n";
	while (b != NULL)
	{
		cout << b->in << endl;
		b = b->next;
	}
}

void ViewQ(val* b) {
	cout << "-----------------------\n";
	while (b != NULL)
	{
		cout << b->in << endl;
		b = b->prev;
	}
}

void vstavki(int* a, int n){
	int i, j, temp;
	for (i = 1; i < n; i++) {
		j = i; temp = a[j];
		while (j > 0 && a[j-1] > temp) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = temp;
	}
}
void vibor(int* a, int n){
	int i_min=0,i,j,temp;
	for (i = 0; i < n-1; i++) {
		i_min = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[i_min]) i_min = j;
		}
		temp = a[i];
		a[i] = a[i_min];
		a[i_min] = temp;
	}
}
void qsort(int* a, int l, int r){
	int i=l, j=r, x, temp;
	x = a[(l + r) / 2];
	while (i <= j) {
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j) {
			temp = a[i]; // Переставляем элементы
			a[i] = a[j];
			a[j] = temp;
			i++; j--;
		}
	}
	if(l<j) qsort(a, l, j);
	if(r>i) qsort(a, i, r);
}
int interpolationSearch(int* arr, int n, int x)
{
	int lo = 0, hi = n - 1;

	while (lo <= hi && x >= arr[lo] && x <= arr[hi])
	{
		int pos = lo + (((double)(hi - lo) /
			(arr[hi] - arr[lo])) * (x - arr[lo]));

		if (arr[pos] == x)
			return pos;
		if (arr[pos] < x)
			lo = pos + 1;
		else
			hi = pos - 1;
	}

	return -1;
}
//------------------------------------------------------------------------------------------------------------
void b1(Stack** p){
	if (*p == NULL) {
		cout << "Стек пуст";
		return;
	}
	*p = InStack(*p, -1);
	Stack* m = *p, * t = *p;
	while (t->next != NULL)
	{
		if (t->next->info > m->next->info) m = t;
		t = t->next;
	}
	if ((*p)->next != m)
	{
		t = (*p)->next->next;
		(*p)->next->next = m->next->next;
		m->next->next = t;

		t = (*p)->next;
		(*p)->next = m->next;
		m->next = t;

	}
	t = *p;
	*p = (*p)->next;
	delete t;
}

void Create(val** b, val** e, int info)
{
	val* t = new val;
	t->in = info;
	t->next = t->prev = NULL;
	*b = *e = t;
}

void obmen(val** b, val** e){
	if (!b) return; 
	Add(0, b, e, (*b)->in + 1);
	Add(1, b, e, (*b)->in + 1);
	val* min = *b, *t = *b;
	while (t->next != NULL)
	{
		if (t->next->in <min->next->in) min = t;
		t = t->next;
	}
	if ((*e)->prev != min) {
		t = min->next;
		min->next = (*e)->prev;
		min->next->next = t->next;
		min->next->next->prev = (*e)->prev;
		t->next = *e;
		t->prev = (*e)->prev->prev;
		(*e)->prev->prev->next = t;
		(*e)->prev->prev = min;
		(*e)->prev = t;
	}
	t = (*e);
	(*e) = (*e)->prev;
	(*e)->next = NULL;
	delete t;
	t = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	delete t;
}