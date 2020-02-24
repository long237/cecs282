#include <iostream>;
using namespace std;

int main(int argc, char* argv[]) {
	bool b = false, e = true, f = false;
	cout << "result: " << (b + e + f) << endl;

	int y = (2.5 + 2) / 2;
	cout << "y= " << y << endl;

	int x = { 5.5 };
	cout << "x: " << x << endl;
}