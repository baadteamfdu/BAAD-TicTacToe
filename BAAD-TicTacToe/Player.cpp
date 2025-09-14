#include "Player.h"
#include <iostream>
using namespace std;

void Player::setIcon(char i) {
	icon = i;
}

char Player::getPlayerIcon()
{
	return icon;
}

int* Player::getMove()
{
	int* move = new int[2];
	do {
		cout << "What will your row be (1 to 3)? " << endl;
		cin >> move[0];
		if (move[0] < 1 || move[0] > 3) {
			cout << "ERROR ::: ROW DOES NOT EXIST. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
		}
	} while (move[0] < 1 || move[0] > 3);
	do {
		cout << "What will your column be (1 to 3)? " << endl;
		cin >> move[1];
		if (move[1] < 1 || move[1] > 3) {
			cout << "ERROR ::: ROW DOES NOT EXIST. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
		}
	} while (move[1] < 1 || move[1] > 3);

	return move;
}