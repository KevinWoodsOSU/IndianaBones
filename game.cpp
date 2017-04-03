/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "game.h"

Game::Game() {
	row = 1;
	col = 1;
	curBoard = 0;
	hasMap = false;
	endGame = false;

	board[0] = new ParkBoard;
	//board[1] = new TunnelBoard;
	//board[2] = new OutsideBoard;
}

Game::~Game() {
	delete board[0];
}

void Game::move() {
	char moveDir;
	board[curBoard]->resetMoveTrack();
	Space* nextElement = NULL;
	Space* currentElement = board[curBoard]->getElement(row, col);
	int newRow = row;
	int newCol = col;
	moveDir = getChar();
	switch (moveDir) {
	case 'w':
		nextElement = board[curBoard]->getElement(row, col)->getUp();
		newRow = row - 1;
		break;
	case 'a':
		nextElement = board[curBoard]->getElement(row, col)->getLeft();
		newCol = col - 1;
		break;
	case 's':
		nextElement = board[curBoard]->getElement(row, col)->getDown();
		newRow = row + 1;
		break;
	case 'd':
		nextElement = board[curBoard]->getElement(row, col)->getRight();
		newCol = col + 1;
		break;
	default:
		cout << "Incorrect input" << endl;
	}

	if ((moveDir == 'w') || (moveDir == 'a') || (moveDir == 's') || (moveDir == 'd')) {
		//Do nothing if next space is a Wall
		if (nextElement->getSpaceType() == WALL) {
			cout << endl << "Ouch! Indy ran into a wall." << endl;
			newRow = row;
			newCol = col;
		}
		//Fight if Indy encounters a Dog
		else if (nextElement->getAnimal() != NULL && nextElement->getAnimal()->getAnimalType() != HUMAN) {
			if (fight(currentElement->getAnimal(), nextElement->getAnimal())) {
				nextElement->setAnimal(currentElement->getAnimal());
				currentElement->setAnimal(NULL);
			}
		}
		//End game if Indy encounters his Human
		else if (nextElement->getAnimal() != NULL && nextElement->getAnimal()->getAnimalType() == HUMAN) {
			cout << "Indy's human scooped him up and carried him out of the park." << endl;
			newRow = row;
			newCol = col;
			endGame = true;
		}
		//End game Indy gets to the Hole before being caught
		else if (nextElement->getSpaceType() == HOLE && hasMap) {
			cout << "Indy digs a hole in the spot marked on the map. The hole leads to a tunnel!" << endl
				<< "Indy crawls through the tunnel and comes out the otherside of the park. His ball, along with"
				<< " all the other balls that were thrown over the fence are here!" << endl
				<< "Indy gathers what he can and heads back through the hole to his human." << endl;
			newRow = row;
			newCol = col;
			endGame = true;
		}
		//Move Indy to appropriate element
		else {
			nextElement->setAnimal(currentElement->getAnimal());
			currentElement->setAnimal(NULL);
		}
		//Set new Indy coordinates and move Animals
		row = newRow;
		col = newCol;
		board[curBoard]->moveAnimals();
		if (hasMap && !endGame) {
			if (board[curBoard]->moveHuman(row, col))
				endGame = true;
		}
	}
}

void Game::play() {
	board[curBoard]->print();
	while (!hasMap && !endGame) {
		move();
		board[curBoard]->print();
	}
	while (hasMap && !endGame) {
		time_t start = time(NULL);
		move();
		board[curBoard]->print();
		if (!endGame) {
			//User has 1.5 seconds to make a move, or the Human moves twice
			if ((time(NULL) - start) >= 1.5) {
				board[curBoard]->resetMoveTrack();
				cout << endl << "Indy's human is catching up! Move faster!" << endl;
				if (board[curBoard]->moveHuman(row, col))
					endGame = true;
				board[curBoard]->print();
			}
		}
	}
	
	cout << "The end." << endl;
	board[curBoard]->getElement(row, col)->getAnimal()->deleteVector();
	delete board[curBoard]->getElement(row, col)->getAnimal();
	board[0]->destroyBoard();
}

