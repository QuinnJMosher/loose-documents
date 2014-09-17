#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

class Zombie {
public:
	Zombie();
	Zombie(int in_health, int in_attack, char* in_occupation);

	int getHealth();
	int getAttack();
	char* getPreviousOccupation();

	void setHealth(int in_health);
	void setAttack(int in_attack);
	void setPreviousOccupation(char* in_setPreviousOccupation);

	void fight(Zombie &in_other);


private:
	int health;
	int attack;
	bool isAlive;
	char* previousOccupation;

};

#endif