#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

void Show_Place(char massive[10][10]) {
	int i, j, numb = 1;;
	cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << endl;
	for (i = 0; i < 10; i++) {
		cout << numb << "\t";
		for (j = 0; j < 10; j++) {
			cout << massive[i][j] << "\t";
		}
		numb++;
		cout << endl;
	}
}

void Show_Place_With_X(char massive_with_x[10][10]) {
	int i, j, numb = 1;;
	cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << endl;
	for (i = 0; i < 10; i++) {
		cout << numb << "\t";
		for (j = 0; j < 10; j++) {
			cout << massive_with_x[i][j] << "\t";
		}
		numb++;
		cout << endl;
	}
}

void Menu(int counter_0, int counter_1, int counter_2, int counter_3) {
	cout << "-------------------------------------------------------" << endl;
	cout << "Какой тип корабля вы хотите поставить?" << endl;
	cout << "Однопалубный - 1 (Осталось: " << counter_0 << ");" << endl;
	cout << "Двухпалубный - 2 (Осталось: " << counter_1 << ");" << endl;
	cout << "Трёхпалубный - 3 (Осталось: " << counter_2 << ");" << endl;
	cout << "Четырёхпалубный - 4 (Осталось: " << counter_3 << ");" << endl;
	cout << "-------------------------------------------------------" << endl;
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
char Player_Move(char (*massive)[10]){
	int count = 0;
	int one = 4, two = 3, three = 2, four = 1, number;
	char ch;
	do {
		Menu(one, two, three, four);
		cin >> number;
		if (number == 1) {
			if (one != 0) {
				one = Vertical(massive, 0, 11, one);
			}
			else {
				cout << "Вы больше не можете выбирать эти корабли!" << endl << endl;
				continue;
			}
		}
		if (number == 2) {
			if (two != 0) {
				cout << "Вы хотите поставить его вертикально или горизонтально? Вертикально - v/V, горизонтально - g/G" << endl;
				cin >> ch;
				if (ch == 'v' or ch == 'V') {
					two = Vertical(massive, 1, 10, two);
				}
				else if (ch == 'g' or ch == 'G') {
					two = Gorizontal(massive, 1, 10, two);
				}
			}
			else {
				cout << "Вы больше не можете выбирать эти корабли!" << endl << endl;
				continue;
			}
		}
		if (number == 3) {
			if (three != 0) {
				cout << "Вы хотите поставить его вертикально или горизонтально? Вертикально - v/V, горизонтально - g/G" << endl;
				cin >> ch;
				if (ch == 'v' or ch == 'V') {
					three = Vertical(massive, 2, 9, three);
				}
				else if (ch == 'g' or ch == 'G') {
					three = Gorizontal(massive, 2, 9, three);
				}
			}
			else {
				cout << "Вы больше не можете выбирать эти корабли!" << endl << endl;
				continue;
			}
		}
		if (number == 4) {
			if (four != 0) {
				cout << "Вы хотите поставить его вертикально или горизонтально? Вертикально - v/V, горизонтально - g/G" << endl;
				cin >> ch;
				if (ch == 'v' or ch == 'V') {
					four = Vertical(massive, 3, 8, four);
				}
				else if (ch == 'g' or ch == 'G') {
					four = Gorizontal(massive, 3, 8, four);
				}
			}
			else {
				cout << "Вы больше не можете выбирать эти корабли!" << endl << endl;
				continue;
			}
		}
		if (number == 0) count++;
		if (one == 0 and two == 0 and three == 0 and four == 0) count++;
	} while (count == 0);
	cout << "Все ваши корабли кончились. Теперь свои корабли расставляет компьютер!\n";
	return 0;
}

int Player_Shoot(char (*massive_virt)[10], int count_killed_virt_ships, char (*place_with_x)[10]) {
	int x = 0, y = 0, count = 0;
	do {
		cout << "Вот ваше вспомогательное поле:" << endl;
		Show_Place(place_with_x);
		cout << "Введите координаты(сначала строчка, потом столбец):" << endl;
		cin >> x >> y;
		switch (x)
		{
		case 1:
			switch (y)
			{
			case 1:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == '-' or massive_virt[x][y - 1] == 'X') and (massive_virt[x - 1][y] == '-' or massive_virt[x - 1][y] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == 'S' or massive_virt[x - 1][y] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			case 2:case 3:case 4:case 5: case 6: case 7: case 8: case 9:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == '-' or massive_virt[x][y - 1] == 'X') and (massive_virt[x - 1][y] == '-' or massive_virt[x - 1][y] == 'X') and (massive_virt[x - 1][y - 2] == '-' or massive_virt[x - 1][y - 2] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == 'S' or massive_virt[x - 1][y] == 'S' or massive_virt[x - 1][y - 2] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			case 10:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == '-' or massive_virt[x][y - 1] == 'X') and (massive_virt[x - 1][y - 2] == '-' or massive_virt[x - 1][y - 2] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == 'S' or massive_virt[x - 1][y - 1] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			default:
				break;
			}
			break;
		case 2:case 3:case 4:case 5: case 6: case 7: case 8: case 9:
			switch (y)
			{
			case 1:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == '-' or massive_virt[x][y - 1] == 'X') and (massive_virt[x - 1][y] == '-' or massive_virt[x - 1][y] == 'X') and (massive_virt[x - 2][y - 1] == '-' or massive_virt[x - 2][y - 1] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == 'S' or massive_virt[x - 1][y] == 'S' or massive_virt[x - 2][y - 1] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			case 2:case 3:case 4:case 5: case 6: case 7: case 8: case 9:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == '-' or massive_virt[x][y - 1] == 'X') and (massive_virt[x - 1][y] == '-' or massive_virt[x - 1][y] == 'X') and (massive_virt[x - 1][y - 2] == '-' or massive_virt[x - 1][y - 2] == 'X') and (massive_virt[x - 2][y - 1] == '-' or massive_virt[x - 2][y - 1] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == 'S' or massive_virt[x - 1][y] == 'S' or massive_virt[x - 1][y - 2] == 'S' or massive_virt[x - 2][y - 1] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			case 10:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x][y - 1] == '-' or massive_virt[x][y - 1] == 'X') and (massive_virt[x - 1][y - 2] == '-' or massive_virt[x - 1][y - 2] == 'X') and (massive_virt[x - 2][y - 1] == '-' or massive_virt[x - 2][y - 1] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x - 2][y - 1] == 'S' or massive_virt[x][y - 1] == 'S' or massive_virt[x - 1][y - 2] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			default:
				break;
			}
			break;
		case 10:
			switch (y)
			{
			case 1:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x - 1][y] == '-' or massive_virt[x - 1][y] == 'X') and (massive_virt[x - 2][y - 1] == '-' or massive_virt[x - 2][y - 1] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x - 1][y] == 'S' or massive_virt[x - 2][y - 1] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			case 2:case 3:case 4:case 5: case 6: case 7: case 8: case 9:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x - 1][y - 2] == '-' or massive_virt[x - 1][y - 2] == 'X') and (massive_virt[x - 1][y] == '-' or massive_virt[x - 1][y] == 'X') and (massive_virt[x - 2][y - 2] == '-' or massive_virt[x - 2][y - 2] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x - 1][y - 2] == 'S' or massive_virt[x - 1][y] == 'S' or massive_virt[x - 2][y - 2] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			case 10:
				if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x - 2][y - 1] == '-' or massive_virt[x - 2][y - 1] == 'X') and (massive_virt[x - 1][y - 2] == '-' or massive_virt[x - 1][y - 2] == 'X')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Убил!" << endl;
					count_killed_virt_ships++;
				}
				else if (massive_virt[x - 1][y - 1] == 'S' and (massive_virt[x - 2][y - 1] == 'S' or massive_virt[x - 1][y - 2] == 'S')) {
					place_with_x[x - 1][y - 1] = 'X';
					massive_virt[x - 1][y - 1] = 'X';
					Show_Place(place_with_x);
					cout << "Ранил!" << endl;
					count_killed_virt_ships++;
				}
				else {
					cout << "Промахнулся!" << endl;
					count = -1;
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		//cout << count_killed_virt_ships << endl;
		//if (count_killed_virt_ships == 20) count = -1;
	} while (count != -1);
	return count_killed_virt_ships;
}