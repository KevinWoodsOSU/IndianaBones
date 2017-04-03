/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "human.h"

Human::Human() {
	setAnimalName("Human");
	setAnimalType(HUMAN);
	setMovedThisTurn(false);
}

void Human::setMovedThisTurn(bool a) {
	movedThisTurn = a;
}
bool Human::getMovedThisTurn() {
	return movedThisTurn;
}

void Human::addItem(Item) {}
void Human::searchItems() {}
bool Human::hasItem(string) { return false; }
void Human::deleteVector() {}
int Human::attackRoll() { return 0; }
void Human::defenseResult(int, attackEffect) {}