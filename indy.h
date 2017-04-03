/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef INDY_H
#define INDY_H

#include "animal.h"

class Indy : public Animal {
private:
	vector<Item> itemVec; //Vector of Items to store Items Indy picks up
public:
	Indy(); //Constructor sets up Indy's fighting stats
	void deleteVector(); //Free memory stored in vector
	
	void addItem(Item); //Adds Item to vector. Limits vector size to 4 Items
	void searchItems(); //Lists Items currently owned
	bool hasItem(string); //Returns true if Indy has a specific Item

	//Get and set methods
	void setMovedThisTurn(bool);
	bool getMovedThisTurn();

	int virtual attackRoll(); //Attack function
	void virtual defenseResult(int, attackEffect); //Calculates damage taken
};


#endif

