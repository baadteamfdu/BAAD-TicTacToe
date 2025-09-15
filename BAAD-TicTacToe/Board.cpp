#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
    reset();
}

void Board::reset() {
    for (int i = 0; i < 3; i++) {
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

bool Board::checkDraw() {
    if (turns >= 9) {
        return true;        
    }
    else 
    {
        return false;
    }
}


bool Board::checkWin(char player) {
    
    for (int i = 0; i < 3; i++) {
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
    return boardArray[row - 1][col - 1];
}

bool Board::setBoxIcon(int row, int col, char icon) {
    if (row >= 1 && row <= 3 && col >= 1 && col <= 3) {
        if (boardArray[row - 1][col - 1] == ' ') {
            boardArray[row - 1][col - 1] = icon;
            turns++;
            return true;
        }
    }
    return false; 
}
