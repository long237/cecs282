#include "OthelloView.h"
#include "OthelloBoard.h"
#include <string>
#include <iostream>
#include <sstream> //For string I/O
#include <memory>
using namespace std;

void OthelloView::PrintBoard(ostream& s) const {
	s << "- 0 1 2 3 4 5 6 7" << endl;
	for (int row = 0; row < OthelloBoard::BOARD_SIZE; row++) {
		s << row << " ";
		for (int col = 0; col < OthelloBoard::BOARD_SIZE; col++) {
			//not sure why the underline under mBoard variable
			if (mOthelloBoard->mBoard[row][col] == OthelloBoard::Player::BLACK) {
				s << "B ";
			}

			else if (mOthelloBoard->mBoard[row][col] == OthelloBoard::Player::WHITE) {
				s << "W ";
			}

			else {
				s << ". ";
			}
		}
		s << "" << endl;
	}
}

unique_ptr<OthelloMove> OthelloView::ParseMove(const string& strFormat) {
	istringstream parser{ strFormat };
	char dummy1, dummy2, dummy3;	//"(2,3)";
	int row, col;
	// order of parsing '(', 'int', ',' , 'int', ')'
	parser >> dummy1 >> row >> dummy2 >> col >> dummy3;
	//cout << "row: " << row << " col: " << col << endl;
	unique_ptr<OthelloMove> PlayerMove = make_unique<OthelloMove>(BoardPosition(row, col));

	return move(PlayerMove);
}

ostream& operator<< (ostream& lhs, const OthelloView& rhs) {
	//print the board to the ostream
	rhs.PrintBoard(lhs);
	//Print the current player to the ostream
	lhs << "Current Player is: " << static_cast<int> (rhs.mOthelloBoard->GetCurrentPlayer())<< endl;
	//lhs << "Current Player is: " << (rhs.mOthelloBoard->GetCurrentPlayer()) << endl;
	return lhs;
}

ostream& operator<<(ostream& lhs, const OthelloMove& rhs) {
	return lhs << static_cast<string> (rhs);
}