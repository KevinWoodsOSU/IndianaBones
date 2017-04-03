/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "grass.h"

Grass::Grass() {
	setSpaceType(GRASS);
}

void Grass::display() {
	if (getAnimal() == NULL)
		cout << ".";
	else if (getAnimal()->getAnimalType() == INDY)
		cout << "I";
	else if (getAnimal()->getAnimalType() == DOG)
		cout << "D";
	else if (getAnimal()->getAnimalType() == HUMAN)
		cout << "H";
}