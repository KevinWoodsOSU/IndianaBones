/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "parkBoard.h"

ParkBoard::ParkBoard() {
	setSize(12);

	//Create board of size length and width
	parkBoard = new Space**[getSize()];

	for (int i = 0; i < getSize(); i++)
		parkBoard[i] = new Space*[getSize()];

	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {

			if (i == 0 || i == (getSize() - 1) || j == 0 || j == (getSize() - 1))
				parkBoard[i][j] = new Wall;
			else if (i == 1 && j == 10)
				parkBoard[i][j] = new Hole;
			else
				parkBoard[i][j] = new Grass;
		}
	}

	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			//Link each adjacent Space
			if (i == 0) {
				parkBoard[i][j]->setUp(NULL);
				if (j != 0 && j != (getSize() - 1)) {
					parkBoard[i][j]->setLeft(parkBoard[i][j - 1]);
					parkBoard[i][j]->setRight(parkBoard[i][j + 1]);
					parkBoard[i][j]->setDown(parkBoard[i + 1][j]);
				}
			}
			if (i == (getSize() - 1)) {
				parkBoard[i][j]->setDown(NULL);
				if (j != 0 && j != (getSize() - 1)) {
					parkBoard[i][j]->setLeft(parkBoard[i][j - 1]);
					parkBoard[i][j]->setRight(parkBoard[i][j + 1]);
					parkBoard[i][j]->setUp(parkBoard[i - 1][j]);
				}
			}
			if (j == 0) {
				parkBoard[i][j]->setLeft(NULL);
				if (i != 0 && i != (getSize() - 1)) {
					parkBoard[i][j]->setRight(parkBoard[i][j + 1]);
					parkBoard[i][j]->setUp(parkBoard[i - 1][j]);
					parkBoard[i][j]->setDown(parkBoard[i + 1][j]);
				}
			}
			if (j == (getSize() - 1)) {
				parkBoard[i][j]->setRight(NULL);
				if (i != 0 && i != (getSize() - 1)) {
					parkBoard[i][j]->setLeft(parkBoard[i][j - 1]);
					parkBoard[i][j]->setUp(parkBoard[i - 1][j]);
					parkBoard[i][j]->setDown(parkBoard[i + 1][j]);
				}
			}
			if ((i != 0) && (i != (getSize() - 1)) && (j != 0) && (j != (getSize() - 1))) {
				parkBoard[i][j]->setLeft(parkBoard[i][j - 1]);
				parkBoard[i][j]->setRight(parkBoard[i][j + 1]);
				parkBoard[i][j]->setDown(parkBoard[i + 1][j]);
				parkBoard[i][j]->setUp(parkBoard[i - 1][j]);
			}
		}
	}

	Animal* indy = new Indy;
	Animal* dog1 = new Dog("Gilly");
	Animal* dog2 = new Dog("Autumn");
	d1 = dog1;
	d2 = dog2;
	parkBoard[1][1]->setAnimal(indy);
	parkBoard[10][1]->setAnimal(dog1);
	parkBoard[10][10]->setAnimal(dog2);
}

ParkBoard::~ParkBoard() {
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			delete parkBoard[i][j];
		}
		delete[] parkBoard[i];
	}
	delete[] parkBoard;
	parkBoard = NULL;
}

void ParkBoard::destroyBoard() {
	for (int i = 0; i < getSize(); i++) {
		for (int j = 0; j < getSize(); j++) {
			delete parkBoard[i][j];
		}
		delete[] parkBoard[i];
	}
	delete[] parkBoard;
	parkBoard = NULL;

	delete d1;
	d1 = NULL;
	delete d2;
	d2 = NULL;
	delete h1;
	h1 = NULL;
}

void ParkBoard::print() {
	for (int i = 0; i < getSize(); i++) {
		cout << " ";
		for (int j = 0; j < getSize(); j++) {
			if (j == 0) {
				parkBoard[i][j]->display();
			}
			else {
				cout << " ";
				parkBoard[i][j]->display();
			}
		}
		cout << "\n";
	}
}

Space* ParkBoard::getElement(int x, int y) {
	return parkBoard[x][y];
}

