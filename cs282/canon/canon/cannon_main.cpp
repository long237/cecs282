#include <random>
#include <iomanip> // for setprecision
#include <iostream>
#include "firing_header.h"
using namespace std;

int main(int argc, char* argv[]) {
	double tar_dis = 500;
	double usr_angle;
	double usr_powder;
	double usr_dis;
	double init_velocity;
	double relative_dis = 2;
	int seed;

	cout << "Enter a seed value to start the game: " << endl;	seed = getSeed();
	random_device rd;
	mt19937 engine = mt19937 (seed);
	uniform_real_distribution<double> tar_range{ 1.0 , 1000.0 };

	tar_dis = tar_range(engine);
	cout << "this is the target distance: " << tar_dis << endl;
	while (relative_dis != 0) {
		cout << "Enter the angle of fire below: " << endl;
		usr_angle = getAngle();
		
		cout << "Enter the amount of gun powder below: " << endl;
		usr_powder = getPowder();
		
		init_velocity = calVelo(usr_powder);
		usr_dis = calDistance(usr_angle, init_velocity);
		relative_dis = hitCheck(tar_dis, usr_dis);	
		
		if(relative_dis == 0) {
			cout << "Target Hit!!!!!" << endl;
		}
		else if (relative_dis > tar_dis) {
			cout << "You overshot by: " << fixed << setprecision(2) << relative_dis<< " m"<< endl;
		}
		else {
			cout << "You are short by: " << fixed << setprecision(2) << relative_dis << " m"<<endl;
		}
	}
}
