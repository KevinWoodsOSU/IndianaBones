/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef HUMAN_H
#define HUMAN_H

#include "animal.h"

class Human : public Animal {
private:
	bool movedThisTurn; //Tracks if Human moved for each moveHuman call
public:
	Human(); //Sets name and type

	//Virtual function declarations
	virtual void setMovedThisTurn(bool);
	virtual bool getMovedThisTurn();
	virtual void addItem(Item);
	virtual void searchItems();
	virtual bool hasItem(string);
	virtual void deleteVector();
	int virtual attackRoll(); 
	void virtual defenseResult(int, attackEffect);
};


#endif