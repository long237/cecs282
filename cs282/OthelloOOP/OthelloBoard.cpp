#include "OthelloBoard.h"
#include <vector>
using namespace std;

OthelloBoard::OthelloBoard():mCurrentPlayer(Player::BLACK), mCurrentValue(0) {
	mBoard = {Player::EMPTY};
	mBoard[3][3] = Player::WHITE;
	mBoard[4][4] = Player::WHITE;
	mBoard[3][4] = Player::BLACK;
	mBoard[4][3] = Player::BLACK;
}

vector<unique_ptr<OthelloMove>> OthelloBoard::GetPossibleMoves() const {
	//a vector to contain all possible moves
	vector<unique_ptr<OthelloMove>> listOfPossibleMove;

	//Iterate the entire board
	for (BoardPosition tempPosition : BoardPosition::GetRectangularPositions(8,8)){
			//checking all of the direction in the Cardinal direction list 
			//only when the current possition is the current player and not empty 
			if (mBoard[tempPosition.GetRow()][tempPosition.GetCol()] == Player::EMPTY) {

				//Iterate through the direction lists to check all 8 directions
				for (int direction = 0; direction < BoardDirection::CARDINAL_DIRECTION.size(); direction++) {
					//Move to the first position of that direction to check
					BoardPosition posInOneDirection = tempPosition + BoardDirection::CARDINAL_DIRECTION[direction];
					//Keep moving in that direction as long as it is inbound and it is not our own piece
					int moveCounter = 0;
					while (InBounds(posInOneDirection)) {
						//Move to the next space in that direction if an enemy piece is found
						if (PositionIsEnemy(posInOneDirection, mCurrentPlayer)) {
							posInOneDirection = posInOneDirection + BoardDirection::CARDINAL_DIRECTION[direction];
							moveCounter++;
						}
						//If found an empty space or ourself(currentplayer) then break
						else {
							break;
						}
					}
					//add the possible move of that one direction to the vector
					if (InBounds(posInOneDirection) && (mBoard[posInOneDirection.GetRow()][posInOneDirection.GetCol()] == mCurrentPlayer) && moveCounter != 0) {
						//add the temp position in the outer for loop and not the position when stepping in the direction					
						listOfPossibleMove.push_back(std::move(make_unique<OthelloMove>(tempPosition)));
						break;		//The moment you find a direction with a valid pattern(temp - enemy - ourselves), immediately break, otherwise you will add duplicates of the temp position since it can be valid for multiple direction.
					}
				}
			}
		}
	//Add a pass to the list of possible moves if there are no possible moves
	if (listOfPossibleMove.size() == 0) {
		listOfPossibleMove.push_back(std::move(make_unique<OthelloMove>()));
	}
	return listOfPossibleMove;
}

void OthelloBoard::ApplyMove(unique_ptr<OthelloMove> m) {
	
	//only execute these if it not a pass
	if (!m->IsPass()) {
		//Set the chosen position to the player value
		mBoard[m->mPosition.GetRow()][m->mPosition.GetCol()] = mCurrentPlayer;
		//Adjust the value of the board after placing the new piece
		mCurrentValue = mCurrentValue + static_cast<int>(mCurrentPlayer);

		//Iterate through the list of 8 directions to check for pieces to flip
		for (int direction = 0; direction < BoardDirection::CARDINAL_DIRECTION.size(); direction++) {
			//Take a step in the chosen direction using the cardinal list
			BoardPosition OneStepInDirection = m->mPosition + BoardDirection::CARDINAL_DIRECTION[direction];
			//Counter to flip pieces later on
			int counterForFlip = 0;
			//Keep moving in that direction as long as it is inbound and the position is not empty
			while (InBounds(OneStepInDirection)) {
				//Increase the counter if found an enemy piece
				if (PositionIsEnemy(OneStepInDirection, mCurrentPlayer)) {
					OneStepInDirection = OneStepInDirection + BoardDirection::CARDINAL_DIRECTION[direction];
					counterForFlip++;
				}
				//Break the loop if encounter an Empty space or ourselves
				else {
					break;
				}
			}
			//Only go back and flip if encounter our own piece at the other end
			//OneStepInDirection variable is now at the end of the direction
			BoardPosition tempPosition = m->mPosition;
			if (InBounds(OneStepInDirection) && mBoard[OneStepInDirection.GetRow()][OneStepInDirection.GetCol()] == mCurrentPlayer) {
				//Add flipset before flipping
				m->AddFlipSet(OthelloMove::FlipSet(counterForFlip, BoardDirection::CARDINAL_DIRECTION[direction]));
				//Iterate the same amount of time as the amount of pieces required to flip
				for (int i = 0; i < counterForFlip; i++) {
					tempPosition = tempPosition + BoardDirection::CARDINAL_DIRECTION[direction];
					//flip the pieces starting from the user position in one direction
					mBoard[tempPosition.GetRow()][tempPosition.GetCol()] = mCurrentPlayer;
					//Add the Currentvalue with the with 2 time the amount of the CurrentPlayer when flipping
					mCurrentValue = mCurrentValue + (2 * static_cast<int>(mCurrentPlayer));
				}
			}
		}
	}
	//Do these line even if it is a pass
	//take ownership of the move
	mHistory.push_back(std::move(m));
	//Update the player turn by multiplying the current player by -1
	mCurrentPlayer = static_cast<Player>((-1) * static_cast<int>(mCurrentPlayer));
}

void OthelloBoard::UndoLastMove() {
	
	auto &lastMove = mHistory.back();
	//Execute these lines if the move is not a pass
	if (!lastMove->IsPass()) {
		//Each flipset is one cardinal direction, iterate through all the direction to flip back
		for (int index = 0; index < lastMove->mFlips.size(); index++) {
			//a temp position starting from the last move position
			BoardPosition tempPos = lastMove->mPosition;
			//take one step in the Cardinal direction
			//flip pieces in one direction
			for (int i = 0; i < lastMove->mFlips[index].mFlipCount; i++) {
				tempPos = tempPos + lastMove->mFlips[index].mDirection;
				mBoard[tempPos.GetRow()][tempPos.GetCol()] = mCurrentPlayer;
				mCurrentValue = mCurrentValue + (2 * static_cast<int>(mCurrentPlayer));
			}
		}

		mCurrentValue = mCurrentValue + static_cast<int>(mCurrentPlayer);
		mBoard[lastMove->mPosition.GetRow()][lastMove->mPosition.GetCol()] = Player::EMPTY;
	}

	mHistory.pop_back();
	mCurrentPlayer = static_cast<OthelloBoard::Player> ((-1) * static_cast<int>(mCurrentPlayer));
}

//comparing the last move in history to the second to last move in history, return true if they are the same.
bool OthelloBoard::IsFinished() const{
	return ( *(mHistory.back()) == *(*(mHistory.end() - 2)) );
}