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
	if (IsPass()) {
		return "pass";
	}
	return mPosition.operator std::string();
}