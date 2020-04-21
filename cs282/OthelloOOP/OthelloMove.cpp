#include "OthelloMove.h"
#include <iostream>
#include <string> 

bool OthelloMove::operator==(const OthelloMove& rhs) {
	return mPosition == rhs.mPosition;
}

OthelloMove::operator std::string() const {
	//print the position of the move using the BoardPosition string()
	return mPosition.operator std::string();
}