#include <array>
#include "tictactoe.h"
#include <iostream>
using namespace std;

void PrintBoard(const std::array<std::array<char, 3>, 3> &board){
	cout << "- 0 1 2 "<< endl;
	for (int i = 0; i < 3; i++) {
		cout<< i << " ";
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 1) {
				cout<< "X ";
			}
			else if (board[i][j] == -1){
				cout<< "O ";
			} 
			else {
				cout<< ". ";
				//cout << board[i][j];
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

bool  MoveIsValid(const std::array<std::array<char, 3>, 3> &board,
		int row, int col) {
	if ((row >= 0 && row < 3) && (col >= 0 && col < 3) && (board[row][col] == 0)) {
			return true;
	}
	else {
		//cout<< "def false" << endl;
		return false;
	}
}


char CheckWinner(const std::array<std::array<char, 3>, 3> &board);


