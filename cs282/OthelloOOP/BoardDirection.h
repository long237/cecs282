#pragma once

#include <array>
#include <vector>
class BoardDirection {

private:
	char mrowChange, mcolChange;

public:
	static std::array<BoardDirection, 8> CARDINAL_DIRECTION;

	BoardDirection();
	BoardDirection(char, char);

	inline char getRowChange() const { return mrowChange; }
	inline char getColChange() const { return mcolChange; }
};