#pragma once
#include <iostream>
#include <vector>
#include "BoardDirection.h"
class BoardPosition {
private:
	int mRow, mCol;


public:
	BoardPosition();
	BoardPosition(int row, int col);

	inline int getRow() const { return mRow; }
	inline int getCol() const { return mCol; }

	operator std::string() const;

	friend std::istream& operator>> (std::istream& lhs, BoardPosition& rhs);

	bool operator== (BoardPosition rhs);

	bool operator< (BoardPosition rhs);

	BoardPosition operator+ (BoardDirection dir);

	bool inBounds(int boardSize);

	bool inBounds(int rows, int columns);

	static std::vector<BoardPosition> GetRectangularPositions(int rows, int columns);
};

std::ostream& operator<<(std::ostream& lhs, BoardPosition rhs);
