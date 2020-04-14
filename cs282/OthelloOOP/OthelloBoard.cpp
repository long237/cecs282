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
	//a vector to contain all possible moves
	vector<unique_ptr<OthelloMove>> listOfPossibleMove;

	//Iterate the entire board
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {

			BoardPosition tempPosition = BoardPosition(row, col);
			//checking all of the direction in the Cardinal direction list 
			//only when the current possition is the current player and not empty 
			if (mBoard[tempPosition.GetRow][tempPosition.GetCol] == mCurrentPlayer) {

				//Iterate through the direction lists to check all 8 directions
				for (int direction = 0; direction < BoardDirection::CARDINAL_DIRECTION.size(); direction++) {
					//Move to the first position of that direction to check
					BoardPosition posInOneDirection = tempPosition + BoardDirection::CARDINAL_DIRECTION[direction];

					//Keep moving in that direction as long as it is inbound and the space is not empty
					//while (InBounds(posInOneDirection) && (mBoard[posInOneDirection.GetRow][posInOneDirection.GetCol] != Player::EMPTY)) {
					//Keep moving in that direction as long as it is inbound
					while (InBounds(posInOneDirection)) {
						//Move to the next space in that direction if an enemy piece is found
						if (PositionIsEnemy(posInOneDirection, mCurrentPlayer)) {
							posInOneDirection = posInOneDirection + BoardDirection::CARDINAL_DIRECTION[direction];
						}
						//If found an empty space or ourself(currentplayer) then break
						else {
							break;
						}
					}

					//add the possible move of that one direction to the vector
					unique_ptr<OthelloMove> possibleMove = make_unique<OthelloMove>(posInOneDirection);
					listOfPossibleMove.push_back(possibleMove);
				}
			}
		}
	}
}