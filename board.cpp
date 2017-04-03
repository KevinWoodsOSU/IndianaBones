/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "board.h"

Board::Board() {};

void Board::setSize(int s) {
	size = s;
}

int Board::getSize() {
	return size;
}

void Board::setAnimal(Animal* a) {
	animalPtr = a;
}

Animal* Board::getAnimal() {
	return animalPtr;
}

