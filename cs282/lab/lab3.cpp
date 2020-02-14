#include <iostream>;
#include <cmath>;
using namespace std;
int SolveQuadratic(const double a, const double b, const double c,  double *xSolution1, double *xSolution2) {
	double delta = pow( b, 2) - (4 * a * c);
	if ( delta < 0 ) {
		*xSolution1 = 0;
		*xSolution2 = 0;
		return 0;
	}
	else {
		*xSolution1 = (-b + sqrt(delta)) / (2 * a);
		*xSolution2 = (-b - sqrt(delta)) / (2 * a);

		if (*xSolution1 == *xSolution2) {
			*xSolution2 = 0.0;
			return 1;
		}
		else {
			return 2;
		}
	}
}
//int main(int argc, char* argv[]) {
//	double a = 1;
//	double b = 2;
//	double c = 1;
//	double xSolution1, xSolution2;
//	int numSolution = SolveQuadratic(a ,b , c, &xSolution1, &xSolution2);
//	cout << "Solution 1: " << xSolution1 << endl;
//	cout << "Solution 2: " << xSolution2 << endl;
//	cout << "number of solutions: "<< numSolution <<endl;
//	cout << "" <<endl;
//	a = 1;
//	b = 0;
//	c = 1;
//	numSolution = SolveQuadratic(a ,b , c, &xSolution1, &xSolution2);
//	cout << "Solution 1: " << xSolution1 << endl;
//	cout << "Solution 2: " << xSolution2 << endl;
//	cout << "number of solutions: "<< numSolution <<endl;
//	cout << "" <<endl;
//	a = 1;
//	b = -3;
//	c = -4;
//	numSolution = SolveQuadratic(a ,b , c, &xSolution1, &xSolution2);
//	cout << "Solution 1: " << xSolution1 << endl;
//	cout << "Solution 2: " << xSolution2 << endl;
//	cout << "number of solutions: "<< numSolution <<endl;
//
//}