bool Game::fight(Animal* p1, Animal* p2) {
	int round = 0;
	int attack;
	int order = rand() % 2;
	if (order == 0) {
		cout << p1->getAnimalName() << " gets the initiative and attacks first!" << endl << endl;
		while (!p1->getIsDead() && !p2->getIsDead()) {
                        enterToContinue();
			getCreatureState(p1, p2);
			attack = p1->attackRoll();
			cout << p1->getAnimalName() << " attacks for " << attack << " damage!" << endl;
			p2->defenseResult(attack, p1->getAttackEffect());
			if (!p2->getIsDead()) {
                                enterToContinue();
				getCreatureState(p1, p2);
				attack = p2->attackRoll();
				cout << p2->getAnimalName() << " attacks for " << attack << " damage!" << endl;
				p1->defenseResult(attack, p2->getAttackEffect());
			}
		}
	}
	else if (order == 1) {
		cout << p2->getAnimalName() << " gets the initiative and attacks first!" << endl << endl;
		while (!p2->getIsDead() && !p1->getIsDead()) {
                        enterToContinue();
			getCreatureState(p1, p2);
			attack = p2->attackRoll();
			cout << p2->getAnimalName() << " attacks for " << attack << " damage!" << endl;
			p1->defenseResult(attack, p2->getAttackEffect());
			if (!p1->getIsDead()) {
                                enterToContinue();
				getCreatureState(p1, p2);
				attack = p1->attackRoll();
				cout << p1->getAnimalName() << " attacks for " << attack << " damage!" << endl;
				p2->defenseResult(attack, p1->getAttackEffect());
			}
		}
	}
	if (p1->getIsDead()) {
		cout << "Indy could not overcome the obstacles in his way to get his ball. He slumps back to his owner and admits defeat." << endl;
		endGame = true;
		return false;
	}
	else {
		if (p1->hasItem("Spiked Collar")) {
			cout << "Looks like the Dog dropped something. Indy picks up a Map!" << endl
				<< "Indy looks at the map and sees that it's a map of the park he's in! "
				<< "There's an X on the map with a note that says 'Dig here'. Indy should check it out!" << endl
                                << endl << "Looks like Indy's human is getting ready to leave. Get to the spot before he catches you!" << endl;
			Item item2("Map");
			hasMap = true;
			board[0]->getElement(1, 10)->setHasMap(true);
			p1->addItem(item2);
			board[0]->addHuman(row, col);
			return true;
		}
		else {
			cout << "The Dog dropped a Spiked Collar! Indy puts in on and feels immediately more badass." << endl;
			cout << "The Spiked Collar adds one armor" << endl;
			Item item1("Spiked Collar");
			p1->addItem(item1);
			return true;
		}
	}
}

void Game::getCreatureState(Animal* p1, Animal* p2) {
	cout << "These are the champion's current stats:" << endl;
	cout << p1->getAnimalName() << "| Attack: " << p1->getAttack().getNumberOfDie() << "d"
		<< p1->getAttack().getSizeOfDie() << "   Defense: " << p1->getDefense().getNumberOfDie()
		<< "d" << p1->getDefense().getSizeOfDie() << "   Armor: " << p1->getArmor()
		<< "   Health: " << p1->getHealth() << "/" << p1->getMaxHealth() << endl;
	cout << p2->getAnimalName() << "| Attack: " << p2->getAttack().getNumberOfDie() << "d"
		<< p2->getAttack().getSizeOfDie() << "   Defense: " << p2->getDefense().getNumberOfDie()
		<< "d" << p2->getDefense().getSizeOfDie() << "   Armor: " << p2->getArmor()
		<< "   Health: " << p2->getHealth() << "/" << p2->getMaxHealth() << endl << endl;
}

