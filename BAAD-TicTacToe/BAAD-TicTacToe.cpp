#include <iostream>
#include <cctype>
#include "Board.h"
#include "Player.h"
using namespace std;

bool askRestart() 
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
            Player& cur = (turnIdx == 0) ? player1 : player2;

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

            if (board.checkWin()) 
			{
                cout << "Player " << (turnIdx + 1) << " (" << cur.getPlayerIcon() << ") WINS!\n";
                starter = (turnIdx == 0) ? 1 : 0;
                keepPlaying = askRestart();
                break;
            }

            if (board.checkDraw()) 
			{
                cout << "It's a DRAW!\n";
                starter = 1 - starter;
                keepPlaying = askRestart();
                break;
            }

            turnIdx = 1 - turnIdx;
        }
    }

    cout << "Thanks for playing!\n";
    return 0;
}
