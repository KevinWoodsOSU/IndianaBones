/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "dog.h"

Dog::Dog() {
	setAnimalType(DOG);
	setMovedThisTurn(false);
}

Dog::Dog(string name) {
	setAnimalType(DOG);
	setMovedThisTurn(false);
	setHealth(10);
	setMaxHealth(10);
	setArmor(1);
	Die defenseDie(2, 4);
	Die attackDie(2, 4);
	setDefense(defenseDie);
	setAttack(attackDie);
	setAnimalName(name);
}

void Dog::setMovedThisTurn(bool m) {
	movedThisTurn = m;
}

bool Dog::getMovedThisTurn() {
	return movedThisTurn;
}

int Dog::attackRoll() {
	int damage = getAttack().rollDie();
	return damage;
}

void Dog::defenseResult(int attack, attackEffect effect) {
	defenseCalculations(attack, effect);
}

void Dog::addItem(Item a) {}

void Dog::searchItems() {}

bool Dog::hasItem(string i) { return false; }

void Dog::deleteVector() {}