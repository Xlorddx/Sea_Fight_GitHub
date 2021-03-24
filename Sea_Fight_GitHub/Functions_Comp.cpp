#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Functions_Player.h"

using namespace std;

char Show_Place_Virt(char massive_virt[10][10]) {
	int i, j, numb = 1;;
	cout << "\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10" << endl;
	for (i = 0; i < 10; i++) {
		cout << numb << "\t";
		for (j = 0; j < 10; j++) {
			cout << massive_virt[i][j] << "\t";
		}
		numb++;
		cout << endl;
	}
	return 0;
}

char Virtial_Move_Gorizontal(char massive_virt[10][10], int x, int y) {
	int string_i = rand() % 10;
	int column_j = rand() % 10;
	int count = 0;
	if (column_j == 0 and string_i > 0 and string_i < 9) {
		for (int i = string_i - 1; i < string_i + 2; i++) {
			for (int j = column_j; j < column_j + 2 + x; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (x == 0 and column_j == 9 and string_i > 0 and string_i < 9) {
		for (int i = string_i - 1; i < string_i + 2; i++) {
			for (int j = column_j - 1; j < column_j + 1; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 0 and column_j > 0 and column_j < 9) {
		for (int i = string_i; i < string_i + 2; i++) {
			for (int j = column_j - 1; j < column_j + 2 + x; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 9 and column_j > 0 and column_j < 9) {
		for (int i = string_i - 1; i < string_i + 1; i++) {
			for (int j = column_j - 1; j < column_j + 2 + x; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 0 and column_j == 0) {
		for (int i = string_i; i < string_i + 2; i++) {
			for (int j = column_j; j < column_j + 2 + x; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (x == 0 and string_i == 0 and column_j == 9) {
		for (int i = string_i; i < string_i + 2; i++) {
			for (int j = column_j - 1; j < column_j + 1; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 9 and column_j == 0) {
		for (int i = string_i - 1; i < string_i + 1; i++) {
			for (int j = column_j; j < column_j + 2 + x; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (x == 0 and string_i == 9 and column_j == 9) {
		for (int i = string_i - 1; i < string_i + 1; i++) {
			for (int j = column_j - 1; j < column_j + 1; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i > 0 and string_i < 9 and column_j > 0 and column_j < 9) {
		for (int i = string_i - 1; i < string_i + 2; i++) {
			for (int j = column_j - 1; j < column_j + 2 + x; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	if (count == 0) Virtial_Move_Gorizontal(massive_virt, x, y);
	else if (x == 0) massive_virt[string_i][column_j] = 'S';
	else if (x == 1) {
		for (int j = column_j; j < column_j + y; j++) {
			massive_virt[string_i][j] = 'S';
		}
	}
	else if (x == 2) {
		for (int j = column_j; j < column_j + y; j++) {
			massive_virt[string_i][j] = 'S';
		}
	}
	else if (x == 3) {
		for (int j = column_j; j < column_j + y; j++) {
			massive_virt[string_i][j] = 'S';
		}
	}
	return 0;
}

char Virtual_Move_Vertical(char massive_virt[10][10], int x, int y) {
	int string_i = rand() % 10;
	int column_j = rand() % 10;
	int count = 0;
	if (column_j == 0 and string_i > 0 and string_i < 9) {
		for (int i = string_i - 1; i < string_i + 2 + x; i++) {
			for (int j = column_j; j < column_j + 2; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (x == 0 and column_j == 9 and string_i > 0 and string_i < 9) {
		for (int i = string_i - 1; i < string_i + 2; i++) {
			for (int j = column_j - 1; j < column_j + 1; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 0 and column_j > 0 and column_j < 9) {
		for (int i = string_i; i < string_i + 2 + x; i++) {
			for (int j = column_j - 1; j < column_j + 2; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 9 and column_j > 0 and column_j < 9) {
		for (int i = string_i - 1; i < string_i + 1 + x; i++) {
			for (int j = column_j - 1; j < column_j + 2; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 0 and column_j == 0) {
		for (int i = string_i; i < string_i + 2 + x; i++) {
			for (int j = column_j; j < column_j + 2; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (x == 0 and string_i == 0 and column_j == 9) {
		for (int i = string_i; i < string_i + 2; i++) {
			for (int j = column_j - 1; j < column_j + 1; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i == 9 and column_j == 0) {
		for (int i = string_i - 1; i < string_i + 1 + x; i++) {
			for (int j = column_j; j < column_j + 2; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (x == 0 and string_i == 9 and column_j == 9) {
		for (int i = string_i - 1; i < string_i + 1; i++) {
			for (int j = column_j - 1; j < column_j + 1; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	else if (string_i > 0 and string_i < 9 and column_j > 0 and column_j < 9) {
		for (int i = string_i - 1; i < string_i + 2 + x; i++) {
			for (int j = column_j - 1; j < column_j + 2; j++) {
				if (massive_virt[i][j] == '-') count++;
				else {
					count = 0;
					break;
				}
			}
			if (count == 0) break;
		}
	}
	if (count == 0) Virtual_Move_Vertical(massive_virt, x, y);
	else if (x == 0) massive_virt[string_i][column_j] = 'S';
	else if (x == 1) {
		for (int i = string_i; i < string_i + y; i++) {
			massive_virt[i][column_j] = 'S';
		}
	}
	else if (x == 2) {
		for (int i = string_i; i < string_i + y; i++) {
			massive_virt[i][column_j] = 'S';
		}
	}
	else if (x == 3) {
		for (int i = string_i; i < string_i + y; i++) {
			massive_virt[i][column_j] = 'S';
		}
	}
	return 0;
}

char Virtual_Move(char massive_virt[10][10]) {
	srand(time(0));
	int count = 0;
	int one = 4, two = 3, three = 2, four = 1;
	do {
		int random_case = 0;
		do {
			Virtial_Move_Gorizontal(massive_virt, 0, 1);
			one--;
		} while (one != 0);
		do {
			random_case = rand() % 2 + 1; // 1 - горизонтально, 2 - вертикально.
			switch (random_case)
			{
			case 1:
				Virtial_Move_Gorizontal(massive_virt, 1, 2);
				two--;
				break;
			case 2:
				Virtual_Move_Vertical(massive_virt, 1, 2);
				two--;
				break;
			default:
				break;
			}
		} while (two != 0);
		do {
			random_case = rand() % 2 + 1; // 1 - горизонтально, 2 - вертикально.
			switch (random_case)
			{
			case 1:
				Virtial_Move_Gorizontal(massive_virt, 2, 3);
				three--;
				break;
			case 2:
				Virtual_Move_Vertical(massive_virt, 2, 3);
				three--;
				break;
			default:
				break;
			}
		} while (three != 0);
		do {
			random_case = rand() % 2 + 1; // 1 - горизонтально, 2 - вертикально.
			switch (random_case)
			{
			case 1:
				Virtial_Move_Gorizontal(massive_virt, 3, 4);
				four--;
				break;
			case 2:
				Virtual_Move_Vertical(massive_virt, 3, 4);
				four--;
				break;
			default:
				break;
			}
		} while (four != 0);
		count++;
	} while (count == 0);
	//Show_Place_Virt(massive_virt);
	cout << endl;
	return 0;
}

int Virtual_Shoot(char massive[10][10], int count_killed_player_ships) {
	srand(time(0));
	int x = 0, y = 0, count = 0;
	do {
		x = rand() % 10 + 1;
		y = rand() % 10 + 1;
		switch (x)
		{
		case 1:
			switch (y)
			{
			case 1:
				if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == '-' or massive[x][y - 1] == 'X') and (massive[x - 1][y] == '-' or massive[x - 1][y] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == 'S' or massive[x - 1][y] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
					count = -1;
				}
				break;
			case 2:case 3:case 4:case 5: case 6: case 7: case 8: case 9:
				if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == '-' or massive[x][y - 1] == 'X') and (massive[x - 1][y] == '-' or massive[x - 1][y] == 'X') and (massive[x - 1][y - 2] == '-' or massive[x - 1][y - 2] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == 'S' or massive[x - 1][y] == 'S' or massive[x - 1][y - 2] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
					count = -1;
				}
				break;
			case 10:
				if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == '-' or massive[x][y - 1] == 'X') and (massive[x - 1][y - 2] == '-' or massive[x - 1][y - 2] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == 'S' or massive[x - 1][y - 1] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
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
				if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == '-' or massive[x][y - 1] == 'X') and (massive[x - 1][y] == '-' or massive[x - 1][y] == 'X') and (massive[x - 2][y - 1] == '-' or massive[x - 2][y - 1] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == 'S' or massive[x - 1][y] == 'S' or massive[x - 2][y - 1] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
					count = -1;
				}
				break;
			case 2:case 3:case 4:case 5: case 6: case 7: case 8: case 9:
				if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == '-' or massive[x][y - 1] == 'X') and (massive[x - 1][y] == '-' or massive[x - 1][y] == 'X') and (massive[x - 1][y - 2] == '-' or massive[x - 1][y - 2] == 'X') and (massive[x - 2][y - 1] == '-' or massive[x - 2][y - 1] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == 'S' or massive[x - 1][y] == 'S' or massive[x - 1][y - 2] == 'S' or massive[x - 2][y - 1] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
					count = -1;
				}
				break;
			case 10:
				if (massive[x - 1][y - 1] == 'S' and (massive[x][y - 1] == '-' or massive[x][y - 1] == 'X') and (massive[x - 1][y - 2] == '-' or massive[x - 1][y - 2] == 'X') and (massive[x - 2][y - 1] == '-' or massive[x - 2][y - 1] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x - 2][y - 1] == 'S' or massive[x][y - 1] == 'S' or massive[x - 1][y - 2] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
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
				if (massive[x - 1][y - 1] == 'S' and (massive[x - 1][y] == '-' or massive[x - 1][y] == 'X') and (massive[x - 2][y - 1] == '-' or massive[x - 2][y - 1] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x - 1][y] == 'S' or massive[x - 2][y - 1] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
					count = -1;
				}
				break;
			case 2:case 3:case 4:case 5: case 6: case 7: case 8: case 9:
				if (massive[x - 1][y - 1] == 'S' and (massive[x - 1][y - 2] == '-' or massive[x - 1][y - 2] == 'X') and (massive[x - 1][y] == '-' or massive[x - 1][y] == 'X') and (massive[x - 2][y - 2] == '-' or massive[x - 2][y - 2] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x - 1][y - 2] == 'S' or massive[x - 1][y] == 'S' or massive[x - 2][y - 2] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
					count = -1;
				}
				break;
			case 10:
				if (massive[x - 1][y - 1] == 'S' and (massive[x - 2][y - 1] == '-' or massive[x - 2][y - 1] == 'X') and (massive[x - 1][y - 2] == '-' or massive[x - 1][y - 2] == 'X')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер убил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else if (massive[x - 1][y - 1] == 'S' and (massive[x - 2][y - 1] == 'S' or massive[x - 1][y - 2] == 'S')) {
					massive[x - 1][y - 1] = 'X';
					Show_Place(massive);
					cout << "Компьютер ранил ваш корабль!" << endl;
					count_killed_player_ships++;
				}
				else {
					cout << "Компьютер промахнулся!" << endl << "Теперь ваш ход!" << endl;
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
		cout << count_killed_player_ships << endl;
		if (count_killed_player_ships == 20) count = -1;
	} while (count != -1);
	return count_killed_player_ships;
}