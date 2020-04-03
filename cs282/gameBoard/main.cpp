#include "BoardPostition.h"
#include <iostream>
#include "BoardDirection.h"
#include <array>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	BoardPosition pos0 = BoardPosition();
	BoardPosition pos1 = BoardPosition(1, 2);
	BoardPosition pos2 = BoardPosition(3, 4);
	BoardPosition pos3 = BoardPosition(2, 1);
	BoardPosition pos4 = BoardPosition(3, 3);
	BoardPosition pos5 = BoardPosition(3, 3);

	cout << "Testing << operator: " << endl;
	cout << pos0 << endl;

	cout << "Testing >> operator: " << endl;
	cout << "Enter a coordinate here: " << endl;
	cin >> pos0;
	cout << "Board Position is: " << endl;
	cout << pos0 << endl;

	cout << "Board position 4: " << pos4 << " == " << "Board position 5: " << pos5 << endl;
	cout << "Result of the comparison: " << (pos4 == pos5) << endl;

	cout << "Board position 1: " << pos1 << " < " << "Board position 2: " << pos2 << endl;
	cout << "Result of comparison: " << (pos1 < pos2) << endl;



	//cout << pos1;
	//int row, col;
	//cout << "put row and col" << endl;
	//cin >> pos1;
	//cout << pos1;
	//bool result = (pos3 == pos4);
	//cout << "comparison result"<< result << endl;

	//bool less = (pos4 < pos3);
	//cout << "Less than " << less << endl;

	//cout << "Inbound test " << endl;
	//cout << pos3.inBounds(4) << endl;

	//cout << "non-square inbound test: " << endl;
	//cout << pos3.inBounds(3, 3) << endl;

	//cout << "Position generator " << endl;
	//vector<BoardPosition> posList = BoardPosition::GetRectangularPositions(3, 2);
	//
	//for (vector<BoardPosition>::iterator itr = posList.begin(); itr != posList.end(); itr++) {
	//	cout << *itr << endl;
	//}

}