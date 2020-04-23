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
	for (int row = 0; row < BOARD_SIZE; row++) {
		for (int col = 0; col < BOARD_SIZE; col++) {

			BoardPosition tempPosition = BoardPosition(row, col);
			//checking all of the direction in the Cardinal direction list 
			//only when the current possition is the current player and not empty 
			if (mBoard[tempPosition.GetRow()][tempPosition.GetCol()] == mCurrentPlayer) {

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
					listOfPossibleMove.push_back(std::move(possibleMove));
				}
			}
		}
	}
	return listOfPossibleMove;
}

void OthelloBoard::ApplyMove(unique_ptr<OthelloMove> m) {
	
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
		//while (InBounds(OneStepInDirection) && (mBoard[OneStepInDirection.GetRow()][OneStepInDirection.GetCol()] != Player::EMPTY)) {
		//cout << "rowChange: " << static_cast<int>(BoardDirection::CARDINAL_DIRECTION[direction].getRowChange()) << " colChange: " << static_cast<int>(BoardDirection::CARDINAL_DIRECTION[direction].getColChange()) << endl;
		while (InBounds(OneStepInDirection)) {
			//cout << "Step in direction: " << OneStepInDirection << endl;
			//Increase the counter if found an enemy piece
			//cout << "if statement value: " << PositionIsEnemy(OneStepInDirection, mCurrentPlayer) << endl;
			if (PositionIsEnemy(OneStepInDirection, mCurrentPlayer)) {
				//cout << "increase the counter" << endl;
				OneStepInDirection = OneStepInDirection + BoardDirection::CARDINAL_DIRECTION[direction];
				counterForFlip++;
			}

			else {
				break;
			}
		}
		//cout << "counter for flip: " << counterForFlip << endl;
		//Only go back and flip if encounter our own piece at the other end
		//OneStepInDirection variable is now at the end of the direction
		char rowDir = BoardDirection::CARDINAL_DIRECTION[direction].getRowChange();
		char colDir = BoardDirection::CARDINAL_DIRECTION[direction].getColChange();

		OthelloMove::FlipSet flipSet = OthelloMove::FlipSet(counterForFlip, BoardDirection::CARDINAL_DIRECTION[direction]);
		m->AddFlipSet(flipSet);

		if (mBoard[OneStepInDirection.GetRow()][OneStepInDirection.GetCol()] == mCurrentPlayer) {
			//Iterate the same amount of time as the amount of pieces required to flip
			for (int i = 0; i < counterForFlip; i++) {
				//flip the pieces starting from the user position in one direction
				mBoard[m->mPosition.GetRow() + rowDir][m->mPosition.GetCol() + colDir] = mCurrentPlayer;
				//Add the Currentvalue with the with 2 time the amount of the CurrentPlayer when flipping
				mCurrentValue = mCurrentValue + (2 * static_cast<int>(mCurrentPlayer));
			}
		}
	}
	//take ownership of the move
	mHistory.push_back(std::move(m));
	//Update the player turn by multiplying the current player by -1
	mCurrentPlayer = static_cast<Player>((-1) * static_cast<int>(mCurrentPlayer));
}

void OthelloBoard::UndoLastMove() {
	//add code into this function
}