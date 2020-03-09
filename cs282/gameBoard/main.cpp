#include "BoardPostition.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	BoardPosition pos1 = BoardPosition();
	BoardPosition pos2 = BoardPosition(1, 2);
	BoardPosition pos3 = BoardPosition(3, 4);
	BoardPosition pos4 = BoardPosition(2, 1);

	//cout << pos1;
	//int row, col;
	//cout << "put row and col" << endl;
	//cin >> pos1;
	//cout << pos1;
	bool result = (pos3 == pos4);
	cout << "comparison result"<< result << endl;

	bool less = (pos4 < pos3);
	cout << "Less than " << less << endl;

	cout << "Inbound test " << endl;
	cout << pos3.inBounds(4) << endl;

	cout << "non-square inbound test: " << endl;
	cout << pos3.inBounds(3, 3) << endl;

	cout << "Position generator " << endl;
	vector<BoardPosition> posList = BoardPosition::GetRectangularPositions(3, 2);
	
	for (vector<BoardPosition>::iterator itr = posList.begin(); itr != posList.end(); itr++) {
		cout << *itr << endl;
	}
}