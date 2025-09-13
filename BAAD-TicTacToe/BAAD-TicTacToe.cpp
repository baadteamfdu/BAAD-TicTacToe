#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

int main()
{
	cout << "Instructions: ";
	//we could just alternate from x then o and just say in a cout set of instructions that the player going first is x and then it is o.
	// Then instead of a player we could just make an input handler that checks for 1-9?
	//for reseting we could just say who's turn it is and say that the loser goes first then in the documentation/instructions
	Board board;
	board.printBoard();

}
