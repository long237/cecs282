#include <iomanip>
#include <iostream>
#include "tictactoe.h"
using namespace std;

int main(int argc, char* argv[]) {
	int usr_row = 0;
	int usr_col = 0;
	
	GetMove(usr_row, usr_col);
	cout<< "this is row: " << usr_row <<endl;
	cout << "this is col: " << usr_col <<endl;
	
	char test = 5;
	cout<< "char value " << test << endl;
	cout<<"test array" <<endl;	
	std::array<char,3> testcase = {0,0,0};
	for(int i = 0; i < 3; i++) {
		cout<< testcase[i] <<endl;
	}
	char test_var = '-1';
	cout << "this is test variable: " << (int) test_var << endl;
	std::array<std::array<char, 3>, 3> board = {0};
	//cout << "this is the array: " << board << endl;	
	PrintBoard(board);	

	board[0][0] = 0;
	board[0][1] = 0;
	board[0][2] = '1';
	board[1][0] = 0;
	board[1][1] = '1';
	board[1][2] = 0;
	board[2][0] = '1';
	board[2][1] = 0;
	board[2][2] = '1';
	cout<<"this is the board: "<< endl;
	PrintBoard(board);

	cout<< "test check move " << MoveIsValid(board, usr_row, usr_col)<< endl;
 
}