void ParkBoard::moveAnimals() {
	for (int i = 0; i < getSize(); i++)
		for (int j = 0; j < getSize(); j++)
			if (parkBoard[i][j] != NULL) {
				if (parkBoard[i][j]->getAnimal() != NULL) {
					if (parkBoard[i][j]->getAnimal()->getAnimalType() == DOG) {
						if (parkBoard[i][j]->getAnimal()->getMovedThisTurn() == false) {

							int dirNum = (rand() % 4);
							parkBoard[i][j]->getAnimal()->setMovedThisTurn(true);
							switch (dirNum) {
								//Up
							case 0:
								if (parkBoard[i - 1][j]->getSpaceType() != WALL && parkBoard[i - 1][j]->getSpaceType() != HOLE && parkBoard[i - 1][j]->getAnimal() == NULL) {
									parkBoard[i - 1][j]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
								}
								break;
								//Down
							case 1:
								if (parkBoard[i + 1][j]->getSpaceType() != WALL && parkBoard[i + 1][j]->getSpaceType() != HOLE && parkBoard[i + 1][j]->getAnimal() == NULL) {
									parkBoard[i + 1][j]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
								}
								break;
								//Left
							case 2:
								if (parkBoard[i][j - 1]->getSpaceType() != WALL && parkBoard[i][j - 1]->getSpaceType() != HOLE && parkBoard[i][j - 1]->getAnimal() == NULL) {
									parkBoard[i][j - 1]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
								}
								break;
								//Right
							case 3:
								if (parkBoard[i][j + 1]->getSpaceType() != WALL && parkBoard[i][j + 1]->getSpaceType() != HOLE && parkBoard[i][j + 1]->getAnimal() == NULL) {
									parkBoard[i][j + 1]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
								}
								break;
							default:
								cout << "Move dogs switch error." << endl;
							}
						}
					}
				}
			}
}

bool ParkBoard::moveHuman(int row, int col) {
	for (int i = 0; i < getSize(); i++)
		for (int j = 0; j < getSize(); j++)
			if (parkBoard[i][j] != NULL) {
				if (parkBoard[i][j]->getAnimal() != NULL) {
					if (parkBoard[i][j]->getAnimal()->getAnimalType() == HUMAN) {
						if (parkBoard[i][j]->getAnimal()->getMovedThisTurn() == false) {
							parkBoard[i][j]->getAnimal()->setMovedThisTurn(true);
							if (i > row) {
								if (parkBoard[i - 1][j]->getAnimal() != NULL) {
									cout << endl << "Indy got caught! His ball is lost forever..." << endl;
									return true;
								}
								else {
									parkBoard[i - 1][j]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
									return false;
								}
							}
							else if (i < row) {
								if (parkBoard[i + 1][j]->getAnimal() != NULL) {
									cout << endl << "Indy got caught! His ball is lost forever..." << endl;
									return true;
								}
								else {
									parkBoard[i + 1][j]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
									return false;
								}
							}
							else if (j > col) {
								if (parkBoard[i][j - 1]->getAnimal() != NULL) {
									cout << endl << "Indy got caught! His ball is lost forever..." << endl;
									return true;
								}
								else {
									parkBoard[i][j - 1]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
									return false;
								}
							}
							else if (j < col) {
								if (parkBoard[i][j + 1]->getAnimal() != NULL) {
									cout << endl << "Indy got caught! His ball is lost forever..." << endl;
									return true;
								}
								else {
									parkBoard[i][j + 1]->setAnimal(parkBoard[i][j]->getAnimal());
									parkBoard[i][j]->setAnimal(NULL);
									return false;
								}
							}
						}
					}
				}
			}
}
				
void ParkBoard::resetMoveTrack() {
	for (int i = 0; i < getSize(); i++)
		for (int j = 0; j < getSize(); j++)
			if (parkBoard[i][j] != NULL) {
				if (parkBoard[i][j]->getAnimal() != NULL) {
					if (parkBoard[i][j]->getAnimal()->getAnimalType() == DOG) {
						parkBoard[i][j]->getAnimal()->setMovedThisTurn(false);
					}
					else if (parkBoard[i][j]->getAnimal()->getAnimalType() == HUMAN) {
						parkBoard[i][j]->getAnimal()->setMovedThisTurn(false);
					}
				}
			}
}

void ParkBoard::addHuman(int row, int col) {
	Animal* human = new Human;
	h1 = human;
	if (row == 1 && col == 10) {
		parkBoard[1][1]->setAnimal(human);
	}
	else {
		if (row > 8 && col < 3) {
			parkBoard[1][1]->setAnimal(human);
		}
		else {
			parkBoard[10][1]->setAnimal(human);
		}
	}
}







