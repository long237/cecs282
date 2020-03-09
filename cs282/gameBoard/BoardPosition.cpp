#include "BoardPostition.h";
#include <iostream>
#include <sstream> //string input and output

using namespace std;

BoardPosition::BoardPosition() : mRow(0), mCol(0) {
}

BoardPosition::BoardPosition(int row, int col) : mRow(row), mCol(col) {
}

BoardPosition::operator string() const{
	ostringstream coordinate;
	coordinate << "(" << BoardPosition::mRow << ", " << BoardPosition::mCol << ")" ;
}