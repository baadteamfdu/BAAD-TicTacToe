#pragma once
using namespace std;

class Board {
private:
    int turns;
    char boardArray[3][3];
 public:
     Board();
        void reset();
        void printBoard();
        bool checkDraw();
        bool checkWin(char player);
        char getBoxIcon(int row, int col);
        void setBoxIcon(int row, int col, char icon);
        
 

};


