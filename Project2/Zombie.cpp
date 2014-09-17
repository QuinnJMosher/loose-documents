#include "Zombie.h";

	Zombie::Zombie() {
		health = 50;
		attack = 10;
		previousOccupation = "Busness dude";
		isAlive = true;
	}

	Zombie::Zombie(int in_health, int in_attack, char* in_occupation) {
		health = in_health;
		attack = in_attack;
		previousOccupation = in_occupation;
		if (in_health > 0) {
			isAlive = true;
		} else {
			isAlive = false;
		}
	}

	int Zombie::getHealth() {
		return health;
	}

	int Zombie::getAttack() {
		return attack;
	}

	char* Zombie::getPreviousOccupation() {
		return previousOccupation;
	}

	void Zombie::setHealth(int in_health) {
		if (in_health < 0) {
			health = 0;
		}
		else {
			health = in_health;
		}

		if (health == 0) {
			isAlive = false;
		}
	}

	void Zombie::setAttack(int in_attack) {
		if (in_attack < 0) {
			attack = 1;
		} else {
		attack = in_attack;
		}
	}

	void Zombie::setPreviousOccupation(char* in_previousOccupation) {
		previousOccupation = in_previousOccupation;
	}

	void Zombie::fight(Zombie &in_other) {
		in_other.setHealth(in_other.getHealth() - attack);

	}