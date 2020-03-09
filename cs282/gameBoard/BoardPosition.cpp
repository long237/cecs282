#include "BoardPostition.h";
#include <iostream>
#include <sstream> //string input and output
#include <vector>
using namespace std;

BoardPosition::BoardPosition() : mRow(0), mCol(0) {
}

BoardPosition::BoardPosition(int row, int col) : mRow(row), mCol(col) {
}

BoardPosition::operator std::string() const{
	ostringstream coordinate;
	coordinate << "(" << to_string (BoardPosition::mRow) << ", " << to_string(BoardPosition::mCol) << ")" ;
	return coordinate.str(); 
}

//BoardPosition::operator std::string() const {
//	string value = "";
//	value = "(" + to_string(BoardPosition::mRow) + ", " + to_string(BoardPosition::mCol) + ")";
//	return value;
//}

//does not take in const ref for rhs because casting it to a string modifies the value
//due to string operator
std::ostream& operator<< (std::ostream& lhs, BoardPosition rhs) {
	lhs << static_cast<string>(rhs);
	return lhs;
}

istream& operator>> (istream& lhs, BoardPosition& rhs) {
	char dummy1, dummy2, dummy3;
	lhs >> dummy1 >> rhs.mRow >> dummy2 >> rhs.mCol >> dummy3;
	return lhs;
}

bool BoardPosition::operator== (BoardPosition rhs) {
	return ((mRow == rhs.mRow) && (mCol == rhs.mCol));
}

bool BoardPosition::operator< (BoardPosition rhs) {
	if (mRow > rhs.mRow) {
		return false;
	}
	else if ((mRow == rhs.mRow) && (mCol >= rhs.mCol)) {
		return false;
	}
	return true;
}

bool BoardPosition::inBounds(int boardSize) {
	return ((mRow > 0) && (mRow < boardSize -1) && (mCol > 0) && (mCol < boardSize - 1));
}

bool BoardPosition::inBounds(int row, int column) {
	return ((mRow > 0) && (mRow < row) && (mCol > 0) && (mCol < column));
}

std::vector<BoardPosition> BoardPosition::GetRectangularPositions(int rows, int columns) {
	vector<BoardPosition> positionList;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < columns; c++)
			positionList.push_back(BoardPosition(r, c));
	}
	return positionList;
}