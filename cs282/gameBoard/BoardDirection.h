#pragma once
#include <array>
#include "BoardPostition.h"
class BoardDirection {

private:
	char mrowChange, mcolChange;

public:
	std::array<BoardDirection, 8> CARDINAL_DIRECTION;

	BoardDirection();
	BoardDirection(char, char);

	inline char getRowChange() const { return mrowChange; }
	inline char getColChange() const { return mcolChange; }

	
};