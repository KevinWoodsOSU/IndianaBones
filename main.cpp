/**************************
Kevin Woods - woodske@oregonstate.edu
CS 162 - Fall 2016
Final Project - Indiana Bones
***************************/

#include "game.h"

int main() {
	srand(time(0));

	cout << endl << "INDIANA BONES AND THE RAIDERS OF THE LOST BALL" << endl << endl;

	cout << "This game is about a dog named Indiana Bones (Indy) who was taken to the dog park by his human." << endl
		<< "Indy's human threw his favorite ball over the fence and now Indy must find it or it'll be lost forever!" << endl
		<< "First defeat the other dogs in the park to find the map to the tunnel that leads under the fence." << endl
		<< "then avoid Indy's human while you go to the hole, or else Indy will be taken from the park without his ball." << endl << endl;

	cout << "Use the w, a, s, and d keys to move: (w = up, a = left, s = down, d = right)" << endl;

	bool ans;
        do {
		Game game;
		game.play();
		ans = yesOrNo("Would you like to play again? (y/n): ");
	} while (ans);

	return 0;
}