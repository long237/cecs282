#include <iostream>
#include "OthelloGame.h"
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
	OthelloMatrix board = OthelloMatrix { 0 };
	
	//int row = -2, col = -3;
	//PrintBoard(board);
	//board[3][3] = 1;
	//PrintBoard(board);
	//cout << "valid? " << IsValidMove(board, 1, 2)<< endl;
	//while (!(IsValidMove(board, row, col))) {
	//	cout << "Enter where you want to move (x,y): " << endl;
	//	GetMove(row, col);
	//}
	

	int prevRow = -4, prevCol = -5;
	char turn = 1;
	
	/*while (!(prevRow == -1 && prevCol == -1) && (row == -1 && col == -1)) {*/
	PrintBoard(board);
	while (true) {

		int row = -2, col = -3;

		while (!(IsValidMove(board, row, col))) {
			cout << "Enter where you want to move (x,y): " << endl;
			GetMove(row, col);
		}

		if ((row == -1 && col == -1) && (prevRow = -1 && prevCol == -1)) {
			cout << "We have a tie!" << endl;
				break;
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