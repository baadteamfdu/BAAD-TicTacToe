#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

int main()
{
	cout << "Instructions: " << endl;
	cout << "The player going first uses 'x', and the second uses 'o'" << endl;
	cout << "When it is your turn, enter which ROW and COLUMN you would like to select(numbers 1-3)" << endl;
	cout << "You CANNOT play on a spot that is already taken, otherwise you will be asked again!" << endl;
	cout << "First to 3 in a row wins! If the board has no winner, it is a draw!" << endl;
	cout << "Loser goes first if you play again! Good luck!" << endl;

	Board board;
	board.printBoard();
    Player player1;
    Player player2;
    player1.setIcon('x');
    player2.setIcon('o');

	cout << "Player 1 " << player1.getPlayerIcon() << "'s turn:" << endl;
	int* move1 = player1.getMove();
	while (board.getBoxIcon(move1[0], move1[1]) != ' ')
	{
		cout << "ERROR ::: BOARD SPOT TAKEN. Try again.";
		delete[] move1;
		move1 = player1.getMove();
	}
	board.setBoxIcon(move1[0], move1[1], player1.getPlayerIcon());
	delete[] move1;

	board.printBoard();

	cout << "Player 2 " << player1.getPlayerIcon() << "'s turn:" << endl;
	int* move2 = player2.getMove();
	while (board.getBoxIcon(move2[0], move2[1]) != ' ')
	{
		cout << "ERROR ::: BOARD SPOT TAKEN. Try again.";
		delete[] move2;
		move2 = player2.getMove();
	}
	board.setBoxIcon(move2[0], move2[1], player2.getPlayerIcon());
	delete[] move2;

	board.printBoard();
}

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
