/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "menu.h"

int getInt(string prompt) {
	float input;
	int num;
	bool isInt = false;

	do {
		cout << prompt;
		cin >> input;
		num = input;
		if (cin.good() && num > 0 && num == input) {
			isInt = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isInt);

	cin.ignore();
	return num;
}

int getIntLimited(string prompt, int min, int max) {
	int num;
	bool isInt = false;

	do {
		cout << prompt << " (Pick between " << min << " and " << max << "): ";
		cin >> num;
		if (cin.good() && num >= min && num <= max) {
			isInt = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isInt);

	return num;
}

//This function is for testing on Windows OS and will not be used on FLIP
void clearScreenWindows() {
	system("CLS");
}

void clearScreenUnix() {
	cout << "\033[2J\033[1;1H" << endl;
}

void enterToContinue() {
	cout << endl << "Press Enter to Continue." << flush;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	cout << endl;
}

bool yesOrNo(string prompt) {
	string ans;
	bool isStr = false;

	do {
		cout << prompt;
		getline(cin, ans);
		if (ans == "y" || ans == "Y" || ans == "n" || ans == "N")
			isStr = true;
	} while (!isStr);

	if (ans == "y" || ans == "Y")
		return true;
	else if (ans == "n" || ans == "N")
		return false;
}

string getString(string prompt) {
	string ans;
	cout << prompt;

	bool cont = true;
	while (cont) {
		getline(cin, ans);
		if (ans == "")
			cout << "Incorrect input. Try again." << endl;
		else
			cont = false;
	}
	string fixedAns = removeWhitespace(ans, " \t");
	return fixedAns;
}

double getDouble(string prompt) {
	double num;
	bool isDouble = false;

	do {
		cout << prompt;
		cin >> num;
		if (cin.good() && num > 0) {
			isDouble = true;
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was not valid." << endl;
		}
	} while (!isDouble);

	return num;
}

string removeWhitespace(string str, string space)
{
	int begin = str.find_first_not_of(space);
	int end = str.find_last_not_of(space);
	int length = end - begin + 1;

	return str.substr(begin, length);
}

char getChar() {

char ch;
ch = mygetch( );
return ch;

}

//Found solution on: https://forums.macrumors.com/threads/how-to-get-getch-function-to-work.418230/
int mygetch( ) {
struct termios oldt,
newt;
int ch;
tcgetattr(STDIN_FILENO, &oldt );
newt = oldt;
newt.c_lflag &= ~( ICANON | ECHO );
tcsetattr( STDIN_FILENO, TCSANOW, &newt );
ch = getchar();
tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
return ch;
}
    
    
    /*
	char myChar = { 0 };
	string input;

	while (true) {
		getline(cin, input);
		//input = _getch();
		if (input.length() == 1) {
			myChar = input[0];
			break;
		}
		cout << "Invalid input. Try again." << endl;
	}
	return myChar;
     * */
	
	


