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

	inline int GetRow() const { return mRow; }
	inline int GetCol() const { return mCol; }

	operator std::string() const;

	friend std::istream& operator>> (std::istream& lhs, BoardPosition& rhs);

	bool operator== (BoardPosition rhs);

	bool operator< (BoardPosition rhs);

	BoardPosition operator+ (BoardDirection dir);

	bool InBounds(int boardSize);

	bool InBounds(int rows, int columns);

	static std::vector<BoardPosition> GetRectangularPositions(int rows, int columns);
};

std::ostream& operator<<(std::ostream& lhs, BoardPosition rhs);