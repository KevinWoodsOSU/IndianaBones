/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "space.h"

Space::Space() {
	setHasAnimal(false);
	setAnimal(NULL);
}

void Space::setAnimal(Animal* a) {
	thisAnimal = a;
}

Animal* Space::getAnimal() {
	return thisAnimal;
}

void Space::setUp(Space* u) {
	up = u;
}

Space* Space::getUp() {
	return up;
}

void Space::setDown(Space* d) {
	down = d;
}

Space* Space::getDown() {
	return down;
}

void Space::setLeft(Space* l) {
	left = l;
}

Space* Space::getLeft() {
	return left;
}

void Space::setRight(Space* r) {
	right = r;
}

Space* Space::getRight() {
	return right;
}

void Space::setHasAnimal(bool ha) {
	hasAnimal = ha;
}

bool Space::getHasAnimal() {
	return hasAnimal;
}

void Space::setHasMap(bool has) {
	hasMap = has;
}

bool Space::getHasMap() {
	return hasMap;
}

void Space::setSpaceType(SpaceType t) {
	thisType = t;
}
SpaceType Space::getSpaceType() {
	return thisType;
}