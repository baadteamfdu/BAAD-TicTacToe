#pragma once
using namespace std;

class Board {
    public:
        void reset();
        void checkWin(); //could mention if draw occurs based on turn number
        void getBoxIcon(int row, int col);
        void setBoxIcon(int row, int col, char icon);
        void printBoard();
    private:
        int turns;
        char boardArray[3][3] = { ' ', ' ', ' ',
                                  ' ', ' ', ' ',
                                  ' ', ' ', ' ' };

};


