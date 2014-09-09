#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//prototypes
void setHeros(int inHeros[], int inHeros_length);
bool attack(int in_group[], int in_group_length, int in_target);

const int heros_length = 5;
int heros[heros_length];

void main() {
	srand(time(NULL));
	int input;
	setHeros(heros, heros_length);
	int turn = 0;

	cout << "Five heros attack you! \n";

	while (turn < 5) {
		cout << "Wich hero will you attack? (0 - 4) " << " turn: " << turn + 1 << endl;
		cin >> input;
		if (attack(heros, heros_length, input)) {
			turn++;
		}
		cout << endl;
	}

	cout << "The heros have escaped \n" << "The party's health is at: ";

	for (int i = 0; i < heros_length; i++) {
		if (heros[i] < 0) {
			cout << 0 << " ";
		} else {
			cout << heros[i] << " ";
		}
	}
	cout << endl;

	system("pause");
	
}

void setHeros(int in_Heros[], int in_Heros_length) {
	for (int i = 0; i < in_Heros_length; i++) {
		in_Heros[i] = 100;
	}
}

bool attack(int in_group[], int in_group_length, int in_target) {

	if (in_target < in_group_length && in_target > -1) {

		if (in_group[in_target] > 0) {

			int dammage = ((rand() % 100) + 10) / 2;
			in_group[in_target] -= dammage;
			cout << "Attack dealt " << dammage << " dammage.\n";

			if (in_group[in_target] <= 0) {
				cout << "target has died! \n";
			}

			return true;

		} else {

			cout << "target is already dead! \n";
			return false;

		}

	} else {

		cout << "Invalid Target: " << in_target << endl;
		return false;

	}
}