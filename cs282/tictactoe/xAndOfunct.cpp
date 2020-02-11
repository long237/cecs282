#include <array>
#include "tictactoe.h"
#include <iostream>
using namespace std;

void PrintBoard(const std::array<std::array<char, 3>, 3> &board){
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '1') {
				cout<< "X";
			}
			else if (board[i][j] == '-1'){
				cout<< "O";
			} 
			else {
				cout<< ".";
			}
		}
		cout<< ""<<endl;
	}
}

//take in references and modified them.
void GetMove(int &row, int &col){
	cout<< "Enter the row and column to place a symbol: "<< endl;
	cin>> row;
	cin>> col;
	
}

bool  MoveIsValid(const std::array<std::array<char, 3>, 3> &board,
		int row, int col);

char CheckWinner(const std::array<std::array<char, 3>, 3> &board);


