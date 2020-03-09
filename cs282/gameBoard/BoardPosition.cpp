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
	return coordinate.str(); 
}

//does not take in const ref for rhs because casting it to a string modifies the value
//due to string operator
ostream& operator<< (ostream& lhs, BoardPosition rhs) {
	lhs << static_cast<string>(rhs);
	return lhs;
}

istream& operator>> (istream& lhs, BoardPosition& rhs) {
	char dummy1, dummy2, dummy3;
	lhs >> dummy1 >> rhs.mRow >> dummy2 >> rhs.mCol >> dummy3;
}

bool BoardPosition::operator== (BoardPosition rhs) {
	if ((mRow != rhs.mRow) || (mCol != rhs.mCol)) {
		return false;
	}
}

bool BoardPosition::operator< (BoardPosition rhs) {
	if (mRow > rhs.mRow) {
		return false;
	}
	else if ((mRow == rhs.mCol) && (mCol > rhs.mCol)) {
		return false;
	}
}