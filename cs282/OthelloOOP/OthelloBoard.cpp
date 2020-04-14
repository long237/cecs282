#include "OthelloBoard.h"
#include <vector>
using namespace std;

OthelloBoard::OthelloBoard() {
	mBoard = {Player::EMPTY};
	mBoard[3][3] = Player::WHITE;
	mBoard[4][4] = Player::WHITE;
	mBoard[3][4] = Player::BLACK;
	mBoard[4][3] = Player::BLACK;
	mCurrentPlayer = Player::BLACK;
	mCurrentValue = 0;
}

vector<unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const {
	//Iterate the entire board
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {

			BoardPosition tempPosition = BoardPosition(row, col);
			//checking all of the direction in the Cardinal direction list
			for (int direction = 0; direction < BoardDirection::CARDINAL_DIRECTION.size(); direction++) {
				//Move to the first position of that direction to check
				BoardPosition posInOneDirection = tempPosition + BoardDirection::CARDINAL_DIRECTION[direction];

				while (InBounds(posInOneDirection) && (mBoard[posInOneDirection.GetRow][posInOneDirection.GetCol] != Player::EMPTY) {

				}
			}
		}
	}
}