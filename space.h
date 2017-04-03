/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef SPACE_H
#define SPACE_H

#include "menu.h"
#include "animal.h"

enum SpaceType {GRASS, WALL, HOLE}; //Defines the type of Space

class Space {
private:
	Animal* thisAnimal; //Space may have an animal on it

	bool hasAnimal; //True if Space contains an Animal
	bool hasMap; //True if Indy has found the map
	SpaceType thisType; //Enum type to define type of Space

	//Link the surrounding spaces
	Space* up;
	Space* down;
	Space* left;
	Space* right;

public:
	Space(); //Set hasAnimal to false and thisAnimal to NULL
	
	//Polymorphic display function. Checks if Space contains an animal before printing.
	//Wall = "/"
	//Grass = "."
	//Hole = "O"
	//Indy = "I"
	//Dog = "D"
	//Human = "H"
	virtual void display() = 0; 

	//Get and set methods
	void setAnimal(Animal*);
	Animal* getAnimal();
	void setUp(Space*);
	Space* getUp();
	void setDown(Space*);
	Space* getDown();
	void setLeft(Space*);
	Space* getLeft();
	void setRight(Space*);
	Space* getRight();
	void setHasAnimal(bool);
	bool getHasAnimal();
	void setSpaceType(SpaceType);
	SpaceType getSpaceType();
	void setHasMap(bool);
	bool getHasMap();
};

#endif