#include <iostream>
#include "OthelloGame.h"
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
	/*OthelloMatrix board = OthelloMatrix {0};*/
	
	//PrintBoard(board);


	/*int row, col;*/

	//cout << "enter: " << endl;

	//GetMove(row, col);
	//cout << "row: " << row << "col: " << col << endl;
	//cout << "check value: " << IsValidMove(board, row, col);

	//board[0][1] = 1;
	//board[1][1] = -1;
	//board[1][2] = -1;
	//board[1][3] = 1;
	//board[1][4] = -1;
	//board[1][5] = 1;
	//board[2][0] = -1;
	//board[2][1] = -1;
	//board[3][2] = 1;
	//board[3][0] = -1;
	//PrintBoard(board);

	//ApplyMove(board, 1, 0, 1);
	//cout << "after move " << endl;
	//cout << " " << endl;
	//PrintBoard(board);

	//cout << "white turn: " << endl;
	//ApplyMove(board, 0, 3, -1);
	//PrintBoard(board);

	OthelloMatrix board = OthelloMatrix { 0 };

	int row = -2, col = -3, prevRow = -4, prevCol = -5;
	char turn = 1;
	
	while (!(prevRow == -1 && prevCol == -1) && (row == -1 && col == -1)) {
		PrintBoard(board);
		while (!(IsValidMove(board, row, col))) {
			cout << "Enter where you want to move (x,y): " << endl;
			GetMove(row, col);
		}

		prevRow = row, prevCol = col;
		ApplyMove(board, row, col, turn);
		PrintBoard(board);
		if (turn == 1) {
			turn -= 2;
		}
		else {
			turn += 2;
		}
	}

}