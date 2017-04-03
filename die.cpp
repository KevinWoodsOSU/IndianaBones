/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "die.h"

Die::Die() {
}

Die::Die(int num, int size) {
	setNumberOfDie(num);
	setSizeOfDie(size);
}

void Die::setNumberOfDie(int n) {
	numberOfDie = n;
}

int Die::getNumberOfDie() {
	return numberOfDie;
}

void Die::setSizeOfDie(int s) {
	sizeOfDie = s;
}

int Die::getSizeOfDie() {
	return sizeOfDie;
}

int Die::rollDie() {
	int total = 0;
	for (int i = 0; i < getNumberOfDie(); i++) {
		total += 1 + (rand() % getSizeOfDie());
	}

	return total;
}