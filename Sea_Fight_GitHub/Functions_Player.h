#pragma once

void Show_Place(char massive[10][10]);
void Show_Place_With_X(char massive_with_x[10][10]);

void Menu(int, int, int, int);

int Gorizontal(char massive[10][10], int x, int y, int count_ships);
int Vertical(char massive[10][10], int x, int y, int count_ships);

int Player_Shoot(char(*)[10], int count_killed_virt_ships, char(*)[10]);
char Player_Move(char(*)[10]);
