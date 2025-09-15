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

bool Board::checkDraw() {
    if (turns >= 9) {
        return true;        //might need changing based on the implementation of others to be 8 or 10
    }
    else {
        return false;
    }
}

char Board::getBoxIcon(int row, int col) {
    return boardArray[row - 1][col - 1];
}

void Board::setBoxIcon(int row, int col, char icon) {
    boardArray[row-1][col-1] = icon;
    turns++;
}