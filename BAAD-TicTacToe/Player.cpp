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

//askig for the row and column, 
//changing the variables that were passed through refereneces therefore,
//we need to create variables row and column in the main so we can use them
void Player::getMove(int& row, int& column)
{
	do {
		cout << "what will your row be from 1 to 3" << endl;
		cin >> row;
		if (row < 1 || row > 3) {
			cout << "ERROR ::: ROW DOES NOT EXIST. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
		}
	} while (row < 1 && row > 3);
	do {
		cout << "what will your column be from 1 to 3" << endl;
		cin >> column;
		if (column < 1 && column > 3) {
			cout << "ERROR ::: ROW DOES NOT EXIST. PLEASE CHOOSE ROW FROM 1 TO 3" << endl;
		}
	} while (column < 1 && column > 3);
}