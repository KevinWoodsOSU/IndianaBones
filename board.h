
#ifndef BOARD_H
#define BOARD_H

#include "space.h"
#include "grass.h"
#include "wall.h"
#include "hole.h"
#include "menu.h"
#include "indy.h"
#include "dog.h"
#include "human.h"
/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

class Board {
protected:
	int size; //Determines the size of the board
	Animal* animalPtr; //Points to Animal type, used if Animal is on current element

public:
	Board();

	//Virtual function delcarations
	virtual void print() = 0;
	virtual Space* getElement(int, int) = 0;
	virtual void moveAnimals() = 0;
	virtual bool moveHuman(int, int) = 0;
	virtual void resetMoveTrack() = 0;
	virtual void destroyBoard() = 0;
	virtual void addHuman(int, int) = 0;

	//Get and set methods
	void setSize(int);
	int getSize();
	void setAnimal(Animal*);
	Animal* getAnimal();
	
};

#endif
