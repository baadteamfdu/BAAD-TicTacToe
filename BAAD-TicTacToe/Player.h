#pragma once
using namespace std;

class Player {
public:
    void getMove(int& row, int& column);
    char getPlayerIcon();
    void setIcon(char i);
private:
    char icon;
};