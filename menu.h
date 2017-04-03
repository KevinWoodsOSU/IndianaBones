/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

using namespace std;

#include <iostream>
#include <string>
#include <limits>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <vector>
#include <deque>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
//#include <conio.h>

#ifndef MENU_H
#define MENU_H

int getInt(string); //Input verification for an integer
int getIntLimited(string, int, int); //Input verification for an integer between min and max
void clearScreenWindows(); //Clear console for Windows OS testing only
void clearScreenUnix(); //Clear console in Unix
void enterToContinue(); //Pause the program until a key is entered
bool yesOrNo(string); //Input verfication for choose one
string getString(string); //Input verification for a string
double getDouble(string); //Input verification for a double
string removeWhitespace(string, string); //Remove leading and trailing whitespace from string
char getChar(); //Input verification for a char
int mygetch();

#endif

