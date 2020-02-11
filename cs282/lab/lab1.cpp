#include <iostream>;
using namespace std;
int RoundtoNearest(double x);
//int main(int argc, char* argv[]) {
//	double x = 2.9;
//	cout << "this is the result " << RoundtoNearest(x) << endl;
//
//	int a = 9;
//	int b = a;
//	int *c = &a;
//	int *d = c;
//	int e = *c;
//
//	cout << "a" << a << endl;
//	cout << "b" << b << endl;
//	cout << "c" << c << endl;
//	cout << "d" << d << endl;
//	cout << "e" << e << endl;
//}

int RoundtoNearest(double x) {
	int y = x + 0.5;
	return y;
}