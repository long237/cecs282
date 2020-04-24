#include "OthelloBoard.h"
#include "OthelloView.h"
#include "OthelloMove.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

string GetInput() {
	string userInput = "";
	while (userInput.length() < 0) {
		cin >> userInput;
	}
	return userInput;
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
	do {
		// Print the game board using the OthelloView object
		auto board = make_shared<OthelloBoard>();
		OthelloView view(board);
		cout << "Initial board: " << endl;
		cout << view << endl;

	   // Print all possible moves
		auto PossibleMoveList = board->GetPossibleMoves();
		for (auto itr = PossibleMoveList.begin(); itr != PossibleMoveList.end(); itr++) {
			cout << *(*itr) << ", ";
		}
		cout << "" << endl;
	   // Ask to input a command
		cout << "Enter a command: " << endl;
		userCommand = GetInput();

	   // Command loop:
		  // move (r,c)
		  // undo n
		  // showValue
		  // showHistory
		  // quit
		if (userCommand == "move") {

		}
		else if (userCommand == "undo") {

		}
		else if (userCommand == "showValue") {
			cout << "Value of the board: " << board->GetValue() << endl;
		}
		//Add a print line for which player apply the move
		else if (userCommand == "showHistory") {
			auto &history = board->GetMoveHistory();
			for (auto itr = history.rbegin(); itr != history.rend(); itr++ ) {
				cout << *(*itr) << endl;
			}
		}
	} while (userCommand != "quit"); // you may want to change the condition


}


