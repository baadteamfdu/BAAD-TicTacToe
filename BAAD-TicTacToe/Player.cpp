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
	int* Move = new int[2];
	do {
		cout << "what will your row be from 1 to 3" << endl;
		cin >> Move[0];
		if (Move[0] < 1 || Move[0] > 3) {
			cout << "ERROR ::: ROW DOES NOT EXIST. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
		}
	} while (Move[0] < 1 || Move[0] > 3);
	do {
		cout << "what will your column be from 1 to 3" << endl;
		cin >> Move[1];
		if (Move[1] < 1 || Move[1] > 3) {
			cout << "ERROR ::: ROW DOES NOT EXIST. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
		}
	} while (Move[1] < 1 || Move[1] > 3);

	return Move;
}