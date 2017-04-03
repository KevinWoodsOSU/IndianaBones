/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "wall.h"

Wall::Wall() {
	setSpaceType(WALL);
}

void Wall::display() {
	if (getAnimal() == NULL)
		cout << "/";
	else if (getAnimal()->getAnimalType() == INDY)
		cout << "I";
	else if (getAnimal()->getAnimalType() == DOG)
		cout << "D";
}