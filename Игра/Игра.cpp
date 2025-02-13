#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>

using namespace std;

int main(){	
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	srand(time(NULL));
	string player_1, player_2, buf; int score_1, score_2, up1=0,up2=0; bool pl1, pl2;
	while (true) {
		score_1 = 0, score_2 = 0; pl1 = true, pl2 = true;
		cout << "Правила игры:\n  1. Игроки по очереди могут сделать бросок или же остановиться\n  2. Игра закончиться, если игроки оба отказываются делать бросок или у одного набирается больше 21 очка\n  3. Победителям становиться игрок с наибольшим кол-вом очков\n  4. Игрок набравший больше 21 автоматически проигрывает\n  5. У игроков есть возможность ошибиться при вводе только 3 раза, иначе игроку блокируется возможность делать броски! " << endl << "------------------------------------------------------------------" << endl;
		cout << "Введите имя первого игрока:   "; cin >> player_1;
		cout << "Введите имя второго игрока:   "; cin >> player_2;
		cout << "\n---------------------------------------------------------------\n" << endl;
		while ((pl1 || pl2) && score_1 < 21 && score_2 < 21) {
			if (pl1) {
				cout << "Ваш счет: " << score_1 << endl; 
				cout << player_1 << ", сделать бросок?" << endl << "1 - Да\n" << "2 - Нет\n"; cin >> buf;
				if (buf == "1") { score_1 += rand() % 6 + 1; cout << "Ваш счет: " << score_1 << endl;
				}
				else { if (buf == "2") pl1 = false; else { if (up1 == 2) pl1 = false; cout << "За неправильный ввод игрок пропускает ход!" << endl; up1++; } }
			}
			cout << "\n---------------------------------------------------------------\n"<<endl;
			if (pl2) {
				cout << "Ваш счет: " << score_2 << endl;
				cout << player_2 << ", сделать бросок?" << endl << "1 - Да\n" << "2 - Нет\n"; cin >> buf;
				if (buf == "1") { score_2 += rand() % 6 + 1;  cout << "Ваш счет: " << score_2 << endl; }
				else {
					if (buf == "2") pl2 = false; else { if (up2 == 2) pl2 = false; cout << "За неправильный ввод игрок пропускает ход!" << endl; up2++; }
				}
			}
			cout << "\n---------------------------------------------------------------\n" << endl;
		}
		buf = "0";
		if (score_1 == score_2) cout << "Ничья!" << endl;
		else { if (score_1 < score_2) cout << "Победил игрок:  " << player_2 << endl; else cout << "Победил игрок:  " << player_1 << endl;
		}
		cout << "Для начала новой партии введите 1:  "; cin >> buf; 
		if (buf != "1") return 1;
	}
}