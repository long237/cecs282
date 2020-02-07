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
	
	//Prompt user to enter a seed value
	seed = getSeed();
	random_device rd;
	mt19937 engine = mt19937 (seed);
	uniform_real_distribution<double> tar_range{ 1.0 , 1000.0 };

	//generate a random distance
	tar_dis = tar_range(engine);
	cout << "this is the target distance: " << fixed << setprecision(2) << tar_dis << "m" <<endl;
	cout << "" << endl;

	while (relative_dis != 0) {
		usr_angle = getAngle();
	
		usr_powder = getPowder();
		
		init_velocity = calVelo(usr_powder);
		usr_dis = calDistance(usr_angle, init_velocity);
		relative_dis = hitCheck(tar_dis, usr_dis);	

		//cout << "target: " << tar_dis << endl;
		//cout << "user: " << relative_dis << endl;
		
		//Print target hit if the bomb relative distance to the target is within 1m
		if(relative_dis == 0) {
			cout << "Target Hit!!!!!" << endl;
		}
		//Print overshot if the user distance is more than the target distance
		else if (usr_dis > tar_dis) {
			cout << "You overshot by: " << fixed << setprecision(2) << relative_dis<< "m"<< endl;
			cout << "" << endl;
		}
		//Print short if the user distance is smaller than the target distance
		else {
			cout << "You are short by: " << fixed << setprecision(2) << relative_dis << "m"<<endl;
			cout << "" << endl;
		}
	}
}
