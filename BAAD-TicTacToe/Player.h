#pragma once
using namespace std;

class Player {
public:
    void getMove(int row, int col);
    void getPlayerIcon();
private:
    char icon;
};