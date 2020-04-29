#include "OthelloMove.h"
#include <iostream>
#include <string> 
#include <sstream>
using namespace std;

bool OthelloMove::operator==(const OthelloMove& rhs) {
	return mPosition == rhs.mPosition;
}

OthelloMove::operator std::string() const {
	//print the position of the move using the BoardPosition string()
	//ostringstream position;
	//position << "(" << to_string(mPosition.GetRow()) << "," << to_string(mPosition.GetCol()) << ")";
	//return position.str();
	if ((mPosition.GetRow() == -1) && (mPosition.GetCol() == -1)) {
		return "pass";
	}
	return mPosition.operator std::string();
	//return static_cast<string>(mPosition);
}