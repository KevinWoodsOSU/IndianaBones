/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef DOG_H
#define DOG_H

#include "animal.h"
#include "die.h"

class Dog : public Animal {
private:
	bool movedThisTurn;
public:
	Dog();
	Dog(string);

	//Virtual function declarations
	virtual void setMovedThisTurn(bool);
	virtual bool getMovedThisTurn();
	virtual void addItem(Item);
	virtual void searchItems();
	virtual bool hasItem(string);
	virtual void deleteVector();

	int virtual attackRoll(); //Handles attack when fighting
	void virtual defenseResult(int, attackEffect); //Calculates damage taken
};


#endif