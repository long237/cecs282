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
	//array out of bound for negative numbers
	//if ((InBounds(row, col) || row == -1 && col == -1) && board[row][col] == 0) 
	if ((InBounds(row, col) && board[row][col] == 0) || row == -1 && col == -1) {
		return true;
	}
	return false;
}

int GetValue(const OthelloMatrix& board) {
	int boardValue = 0;
	for (int row = 0; row < board.size(); row++) {
		for (int col = 0; col < board.size(); col++) {
			boardValue += board[row][col];
		}
	}
	return boardValue;
}

void ApplyMove(OthelloMatrix& board, int row, int col,
	char currentPlayer) {
	//Set the chosen position to the player turn.
	board[row][col] = currentPlayer;
	//Generate direction to check for matching when add to orgin coordinate
	for (int rowDir = -1; rowDir < 2; rowDir++) {
		for (int colDir = -1; colDir < 2; colDir++) {
			
			//temporary row and column to move around to check. 
			int counter = 0;
			int tempRow = row, tempCol = col;

			//Keep moving in that direction as long as it is inbound and the space is not empty
			while (InBounds(tempRow + rowDir, tempCol + colDir) && board[tempRow + rowDir][tempCol + colDir] != 0) {

				tempRow += rowDir;
				tempCol += colDir;

				//increase the counter if find enemy pieces
				if (board[tempRow][tempCol] != currentPlayer) {
					counter++;
				}

				else {
					break;
				}
			}

			//Only go back and flip if encounter our own piece at the other end.
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

