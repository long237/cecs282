#include "BoardDirection.h"
#include <array>
#include <vector>
using namespace std;

BoardDirection::BoardDirection() : mrowChange(0), mcolChange(0) {
}

BoardDirection::BoardDirection(char rowChange, char colChange) : mrowChange(rowChange), mcolChange(colChange) {

}

std::array<BoardDirection, 8> BoardDirection::CARDINAL_DIRECTION = { BoardDirection(-1,-1), 
BoardDirection(-1,0), BoardDirection(-1,1), BoardDirection(0,-1), BoardDirection(0,1),
BoardDirection(1,-1), BoardDirection(1,0), BoardDirection(1,1)};
