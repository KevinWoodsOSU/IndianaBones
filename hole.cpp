/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "hole.h"


Hole::Hole() {
	setSpaceType(HOLE);
	setHasMap(false);
}

void Hole::display() {
    if (getAnimal() == NULL && !getHasMap())
         cout << ".";
    else if (getAnimal() == NULL && getHasMap())
         cout << "X";
    else if (getAnimal()->getAnimalType() == INDY)
        cout << "I";
           
}