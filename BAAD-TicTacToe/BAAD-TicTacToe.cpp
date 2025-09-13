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


	/*
	main
keeps track of whose turn (just loop through)
keeps track of if win or if draw
Instructions listed will say x always goes first, etc
	
	Use case
	Prompt player to enter move
	<figure out player's turn>
		int array playermove = playerx->get move()
		board->setBoxIcon(playermove[0], playermove[1], playerx.geticon()
			board->printBoard()
			board->checkWin()
			if win(ask for reset)
				board->checkDraw()
				if draw(ask for reset)


					playermove[1], playerX.geticon())
		playermove = playero->get move()
		board->setBoxIcon(playermove[0], playermove[1], playero.geticon)
		board->printBoard()
		board->checkWin()
		if win(ask for reset)
			board->checkDraw()
			if draw(ask for reset) 
			
			
			player
			X and O
 int array getMove()
int geticon()
player constructor stores icon



Board
reset function
3*3 grid
bool checkWin()
bool checkDraw()
(turns counter to check for draw)

We are gonna have to make cells that is gonna hold the value
 Could be either X OR O OR  ' '

			*/



}
