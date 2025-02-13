#include <iostream>
#include <iomanip>
#include <cstdio>
#include <io.h>
#include <windows.h>

using namespace std;

double Srednee(int (&a)[3][10], int);

void create();
void watch();
void addendum();
int infa();
void editing();
void del();
void sorting();

void FileOutput(int);
bool FileOpen(const char*);

struct st
{
    char familia;
    int nomer_grupi;
    int ozenki[3][10];
    double sr_bal;
}*a;
FILE* f;
char file[20] = "";

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int p, n, i;
    cout << "                                                          Меню: " << endl;
    cout << "1) Создать" << endl;
    cout << "2) Просмотр" << endl;
    cout << "3) Добавление" << endl;
    cout << "4) Информация о студентах заданной группы с отметками 9 и 10 по информатике" << endl;
    cout << "5) Редактирование" << endl;
    cout << "6) Удаление" << endl;
    cout << "7) Сортировка" << endl;
    cout << "0 - Завершение программы" << endl;
    cout << "Выберите функцию:";
    cin >> n;

    for (i = 0; i < 100; i++)
    {
        if (n != 0) {
            switch (n) {
            case 1:create(); break;
            case 2:watch(); break;
            case 3:addendum(); break;
            case 4:p=infa(); break;
            default: {cout << "Ошибка!!! Необходимо выбрать от 0 до 4, попробуйте ещё раз" << endl;
                cout << "Я выбираю:";
                cin >> n; }

            }
            cout << "Вы выполнили " << n << " функцию, выберите следующую" << endl;
            cout << "Я выбираю: ";
            cin >> n;
        }
        else {
            FileOutput(p);
            cout << "Завершение программы.";
            break;
        }

    }
    return 0;
}
bool FileOpen(const char* w) {
    setlocale(LC_ALL, "rus");
    if (!strlen(file)) {
        cout << "Введите имя бинарного файла: ";
        cin >> file;
    }
    if (fopen_s(&f, file, w)) {
        cout << "Ошибка" << endl;
        return 0;
    }
    else return 1;
}
void create() {
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (!FileOpen("ab+")) return;
    int num, i;
    cout << "Введите количество студентов: ";
    cin >> num;
    a = new st[num];
    cout << endl;
    for (i = 0; i < num; i++)
    {
        cout << "Введите фамилию студента:";
        cin >> a[i].familia;
        cout << "Введите номер группы:";
        cin >> a[i].nomer_grupi;
        cout << "Введите оценки по физике через пробел:"; int j = 0;
        while (getchar() != '\n') {
            while(getchar()!=' ')
            cin >> a[i].ozenki[0][j];
            j++;
        }
        cout << "Введите оценки по математике через пробел:"; int j = 0;
        while (getchar() != '\n') {
            while (getchar() != ' ')
                cin >> a[i].ozenki[1][j];
            j++;
        }
        cout << "Введите оценки по информатике через пробел:"; int j = 0;
        while (getchar() != '\n') {
            while (getchar() != ' ')
                cin >> a[i].ozenki[2][j];
            j++;
        }
        cout << "________________________________" << endl;
        a[i].sr_bal = Srednee(a[i].ozenki, i);
    }
    //-----------------------------------------------------------------------------------
    double Srednee(int(&a)[3][10], int i){
        int sum=0,kolvo=0,k,p=0;
        for (k = 0; k < 3; k++) {
            p = 0;
            while (a[i].ozenki[k][p] != 0) {
                p++; kolvo++;
                sum += a[i].ozenki[k][p];
            }
        }
        return sum / kolvo;
    }
    //--------------------------------------------------
    fwrite(a, sizeof(st), num, f);
    delete[] a;
    fclose(f);
}
void watch() {
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (!FileOpen("rb")) return;
    int n, i, k;
    n = _filelength(_fileno(f)) / sizeof(st);
    a = new st[n];
    fread(a, sizeof(st), n, f);
    for (i = 0; i < n; i++)
    {
        cout << "Фамилия студента:" << a[i].familia << endl;
        cout << "Номер группы: " << a[i].nomer_grupi << endl;
        cout << "Оценки по физике:"; 
        while (a[i].ozenki[0][k] != 0) {
            cout << a[i].ozenki[0][k] << ", "; k++;
        } k = 0; cout << endl;
        cout << "Оценки по математике:";
        while (a[i].ozenki[1][k] != 0) {
            cout << a[i].ozenki[1][k] << ", "; k++;
        } k = 0; cout << endl;
        cout << "Оценки по информатике:";
        while (a[i].ozenki[2][k] != 0) {
            cout << a[i].ozenki[2][k] << ", "; k++;
        } cout << endl;
        cout << "Средний бал:" << a[i].sr_bal << endl;
        cout << "________________________________" << endl;
    }
    delete[] a;
    fclose(f);
}
//--------------------------------------------------
void addendum() {
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (!FileOpen("ab+")) return;
    int n;
    n = _filelength(_fileno(f)) / sizeof(st);
    a = new st[n+1];
    cout << endl;
        cout << "Введите фамилию студента:";
        cin >> a[n + 1].familia;
        cout << "Введите номер группы:";
        cin >> a[n + 1].nomer_grupi;
        cout << "Введите оценки по физике через пробел:"; int j = 0;
        while (getchar() != '\n') {
            while (getchar() != ' ')
                cin >> a[n + 1].ozenki[0][j];
            j++;
        }
        cout << "Введите оценки по математике через пробел:"; int j = 0;
        while (getchar() != '\n') {
            while (getchar() != ' ')
                cin >> a[n + 1].ozenki[1][j];
            j++;
        }
        cout << "Введите оценки по информатике через пробел:"; int j = 0;
        while (getchar() != '\n') {
            while (getchar() != ' ')
                cin >> a[n + 1].ozenki[2][j];
            j++;
        }
        cout << "________________________________" << endl;
        a[n+1].sr_bal = Srednee(a[n + 1].ozenki, i);
}
//---------------------------------------------------
int infa() {
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    if (!FileOpen("rb")) return;
    int n, i, k, j;
    n = _filelength(_fileno(f)) / sizeof(st);
    a = new st[n];
    fread(a, sizeof(st), n, f);
    cout << "Введите номер группы";  cin >> k;
    for (i = 0; i < n; i++) {
        if (a[i].nomer_grupi == k) {
            j = 0;
            while (a[i].ozenki[3][j] != 0) {
                if (a[i].ozenki[3][j] == 9 || a[i].ozenki[3][j] == 10) {
                    cout << a[i].familia << endl;
                    cout << a[i].nomer_grupi << endl;
                    cout << a[i].sr_bal << endl;
                    break;
                }
                j++;
           }
        }
    }
    return k;
}
//------------------------------------------------------------------------
void FileOutput(int p) {
    setlocale(LC_ALL, "rus");
    char text[20];
    cout << "Введите имя текстового файла: ";
    cin >> text;
    FILE* txt;
    if (fopen_s(&txt, text, "w")) {
        cout << "Файл не создан";
        return;
    }
    int n, i, j;
    if (!FileOpen("rb")) return;
    n = _filelength(_fileno(f)) / sizeof(st);
    a = new st[n];
    fread(a, sizeof(st), n, f);
    st k;
    cout << "Информация о заданной группы с отметками 9 и 10 по информатике занесена в текстовый файл." << endl;
    for (i = 0; i < n; i++) {
        if (a[i].nomer_grupi == p) {
            j = 0;
            while (a[i].ozenki[3][j] != 0) {
                if (a[i].ozenki[3][j] == 9 || a[i].ozenki[3][j] == 10) {
                    fprintf(txt, "%i %f %s %f", a[i].familia, a[i].nomer_grupi, a[i].ozenki[3][10], a[i].sr_bal);
                    break;
                }
                j++;
            }
        }
    }
    delete[] a;
    fclose(f);
    fclose(txt);
}