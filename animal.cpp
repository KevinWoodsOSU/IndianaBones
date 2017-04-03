/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "animal.h"

Animal::Animal() {}

void Animal::setAnimalType(AnimalType a) {
	thisType = a;
	setAttackEffect(NORMAL);
	setIsDead(false);
}

AnimalType Animal::getAnimalType() {
	return thisType;
}

void Animal::setHealth(int h) {
	health = h;
}

int Animal::getHealth() {
	return health;
}

void Animal::setMaxHealth(int m) {
	maxHealth = m;
}

int Animal::getMaxHealth() {
	return maxHealth;
}

void Animal::setArmor(int a) {
	armor = a;
}

int Animal::getArmor() {
	return armor;
}

void Animal::setDefense(Die d) {
	defense = d;
}

Die Animal::getDefense() {
	return defense;
}

void Animal::setAttack(Die att) {
	attack = att;
}

Die Animal::getAttack() {
	return attack;
}

void Animal::setAttackEffect(attackEffect ae) {
	effect = ae;
}

attackEffect Animal::getAttackEffect() {
	return effect;
}

void Animal::setIsDead(bool dead) {
	isDead = dead;
}

bool Animal::getIsDead() {
	return isDead;
}

void Animal::setAnimalName(string name) {
	animalName = name;
}

string Animal::getAnimalName() {
	return animalName;
}

void Animal::defenseCalculations(int attack, attackEffect effect) {
	int blocked, damageTaken;
	blocked = getDefense().rollDie() + getArmor();
	cout << getAnimalName() << " blocked " << blocked << " damage." << endl;
	if (attack - blocked > 0) {
		damageTaken = attack - blocked;
		setHealth(getHealth() - damageTaken);
		cout << getAnimalName() << " took " << damageTaken << " damage. "
			<< getAnimalName() << "'s health dropped to " << getHealth() << "." << endl << endl;
		//Checks if Creature has died
		if (getHealth() < 1) {
			cout << endl << getAnimalName() << " has been defeated and scurries away." << endl << endl;
			setIsDead(true);
		}
	}
	else
		cout << getAnimalName() << " takes no damage!" << endl << endl;
}
