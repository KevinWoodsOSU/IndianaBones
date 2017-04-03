/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef ITEM_H
#define ITEM_h

#include "menu.h"

//Items contain only a string variable to represent item type

class Item {
private:
	string name;
public:
	Item();
	Item(string);
	void setName(string);
	string getName();

};

#endif