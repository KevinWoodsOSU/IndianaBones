/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef PARKBOARD_H
#define PARKBOARD_H

#include "board.h"

class ParkBoard: public Board {
private:
	Space*** parkBoard; //2D array of Space pointers representing the dog park

	Animal* d1;
	Animal* d2;
	Animal* h1;
	Animal* I1;

public:
	//Constructor creates the 2D array of Space pointers. Outside edges are Walls, and one Hole is placed in the cornor.
	//Links each adjacent element to the appropriate pointer (Up, Down, Left, Right)
	//Creates an Indy object and two Dog objects and links them with thisAnimal pointers in various Space objects.
	ParkBoard();
	~ParkBoard();

	//destroyBoard() frees memory from parkBoard 2D array as well as the two Dog objects and the Human object
	void destroyBoard();
	void print(); //Prints out the board

	void moveAnimals(); //Moves the Dogs to a random adjacent element 
	bool moveHuman(int, int); //Moves the Human closer to Indy. Row is adjusted first.
	void resetMoveTrack(); //Sets hasMoved to false for Dogs and Humans
	void addHuman(int, int); //Adds a Human object to the board based on where Indy is

	Space* getElement(int, int); //Returns Space pointer to get information in Game.cpp
};

#endif
