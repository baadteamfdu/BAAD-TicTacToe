#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    reset();
}

void Board::reset() {
    for (int i = 0; i < 3; i++) { ;//sets every row and column to blank and sets the turn counter back to zero
        for (int j = 0; j < 3; j++) {
            boardArray[i][j] = ' ';
        }
    }
    turns = 0;
}

void Board::printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << boardArray[i][j];
            if (j < 2) cout << " |";
        }
        cout << endl;
        if (i < 2) cout << "---+---+---";
        cout << endl;
    }
    cout << endl;
}

bool Board::checkDraw() { //the board must be full after 9 turns so it will return true then
    if (turns >= 9) {
        return true;        
    }
    else 
    {
        return false;
    }
}


bool Board::checkWin(char player) {
    
    for (int i = 0; i < 3; i++) { //checks all combinations of three across or down
        if (boardArray[i][0] == player &&
            boardArray[i][1] == player &&
            boardArray[i][2] == player) return true;

        if (boardArray[0][i] == player &&
            boardArray[1][i] == player &&
            boardArray[2][i] == player) return true;
    }

    // or diagonal
    if (boardArray[0][0] == player &&
        boardArray[1][1] == player &&
        boardArray[2][2] == player) return true;

    if (boardArray[0][2] == player &&
        boardArray[1][1] == player &&
        boardArray[2][0] == player) return true;

    return false;
}

char Board::getBoxIcon(int row, int col) {
    return boardArray[row - 1][col - 1]; //returns box icon because player input 1-3
}

void Board::setBoxIcon(int row, int col, char icon) {
            boardArray[row - 1][col - 1] = icon; //sets the box icon to whatever is passed and -1 is used because player inputs 1-3
            turns++; //increments turn counter
        }