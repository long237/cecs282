#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

string GetInput() {
	string userInput = "";
	while (userInput.length() < 0) {
		cin >> userInput;
	}
	return userInput;
}

bool IsEqual(const unique_ptr<OthelloMove> &move) {
	return true;
}

int main(int argc, char* argv[]) {
	//// Initialization
	//auto board = std::make_shared<OthelloBoard>(); // the state of the game board
	//OthelloView v(board); // a View for outputting the board via operator<<
	//string userInput; // a string to hold the user's command choice

	//// Start with this DEBUGGING CODE to make sure your basic OthelloMove and 
	//// OthelloBoard classes work, then remove it when you are ready to work
	//// on the real main.
	//cout << "Initial board:" << endl;
	//cout << v << endl;

	//cout << "Possible move: " << endl;
	//auto posMove = board->GetPossibleMoves();
	//cout << "Size of Possible move: " << posMove.size() << endl;
	//for (auto itr = posMove.begin(); itr != posMove.end(); itr++) {
	//	cout << *(*itr) << ", ";
	//}
	//cout << "" << endl;

	//unique_ptr<OthelloMove> m{ v.ParseMove("(3, 2)") };
	//cout << "Applying the move " << *m << endl;
	//board->ApplyMove(std::move(m));
	//cout << endl << v << endl; // should show a changed board.
	//cout << "value of board: " << board->GetValue() << endl;

	//posMove = board->GetPossibleMoves();
	//cout << "Size of Possible move: " << posMove.size() << endl;
	//for (auto itr = posMove.begin(); itr != posMove.end(); itr++) {
	//	cout << *(*itr) << ", ";
	//}
	//cout << "" << endl;

	//m = v.ParseMove("(4, 2)");
	//cout << "Applying the move " << *m << endl;
	//board->ApplyMove(std::move(m));
	//cout << endl << v << endl;
	//cout << "value of board: " << board->GetValue() << endl;

	//posMove = board->GetPossibleMoves();
	//cout << "Size of Possible move: " << posMove.size() << endl;
	//for (auto itr = posMove.begin(); itr != posMove.end(); itr++) {
	//	cout << *(*itr) << ", ";
	//}
	//cout << "" << endl;

	//m = v.ParseMove("(5, 2)");
	//cout << "Applying the move " << *m << endl;
	//board->ApplyMove(std::move(m));
	//cout << endl << v << endl;
	//cout << "value of board: " << board->GetValue() << endl;

	//posMove = board->GetPossibleMoves();
	//cout << "Size of Possible move: " << posMove.size() << endl;
	//for (auto itr = posMove.begin(); itr != posMove.end(); itr++) {
	//	cout << *(*itr) << ", ";
	//}
	//cout << "" << endl; 

	//cout << "move history (latest-earliest): " << endl;
	//auto &history = board->GetMoveHistory();
	//for (auto itr2 = history.rbegin(); itr2 != history.rend(); itr2++ ) {
	//	cout << *(*itr2) << ", ";
	//}
	//cout << "" << endl;


	// END OF DEBUGGING CODE

	// Main loop
	string userCommand;
	auto board = make_shared<OthelloBoard>();
	OthelloView view(board);
	do {
		// Print the game board using the OthelloView object
		cout << view << endl;

	   // Print all possible moves
		cout << "List of possible moves: " << endl;
		auto PossibleMoveList = board->GetPossibleMoves();
		for (auto itr = PossibleMoveList.begin(); itr != PossibleMoveList.end(); itr++) {
			cout << *(*itr) << ", ";
		}
		cout << "" << endl;
	   // Ask to input a command
		cout << "Enter a command: " << endl;
		getline(cin, userCommand);
		istringstream parser{ userCommand };
		string firstWord;
		parser >> firstWord;
		cout << "first word: " << firstWord << endl;
	   // Command loop:
		  // move (r,c)
		  // undo n
		  // showValue
		  // showHistory
		  // quit
		//if (userCommand == "move") {
		if (firstWord == "move") {
			string coordinates = userCommand.substr(5, 10);
			cout << "coordinates: " << coordinates << endl;
			unique_ptr<OthelloMove> userMove { view.ParseMove(coordinates) };
			//If the move is valid then apply it
			if (find(PossibleMoveList.begin(), PossibleMoveList.end(), userMove) != PossibleMoveList.end()) {
				board->ApplyMove(move(userMove));
				cout << "Applying the move: " << *userMove << endl;
			}
			else {
				cout << "The move is invalid!!!" << endl;
			}
		}
		else if (userCommand == "undo") {

		}
		else if (userCommand == "showValue") {
			cout << "Value of the board: " << board->GetValue() << endl;
			cout << "" << endl;
		}
		//Add a print line for which player apply the move
		else if (userCommand == "showHistory") {
			cout << "History: " << endl;
			auto &history = board->GetMoveHistory();
			OthelloBoard::Player tempPlayer = board->GetCurrentPlayer();	//the temPlayer is the current player
			for (auto itr = history.rbegin(); itr != history.rend(); itr++ ) {
				//get the previous player by multiplying -1 and keep doing that to the the previous of previous
				//alternating
				tempPlayer = static_cast<OthelloBoard::Player>(static_cast<int>(tempPlayer) * (-1));
				if (tempPlayer == OthelloBoard::Player::WHITE) {
					cout << "White's move";
				}
				else {
					cout << "Black's move";
				}
				cout << *(*itr) << endl;
			}
			cout << "" << endl;
		}
	} while ((userCommand != "quit") || board->IsFinished()); // you may want to change the condition


}


