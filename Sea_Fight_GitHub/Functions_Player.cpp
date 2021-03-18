#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

char place[10][10] = {
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
		{'-','-','-','-','-','-','-','-','-','-'},
};

char Show_Place(char massive[10][10]) {
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			cout << massive[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
void Menu(int counter_0, int counter_1, int counter_2, int counter_3) {
	cout << "Какой тип корабля вы хотите поставить?" << endl;
	cout << "Однопалубный - 1 (Осталось: " << counter_0 << ");" << endl;
	cout << "Двухпалубный - 2 (Осталось: " << counter_1 << ");" << endl;
	cout << "Трёхпалубный - 3 (Осталось: " << counter_2 << ");" << endl;
	cout << "Четырёхпалубный - 4 (Осталось: " << counter_3 << ");" << endl;
}
int Gorizontal(char massive[10][10], int x, int y, int count_ships) {
	int string_first, column_first;
	cout << "Выберите строку:" << endl;
	cin >> string_first;
	cout << "Введите начальный столбик:" << endl;
	cin >> column_first;
	for (int i = column_first - 1; i < column_first + x; i++) {
		if (massive[string_first - 1][i] == '-' and column_first != y) massive[string_first - 1][i] = 'K';
		else {
			Gorizontal(massive, x, y, count_ships);
		}
	}
	count_ships--;
	Show_Place(massive);
	if (count_ships == 0) cout << "У вас кончился данный тип кораблей!" << endl;
	cout << endl;
	return count_ships;
}
int Vertical(char massive[10][10], int x, int y, int count_ships) {
	int column_first, string_first;
	cout << "Выберите столбик:" << endl;
	cin >> column_first;
	cout << "Введите строчку:" << endl;
	cin >> string_first;
	for (int i = string_first - 1; i < string_first + x; i++) {
		if ((massive[i][column_first - 1] == '-') and string_first < y) massive[i][column_first - 1] = 'K';
		else {
			cout << "Ошибка..." << endl;
			Vertical(massive, x, y, count_ships);
		}
	}
	count_ships--;
	Show_Place(massive);
	if (count_ships == 0) cout << "У вас кончился данный тип кораблей!" << endl;
	cout << endl;
	return count_ships;
}
char Player_Move(char massive[10][10]) {
	int count = 0;
	int one = 4, two = 3, three = 2, four = 1, number;
	char ch;
	do {
		Menu(one, two, three, four);
		cin >> number;
		if (number == 1) {
			one = Vertical(massive, 0, 10, one);
		}
		if (number == 2) {
			cout << "Вы хотите поставить его вертикально или горизонтально? Вертикально - v/V, горизонтально - g/G" << endl;
			cin >> ch;
			if (ch == 'v' or ch == 'V') {
				two = Vertical(massive, 1, 10, two);
			}
			else if (ch == 'g' or ch == 'G') {
				two = Gorizontal(massive, 1, 10, two);
			}
		}
		if (number == 3) {
			cout << "Вы хотите поставить его вертикально или горизонтально? Вертикально - v/V, горизонтально - g/G" << endl;
			cin >> ch;
			if (ch == 'v' or ch == 'V') {
				three = Vertical(massive, 2, 9, three);
			}
			else if (ch == 'g' or ch == 'G') {
				three = Gorizontal(massive, 2, 9, three);
			}
		}
		if (number == 4) {
			cout << "Вы хотите поставить его вертикально или горизонтально? Вертикально - v/V, горизонтально - g/G" << endl;
			cin >> ch;
			if (ch == 'v' or ch == 'V') {
				four = Vertical(massive, 3, 8, four);
			}
			else if (ch == 'g' or ch == 'G') {
				four = Gorizontal(massive, 3, 8, four);
			}
		}
		if (one == 0 and two == 0 and three == 0 and four == 0) count++;
	} while (count == 0);
	cout << "Все ваши корабли кончились. Теперь свои корабли расставляет компьютер!\n";
	return 0;
}