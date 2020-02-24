#include <array>
#include <iostream>
#include "OthelloGame.h"
using namespace std;

//print B if space is -1 and W if space is 1, . if empty
void PrintBoard(const OthelloMatrix& board) {
	cout << "- 0 1 2 3 4 5 6 7" << endl;
	for (int row = 0; row < board.size(); row++) {
		cout << row << " ";
		for (int col = 0; col < board.size(); col++) {

			if (board[row][col] == 1) {
				cout << "B ";
			}

			else if (board[row][col] == -1) {
				cout << "W ";
			}

			else {
				cout << ". ";
			}
		}
		cout << "" << endl;
	}
}

void GetMove(int& row, int& col) {
	char dummy1, dummy2, dummy3; 
	cin >> dummy1 >> row >> dummy2 >> col >> dummy3;
}


//return false if not inbound otherwise always return true
bool InBounds(int row, int col) {
	if (row < 0 || row >= 8 || col < 0 || col >= 8) {
		return false;
	}
}

bool IsValidMove(const OthelloMatrix& board, int row, int col) {
	if (InBounds(row, col) || (row == -1 && col == -1)) {
		return true;
	}
	return false;
}

int GetValue(const OthelloMatrix& board) {
	int boardValue = 0;
	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board.size(); col++) {
			if (board[row][col] == 1) {
				boardValue++;
			}
			else if(board[row][col] == -1) {
				boardValue--;
			}
		}
	}
	return boardValue;
}

