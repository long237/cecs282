#include <array>
#include "tictactoe.h"
#include <iostream>
using namespace std;

void PrintBoard(const std::array<std::array<char, 3>, 3> &board){
	cout << "- 0 1 2 "<< endl;
	for (int i = 0; i < 3; i++) {
		cout<< i << " ";
		for (int j = 0; j < 3; j++) {
			//Print X if the element is a 1
			if (board[i][j] == 1) {
				cout<< "X ";
			}
			//else print O if the element is a -1
			else if (board[i][j] == -1){
				cout<< "O ";
			} 
			//Print a "." if the element is a zero.
			else {
				cout<< ". ";
			}
		}
		cout<< ""<<endl;
	}
}

//take in references and modified them.
void GetMove(int &row, int &col){
	char dummy_var;
	cout<< "Enter the row and column to place a symbol: "<< endl;
	cin>> row >> dummy_var >> col;
	
}

bool MoveIsValid(const std::array<std::array<char, 3>, 3> &board,
		int row, int col) {
	//If the move is inside the matrix and the element is equal to zero, return true.
	if ((row >= 0 && row < 3) && (col >= 0 && col < 3) && (board[row][col] == 0)) {
			return true;
	}
	else {
		return false;
	}
}

//return the value 1 or -1 if there are 3 matching.
char CheckWinner(const std::array<std::array<char, 3>, 3>& board) {
	//check if for the horizontal line matching.
	if ((board[0][0] == board[0][1]) && (board[0][0]== board[0][2])) {
		return board[0][0];
	}
	else if ((board[1][0] == board[1][1]) && (board[1][0] == board[1][2])) {
		return board[1][0];
	}
	else if ((board[2][0] == board[2][1]) && (board[2][0] == board[2][2])) {
		return board[2][0];
	}

	//check for vertical line matching
	else if ((board[0][0] == board[1][0]) && (board[0][0] == board[2][0])) {
		return board[0][0];
	}
	else if ((board[0][1] == board[1][1]) && (board[0][1] == board[2][1])) {
		return board[0][1];
	}
	else if ((board[0][2] == board[1][2]) && (board[0][2] == board[2][2])) {
		return board[0][2];
	}

	//check for diagonal line matching
	else if ((board[0][0] == board[1][1]) && (board[0][0] == board[2][2])) {
		return board[0][0];
	}
	else if ((board[0][2] == board[1][1]) && (board[0][2] == board[2][0])) {
		return board[0][2];
	}
	//return 0 if there are no matches. 
	else {
		return 0;
	}
}



