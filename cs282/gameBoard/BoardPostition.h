#pragma once
#include <iostream>

class BoardPosition {
private:
	int row, col;


public:
	BoardPosition();
	BoardPosition(int row, int col);

	inline int getRow() const { return row; }
	inline int getCol() const { return col; }

	operator std::string();

	friend std::ostream& operator<<(std::ostream& lhs, BoardPosition rhs);

	friend std::istream& operator>> (std::istream& lhs, BoardPosition& rhs);

	bool operator== (BoardPosition rhs);

	bool operator< (BoardPosition rhs);

	bool inBounds(int boardSize);


};
