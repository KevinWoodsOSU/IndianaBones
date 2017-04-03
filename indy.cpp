/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "indy.h"

Indy::Indy() {
	setAnimalType(INDY);
	setHealth(20);
	setMaxHealth(20);
	setArmor(0);
	Die defenseDie(2, 6);
	Die attackDie(2, 6);
	setDefense(defenseDie);
	setAttack(attackDie);
	setAnimalName("Indy");
}

void Indy::deleteVector() {
	vector<Item> temp;
	itemVec.swap(temp);
}

void Indy::setMovedThisTurn(bool a) {}

bool Indy::getMovedThisTurn() {
	return false;
}

void Indy::addItem(Item i) {
	if (itemVec.size() > 4) {
		cout << "Your pack doesn't have enough room." << endl;
	}
	else
		itemVec.push_back(i);
}

bool Indy::hasItem(string item) {
	for (int i = 0; i < itemVec.size(); i++) {
		if (itemVec[i].getName() == item)
			return true;
	}
	return false;
}

void Indy::searchItems() {
	for (int i = 0; i < itemVec.size(); i++) {
		cout << endl;
		cout << i << ". " << itemVec[i].getName();
	}
}

int Indy::attackRoll() {
	int damage = getAttack().rollDie();
	return damage;
}

void Indy::defenseResult(int attack, attackEffect effect) {
	if (hasItem("Spiked Collar"))
		setArmor(1);
	defenseCalculations(attack, effect);
}

