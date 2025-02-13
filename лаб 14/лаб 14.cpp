#include <iostream>
#include <windows.h>
#include <string.h>
#include <string>

using namespace std;

struct Info {
	int ID; string FIO;
};

struct Tree {
	int ID; string FIO;
	Tree* l, * r;
};


Tree* List(int , string);
void chet(Tree* , Info* , int* );
void Add_List(Tree* , int , string );
Tree* Del(Tree*, int);
void View(Tree*, int);
void Del_All(Tree*);
void poisk(Tree*,int );
void Make_Blns(Tree**, int, int, Info*);
void sort(Info*, int);
void View_W(Tree*);
void View_O(Tree*);
void View_P(Tree*);
Info* addElemet(Info*, int*, string, int);
int TZ(Tree*, char);
bool proverka(string);
void kol_vo(Tree*, int*);

void kol_vo(Tree* r, int* k) {
	if (!r) return;
	else {
		(*k)++;
		kol_vo(r->l, k);
		kol_vo(r->r, k);
	}
}

Tree* List(int i, string a)
{
	Tree* t = new Tree;	
	t->ID = i;
	t->FIO = a;
	t->l = t->r = NULL;
	return t;		  
}

void chet(Tree* root , Info* a , int* kol)
{
	if (!root) return;
	else {
		a[*kol].FIO = root->FIO;
		a[*kol].ID = root->ID;
		(*kol)++;
		chet(root->r,a,kol);
		chet(root->l, a, kol);
	}

}

void Add_List(Tree* root, int key, string FIO)
{
	Tree* prev = root, * t;
	int find = 1;
	t = root;
	while (t && find) {
		prev = t;
		if (key == t->ID) {
			find = 0;
			cout << " Такой уже есть !" << endl;
		}
		else
			if (key < t->ID) t = t->l;
			else
				t = t->r;
	}
	if (find) {
		t = List(key,FIO);
		if (key < prev->ID)
			prev->l = t;
		else
			prev->r = t;
	}
}

Tree* Del(Tree* root, int key) {
	Tree* Del, * Prev_Del, * R, * Prev_R;
	Del = root;
	Prev_Del = NULL;
		while (Del != NULL && Del->ID != key) {
			Prev_Del = Del;
			if (key < Del->ID)  Del = Del->l;
			else Del = Del->r;
		}
	if (Del == NULL) {    
		cout << "\n Элемент не найден!" << endl;
		return root;
	}
	if (Del->r == NULL) R = Del->l;
	else
		if (Del->l == NULL) R = Del->r;
		else {
			Prev_R = Del;
			R = Del->l;
			while (R->r != NULL) {
				Prev_R = R;
				R = R->r;
			}
			if (Prev_R == Del)
				R->r = Del->r;
			else {
				R->r = Del->r;
				Prev_R->r = R->l;
				R->l = Prev_R;
			}
		}
	if (Del == root) root = R;
	else
		if (Del->ID < Prev_Del->ID)
			Prev_Del->l= R;	
		else
			Prev_Del->r = R;  
	cout << " Удалили " << Del->ID << endl;
	delete  Del;
	return root;
}


void View(Tree* t, int level) {
	if (t) {
		View(t->r, level + 1);
		for (int i = 0; i < level; ++i)
			cout << "    ";
		cout << t->ID << endl;
		View(t->l, level + 1);
	}
}

void View_W(Tree* t) {
	if (t) {
		View_W(t->l);
		cout << t->ID << endl;
		View_W(t->r);
	}
}

void View_O(Tree* t) {
	if (t) {
		View_O(t->l);
		View_O(t->r);
		cout << t->ID << endl;
	}
}

void View_P(Tree* t) {
	if (t) {
		cout << t->ID << endl;
		View_O(t->l);
		View_O(t->r);
	}
}

void Del_All(Tree* t) {
	if (t != NULL) {
		Del_All(t->l);
		Del_All(t->r);
		delete t;
	}
}

void poisk(Tree* root, int key) {
	Tree* isk=root;
	while (isk != NULL && isk->ID != key) {
		if (key < isk->ID) isk = isk->l;
		else isk = isk->r;
	}
	if (isk == NULL) cout << "\nЭлемент не найден!" << endl;
	else cout << "ID:  " << isk->ID << endl << "ФИО:  " << isk->FIO << endl;
}


void Make_Blns(Tree** p, int n, int k, Info* a)
{
	if (n == k) {
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new Tree;
		(*p)->ID = a[m].ID;
		(*p)->FIO = a[m].FIO;
		Make_Blns(&(*p)->l, n, m, a);
		Make_Blns(&(*p)->r, m + 1, k, a);
	}
}

