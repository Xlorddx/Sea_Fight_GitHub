//лнпяйни ани
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "Functions.h"

using namespace std;

int main(int argc, char* argv[]) {
	setlocale(0, "");
	//Show_Place(place);
	//cout << endl;
	Show_Place_Virt(place_virt);
	cout << endl;
	//Player_Move(place);
	Virtual_Move(place_virt);
	return 0;
}