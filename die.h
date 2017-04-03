/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef DIE_H
#define DIE_H

#include "menu.h"

class Die {
private:
	int numberOfDie; //Tracks how many die are rolled
	int sizeOfDie; //Tracks how many sides each die has

public:
	Die(); //Default constructor
	Die(int, int); //Constructor initializes number and size of die

	//get and set methods
	void setNumberOfDie(int);
	int getNumberOfDie();
	void setSizeOfDie(int);
	int getSizeOfDie();

	int rollDie(); //Returns the value of dice roll
};

#endif
