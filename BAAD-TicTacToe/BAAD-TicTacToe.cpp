#include <iostream>
#include <cctype>
#include "Board.h"
#include "Player.h"
#include <string>
using namespace std;

bool askRestart() //asks the player if they wish to restart using a string which gets has the first character input cast to a character and converted to lowercase.
{
    while (true) 
	{
        cout << "Play again? (r = restart, q = quit): ";
        string s;
        if (!getline(cin, s)) return false; // EOF -> quit
        if (!s.empty()) 
		{
            char ch = static_cast<char>(tolower(static_cast<unsigned char>(s[0])));
            if (ch == 'r') return true;
            if (ch == 'q') return false;
        }
        cout << "Please enter 'r' or 'q'.\n";
    }
}

int main()
{
    cout << "Instructions: " << endl;
    cout << " - The player going first uses 'x', and the second uses 'o'" << endl;
    cout << " - On your turn, enter ROW and COLUMN (numbers 1-3)" << endl;
    cout << " - You CANNOT play on a taken spot; you'll be asked again" << endl;
    cout << " - First to 3 in a row wins! If no winner and the board is full, it's a draw" << endl;
    cout << " - Loser goes first if you play again. Good luck!" << endl;

    Board board;
    Player player1; player1.setIcon('x');
    Player player2; player2.setIcon('o');

    // starter: 0 -> player1 (x), 1 -> player2 (o)
    int starter = 0;

    bool keepPlaying = true;
    while (keepPlaying)
    {
        board.reset();
        board.printBoard();

        // Current player index for this round (0 or 1)
        int turnIdx = starter;

        while (true)
        {
            Player& cur = (turnIdx == 0) ? player1 : player2; //decides which player will be used for the turn based on the index

            cout << "Player " << (turnIdx + 1) << " (" << cur.getPlayerIcon() << ")'s turn:\n";

            int* mv = cur.getMove(); // expects 0-based [row, col] from your Player.h
            while (board.getBoxIcon(mv[0], mv[1]) != ' ')
            {
                cout << "ERROR ::: BOARD SPOT TAKEN. Try again.\n";
                delete[] mv;
                mv = cur.getMove();
            }

            board.setBoxIcon(mv[0], mv[1], cur.getPlayerIcon());
            delete[] mv;

            board.printBoard();

            if (board.checkWin(cur.getPlayerIcon())) //checks that the current player won
            {
                cout << "Player " << (turnIdx + 1) << " (" << cur.getPlayerIcon() << ") WINS!\n";
                starter = (turnIdx == 0) ? 1 : 0;
                keepPlaying = askRestart(); //will keep looping reseting and printing if this returns true
                break;
            }

            if (board.checkDraw())
            {
                cout << "It's a DRAW!\n";
                starter = 1 - starter;
                keepPlaying = askRestart();
                break;
            }

            turnIdx = 1 - turnIdx; //allows the loser last round to go first 1-1 or 1-0 so player 1 or 2 will be selected from the ternary operator above
        }
    }

    cout << "Thanks for playing!\n";
    return 0;

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
