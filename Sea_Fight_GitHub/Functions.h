#pragma once
#include <iostream>

char Show_Place_Virt(char massive_virt[10][10]);
char Show_Place(char massive[10][10]);
int Gorizontal(char massive[10][10], int x, int y, int count_ships);
int Vertical(char massive[10][10], int x, int y, int count_ships);
void Menu(int, int, int, int);
char Player_Move(char massive[10][10]);
char Virtual_Move(char massive_virt[10][10]);
char Player_Kill(char massive_virt[10][10]);