#include "BoardPostition.h"
#include <iostream>
#include "BoardDirection.h"
#include <array>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
	BoardPosition pos0 = BoardPosition(-1, -1);
	BoardPosition pos1 = BoardPosition(1, 2);
	BoardPosition pos2 = BoardPosition(3, 4);
	BoardPosition pos3 = BoardPosition(2, 1);
	BoardPosition pos4 = BoardPosition(3, 3);
	BoardPosition pos5 = BoardPosition(3, 3);
	BoardPosition pos6 = BoardPosition(-1, -2);

	cout << "Inbound test" << endl;
	int square = 8;
	cout << "Board size: " << square << "x" << square << endl;
	while (!pos0.inBounds(square)) {
		cout << "Enter a coordinate: " << endl;
		cin >> pos0;
	}

	cout << "" << endl;
	cout << "Inbound non square test" << endl;
	int row = 6, col = 8;
	cout << "Board size: " << row << "x" << col << endl;
	while (!pos6.inBounds(row, col)) {
		cout << "Enter a coordinate here: " << endl;
		cin >> pos6;
	}

	cout << "" << endl;
	cout << "Testing << operator: " << endl;
	cout << pos0 << endl;

	cout << "" << endl;

	cout << "Test = operator" << endl;
	cout << "Board position: " << pos4 << " == " << "Board position: " << pos5 << endl;
	cout << "Result of the comparison: " << (pos4 == pos5) << endl;
	cout << pos1 << " == " << pos2 << "?" << endl;
	cout << "Result of comparison: " << (pos1 == pos2) << endl;

	cout << "" << endl;

	cout << "Test < operator" << endl;
	cout << "Board position: " << pos1 << " < " << "Board position: " << pos2 << endl;
	cout << "Result of comparison: " << (pos1 < pos2) << endl;
	cout << pos2 << " < " << pos4 << endl;
	cout << "Result of comparison: " << (pos2 < pos4) << endl;
	cout << pos4 << " < " << pos2 << endl;
	cout << "Result of comparison: " << (pos4 < pos2) << endl;
	cout << pos2 << " < " << pos1 << "?" << endl;
	cout << "Result of comparison: " << (pos2 < pos1) << endl;


	cout << "" << endl;
	cout << "Testing + operator: " << endl;
	cout << pos1 << " + " << "(-1,-1)" << " = " << (pos1 + BoardDirection::CARDINAL_DIRECTION[0]) << endl;

	cout << "" << endl;
	cout << "Position generator " << endl;
	vector<BoardPosition> posList = BoardPosition::GetRectangularPositions(3, 2);

	for (vector<BoardPosition>::iterator itr = posList.begin(); itr != posList.end(); itr++) {
		cout << *itr << endl;
	}




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



}