void sort(Info a[], int n) {
	struct
	{
		int l;
		int r;
	} st[20]{};
	int i, j, left, right, s = 0,x;
	Info t;
	st[s].l = 0; st[s].r = n - 1;
	while (s != -1)
	{
		left = st[s].l; right = st[s].r;
		s--;
		while (left < right)
		{
			i = left; j = right; x= a[(left + right) / 2].ID;
			while (i <= j)
			{
				while (a[i].ID < x) i++;
				while (a[j].ID > x) j--;
				if (i <= j) {
					t = a[i]; a[i] = a[j]; a[j] = t;
					i++; j--;
				}
			}
			if ((j - left) < (right - i))
			{
				if (i < right) { s++; st[s].l = i; st[s].r = right; }
				right = j;
			}
			else {
				if (left < j) { s++; st[s].l = left; st[s].r = j; }
				left = i;
			}
		}
	}

}

Info* addElemet(Info* m, int *n, string f,int id) 
{
	Info* temp = NULL;
	temp = new Info[*n + 1]; 
	for (int i = 0; i < *n; i++)
		temp[i] = m[i];
	temp[*n].FIO = f;
	temp[*n].ID = id;
	(*n)++;
	delete[]m; 
	return temp;
}

int TZ(Tree* r, char ch) {
	if (!r) return 0;	
	if (r) {	
		int i = TZ(r->l, ch) + TZ(r->r, ch);
		if (r->FIO[0] == ch) return i + 1;
		else return i;
	}
}


bool proverka(string D) {
	int p = 0, u = 0, i = 1;
	if (D[0] == '-') {
		p++;
	}
	else {
		if (D[0] == '.') {
			p++; u++;
		}
		else {
			for (char ii = '0'; ii <= '9'; ii++) {
				if (D[0] == ii) {
					p++;
				}
			}
		}
	}
	if (p == 1) {

		while (D[i] != '\0') {
			if (D[i] == ' ') {
				return false;

			}
			for (char ii = '0'; ii <= '9'; ii++) {
				if (D[i] == ii) {
					p++;
				}
			}
			if (u == 0) {
				if (D[i] == '.') {
					p++; u++;
				}
			}
			i++;
		}
	}
	else {
		return false;
	}
	if (p != i) {
		return false;
	}
	if (i + 1 > 1 && D[0] == '0' && D[1] != '.') {
		return false;
	}
	if (i + 1 > 1 && D[0] == '-' && D[1] == '0' && D[2] != '.') {
		return false;
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	int n, in,i,j=0, key,l=0, kol=0; Info* a, buf; string fio, prov; Tree* root = NULL; char k, ch = NULL; bool m;
	cout << "Введите кол-во узлов:   "; cin >> n;
	for (i = 0; i < n; i++) {
		m = TRUE;
		cout << " Введите ID : "; 
		cin >> prov; 
		if (proverka(prov) == false) { cout << "Ошибка ввода, введите другое значение" << endl; i--; }
		else {
			in = stod(prov);
			cout << " Введите ФИО : ";
			cin >> fio;
			if (root == NULL)
				root = List(in, fio);
			else
		    Add_List(root, in, fio);
		}
	}
	while (TRUE) {
		cout << "\n1) Добавить новую запись;\n2) Найти узел;\n3) Удалить узел;\n4) Вывод информации на экран;\n5) Найти кол-во записей по условию\n6) Сбалансировать дерево;\n0) Выход\n"; cin>>k;
		switch (k) {
		case'1':
			cout << " Введите ID : ";
			cin >> prov;
			if (proverka(prov) == false) { cout << "Ошибка ввода, введите другое значение" << endl; i--; }
			else {
				in = stod(prov);
				cout << " Введите ФИО : ";
				cin >> fio;
				if (root == NULL)
					root = List(in, fio);
				else
					Add_List(root, in, fio);
			}
			break;
		case'2':
			cout << "Введите ID:  ";
			cin >> key;
			poisk(root, key);
			break;
		case'3':
		    cout << " Введите ID удаляемого объекта :  ";
			cin >> key;
			root = Del(root, key);
			break;
		case'4':
			cout << "1) В виде дерева; 2) Прямым обходом; 3) Обратным обходом; 4) В порядке возрастания ключа;\n "; cin >> k; cout << "----------------------------------" << endl;
			switch (k) {
			case'1':View(root, 0); break;
			case'2':View_P(root); break;
			case'3':View_O(root); break;
			case'4':View_W(root); break;
			default: cout << "Неправильный ввод!\n";
			}
			break;
		case'5': cout << "Введите букву:  ";  cin >> ch; cout<<TZ(root, ch);  break;
		case'6': j = 0; kol_vo(root, &j); a = new Info[j]; kol = 0; chet(root, a, &kol); sort(a, j); Del_All(root); Make_Blns(&root, 0, j, a); cout << "Дерево сбалансировано" << endl; break;
		case'0': return 0;
		default: cout << "Неправильный ввод!\n";
		}
	}
}
+