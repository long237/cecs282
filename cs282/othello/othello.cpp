#include <iostream>
#include "OthelloGame.h"
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
	OthelloMatrix board = OthelloMatrix { 0 };

	int prevRow = -4, prevCol = -5;
	char turn = 1;
	
	/*while (!(prevRow == -1 && prevCol == -1) && (row == -1 && col == -1)) {*/
	PrintBoard(board);
	//while (true) {
	for (int i = 0; i < (BOARD_SIZE * BOARD_SIZE); i++) {
		int row = -2, col = -3;

		while (!(IsValidMove(board, row, col))) {
			if (turn == -1) {
				cout << "White's turn. Enter where you want to move (x,y): " << endl;
			}
			else {
				cout << "Black's turn. Enter where you want to move (x,y): " << endl;
			}
			//if (!InBounds(row, col)) {
			//	cout << "Invalid move. Enter a different coordinate." << endl;
			//}
			GetMove(row, col);
		}

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

		if (row == -1 && col == -1) {
			cout << "User " << (int) turn << "pass" << endl;
		}
		prevRow = row, prevCol = col;

		if (InBounds(row,col)) {
			ApplyMove(board, row, col, turn);
			//PrintBoard(board);
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