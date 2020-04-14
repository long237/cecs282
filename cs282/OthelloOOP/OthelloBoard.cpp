#include "OthelloBoard.h"

OthelloBoard::OthelloBoard() {
	mBoard = {Player::EMPTY};
	mBoard[3][3] = Player::WHITE;
	mBoard[4][4] = Player::WHITE;
	mBoard[3][4] = Player::BLACK;
	mBoard[4][3] = Player::BLACK;
	mCurrentPlayer = Player::BLACK;
	mCurrentValue = 0;
}