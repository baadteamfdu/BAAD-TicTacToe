#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

void Player::setIcon(char i) {
	icon = i;
}

char Player::getPlayerIcon()
{
	return icon;
}

int* Player::getMove() {
	int* move = new int[2];
	string input = "";
	int moveValid;
	do {
		moveValid = 0;
		cout << "What will your row be (1 to 3)? " << endl;
		cin >> input;
		try {
			moveValid = stoi(input);
			if (moveValid < 1 || moveValid > 3) {
				cout << "ERROR ::: ROW DOES NOT EXIST. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
			}
			else {
				move[0] = moveValid;
			}
		}
		catch (exception& e) {
			cout << "ERROR ::: INVALID INPUT. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
		}
	} while (moveValid < 1 || moveValid > 3);

	do {
		moveValid = 0;
		cout << "What will your column be (1 to 3)? " << endl;
		cin >> input;
		try {
			moveValid = stoi(input);
			if (moveValid < 1 || moveValid > 3) {
				cout << "ERROR ::: COLUMN DOES NOT EXIST. PLEASE CHOOSE COLUMN FROM 1 TO 3" << endl;
			}
			else {
				move[1] = moveValid;
			}
		}
		catch (exception& e) {
			cout << "ERROR ::: INVALID INPUT. PLEASE CHOOSE COLUMN FROM 1 TO 3" << endl;
		}
	}
		while (moveValid < 1 || moveValid > 3);

		return move;
	}