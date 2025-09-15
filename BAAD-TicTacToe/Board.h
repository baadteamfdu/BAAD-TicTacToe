#pragma once
using namespace std;

class Board {
    public:
        void reset();
        bool checkWin();
        bool checkDraw();
        char getBoxIcon(int row, int col);
        void setBoxIcon(int row, int col, char icon);
        void printBoard();
    private:
        int turns;
        char boardArray[3][3] = { ' ', ' ', ' ',
                                  ' ', ' ', ' ',
                                  ' ', ' ', ' ' };

};


