#include "Board.h"
#include <iostream>
using namespace std;

void Board::reset()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            boardArray[i][j] = ' ';
        }
    }
	turns = 0;
}

void Board::printBoard()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << boardArray[i][j];
            cout << "|";
        }
        cout << endl;
        cout << "-- -- --";
        cout << endl;
    }
}