#include <iostream>
#include "OthelloGame.h"
#include <array>
using namespace std;

int main(int argc, char* argv[]) {
	OthelloMatrix board = OthelloMatrix {0};
	
	PrintBoard(board);


	int row, col;

	cout << "enter: " << endl;

	GetMove(row, col);
	cout << "row: " << row << "col: " << col << endl;
	cout << "check value: " << IsValidMove(board, row, col);

}