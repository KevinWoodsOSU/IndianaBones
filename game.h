/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef GAME_H
#define GAME_H

#include "parkBoard.h"
#include "menu.h"
#include "animal.h"
#include "die.h"

class Game {
private:
	int row; //Tracks Indy's row
	int col; //Tracks Indy's column
	int curBoard; //Tracks current board
	bool hasMap; //True if Indy has found the map
	bool endGame; //True if game has ended

	Board* board[3]; //Board array contains 3 pointers to Boards

public:
	Game(); //Initializes variables and creates a ParkBoard object
	~Game(); //Frees memory from board[]

	//Loops through until game has ended. Calls move() and prints board until map has been found
	//When map has been found, user has 1.5 seconds to move Indy or Human moves twice
	//When game is ended, frees memory from Indy, calls deleteVector() and calls destroyBoard()
	void play();

	//Handles user input. Moves Indy to appropriate element, unless that element has a Dog or a Human or is a Wall or Hole when the map has been found
	//Calls moveAnimals() and moveHuman() after player has moved.
	void move();

	//Handles combat between Indy and Dogs. Random chance of who attacks first.
	//Items are picked up by Indy. After defeating the first Dog, he gets a Spiked Collar
	//After defeating the second Dog, Indy picks up map.
	bool fight(Animal*, Animal*); 

	void getCreatureState(Animal*, Animal*); //Displays stats of each Animal
};

#endif
