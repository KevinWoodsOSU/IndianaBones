/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#ifndef ANIMAL_H
#define ANIMAL_H

#include "item.h"
#include "menu.h"
#include "die.h"

enum AnimalType {INDY, DOG, HUMAN}; //Tracks Animal type
enum attackEffect { NORMAL, BLEED }; //Attack effects for fighting

class Animal {
private:
	
	AnimalType thisType; //Store animal type
	string champion; //Stores name of champion
	int health; //Stores current health
	int maxHealth; //Stores the maximum health
	int armor; //Stores armor value
	Die defense; //Defense die (i.e. 2d6)
	Die attack; //Attack die (i.e. 2d6)
	attackEffect effect; //Attack special modifier (medusa's glare)
	bool isDead; //Tracks if character died
	string animalName;
	bool movedThisTurn;

public:
	Animal();

	//Virtual function declarations
	virtual void setMovedThisTurn(bool) = 0;
	virtual bool getMovedThisTurn() = 0;
	virtual void addItem(Item) = 0;
	virtual void searchItems() = 0;
	virtual bool hasItem(string) = 0;
	virtual void deleteVector() = 0;

	//Get and set methods
	void setAnimalType(AnimalType);
	AnimalType getAnimalType();
	void setAnimalName(string);
	string getAnimalName();
	void setHealth(int);
	int getHealth();
	void setMaxHealth(int);
	int getMaxHealth();
	void setArmor(int);
	int getArmor();
	void setDefense(Die);
	Die getDefense();
	void setAttack(Die);
	Die getAttack();
	void setAttackEffect(attackEffect);
	attackEffect getAttackEffect();
	void setIsDead(bool);
	bool getIsDead();



	int virtual attackRoll() = 0; //Returns the damage dealt by attacker. Special attacks are handled within the derived class

	//Calls defenseCalculations and handles special defense abilities within the derived class.
	void virtual defenseResult(int, attackEffect) = 0;

	//Base defense calculations. Takes attack damage, attack effect and defending player name as parameters.
	void defenseCalculations(int, attackEffect);

	

};

#endif
