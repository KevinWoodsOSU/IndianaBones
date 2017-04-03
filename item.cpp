/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "item.h"

Item::Item() {

}

Item::Item(string i) {
	setName(i);
}

void Item::setName(string iname) {
	name = iname;
}

string Item::getName() {
	return name;
}