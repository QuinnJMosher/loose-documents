#include <iostream>
#include <ctime>

using namespace std;

struct Knight {
	unsigned int hitPoints;
	unsigned int armor;
	char* title;
	char* name;
	bool canFight;

	void create() {

		hitPoints = rand() % 100 + 1;
		armor = rand() % 20 + 1;
		canFight = true;

		switch (rand() % 4) {
		case 0:
			title = "Sir";
			break;
		case 1:
			title = "Lord";
			break;
		case 2:
			title = "Earl";
			break;
		case 3:
			title = "Knight";
			break;
		case 4:
			title = "Lady";
			break;
		case 5:
			title = "Thane";
			break;
		}
		
		switch (rand() % 5) {
		case 0:
			name = "Mobley";
			break;
		case 1:
			name = "Back";
			break;
		case 2:
			name = "Corbitt";
			break;
		case 3:
			name = "Mosher";
			break;
		case 4:
			name = "Muir";
			break;
		}
	}

	void attack(Knight &other) {
		int attackDammage = (rand() % 25 + 1) - other.armor;
		if (attackDammage > 0) {
			cout << title << " " << name << " has attacked " << other.title << " " << other.name << " for " << attackDammage << " dammage! \n";
			other.hitPoints -= attackDammage;
			if (other.hitPoints <= 0) {
				cout << other.title << " " << other.name << " has died.\n";
				other.canFight = false;
				system("pause");
			}
		} else {
			cout << title << " " << name << " missed " << other.title << " " << other.name << ".\n";
		}
	}
};

Knight team1[5];
Knight team2[5];
bool team1CanFight = true;
bool team2CanFight = true;

/*
void main() {
	srand(time(NULL));

	for (int i = 0; i < 5; i++) {
		team1[i].create();
	}

	for (int i = 0; i < 5; i++) {
		team2[i].create();
	}

	while (team1CanFight && team2CanFight) {
		int target = rand() % 5;
		int source = rand() % 5;

		while (!team1[source].canFight || !team2[target].canFight) {
			target = rand() % 5;
			source = rand() % 5;
		}

		team1[source].attack(team2[target]);

		target = rand() % 5;
		source = rand() % 5;

		while (!team1[target].canFight || !team2[source].canFight) {
			target = rand() % 5;
			source = rand() % 5;
		}

		team2[source].attack(team1[target]);

		team1CanFight = false;
		for (int i = 0; i < 10; i++) {
			if (team1[i].canFight) {
				team1CanFight = true;
				break;
			}
		}

		team2CanFight = false;
		for (int i = 0; i < 10; i++) {
			if (team2[i].canFight) {
				team2CanFight = true;
				break;
			}
		}
		//system("pause");

	}

	if (team1CanFight) {
		cout << "team 1 has won!\n";
	} else {
		cout << "team 2 has won!\n";
	}
	system("pause");
}*/