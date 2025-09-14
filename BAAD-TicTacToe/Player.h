#pragma once
using namespace std;

class Player {
public:
    int* getMove();
    char getPlayerIcon();
    void setIcon(char i);
private:
    char icon;
};