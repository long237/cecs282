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
			//if (board[row][col] == 1) {
			//	boardValue++;
			//}
			//else if(board[row][col] == -1) {
			//	boardValue--;
			//}
			boardValue += board[row][col];
		}
	}
	return boardValue;
}

void ApplyMove(OthelloMatrix& board, int row, int col,
	char currentPlayer) {
	board[row][col] = currentPlayer;
	for (int rowDir = -1; rowDir < 2; rowDir++) {
		for (int colDir = -1; colDir < 2; colDir++) {
			
			int counter = 0;
			//int rowWDir = rowDir + row, colWDir = col + colDir;
			int tempRow = row, tempCol = col;

			while (InBounds(tempRow + rowDir, tempCol + colDir) && board[tempRow + rowDir][tempCol + colDir] != 0) {

				tempRow += rowDir;
				tempCol += colDir;

				if (board[tempRow][tempCol] != currentPlayer) {
					counter++;
				}

				else {
					break;
				}

				//if (InBounds(row + rowDir, col + colDir) || board[row + rowDir][col + colDir] == 0) {
				//	break;
				//}
				//if (board[rowWDir][colWDir] == 0) {
				//	break;
				//}

				//if (counter == 0) {
				//	break;
				//}

				//else {
				//	for (int j = 0; j < counter; j++) {
				//		board[rowWDir - rowDir][colWDir - colDir] = currentPlayer; 
				//	}
				//}
			}
			cout << "counter: " << counter << endl;
			if (board[tempRow][tempCol] == currentPlayer) {
				for (int j = 0; j < counter; j++) {
					tempRow -= rowDir;
					tempCol -= colDir;
					board[tempRow][tempCol] = currentPlayer;
				}
			}
		}
	} 
}

