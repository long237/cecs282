#include <iostream>
#include "OthelloGame.h"
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
	OthelloMatrix board = OthelloMatrix { 0 };
	//Initialize board with 4 already placed pieces
	board[3][3] = -1;
	board[4][4] = -1;
	board[3][4] = 1;
	board[4][3] = 1;

	//variables to keep track of the previous player move
	//to stop when both player put (-1,-1)

	int prevRow = -4, prevCol = -5;
	char turn = 1;
	
	PrintBoard(board);
	//Keep running as long as it is true
	while (true) {
		int row = -2, col = -3;

		while (!(IsValidMove(board, row, col))) {
			if (turn == -1) {
				cout << "White's turn. Enter where you want to move (x,y): " << endl;
			}
			else {
				cout << "Black's turn. Enter where you want to move (x,y): " << endl;
			}
			GetMove(row, col);
		}

		//Call getValue() to check for winner when both player cannot move
		if ((row == -1 && col == -1) && (prevRow = -1 && prevCol == -1)) {
			int winner = GetValue(board);

			if (winner > 0) {
				cout << "Black wins!!!" << endl;
			}
			else if (winner < 0) {
				cout << "White wins!!!" << endl;
			}
			else {
				cout << "We have a tie!" << endl;
			}
				break;
		}

		prevRow = row, prevCol = col;

		//check the input to be positive and inbound before passing it to Applymove()
		if (InBounds(row,col)) {
			ApplyMove(board, row, col, turn);
		}
		PrintBoard(board);
		if (turn == 1) {
			turn -= 2;
		}
		else {
			turn += 2;
		}
	}

}