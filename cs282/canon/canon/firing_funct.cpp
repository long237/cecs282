#include <iostream> 
#include <random>
#include "firing_header.h"
#include <cmath>
using namespace std;

//int seed;
//random_device rd;
//mt19937 engine = mt19937 (seed);
//uniform_int_distribution<double> tar_range{ 1.0 , 1000.0 };

int getSeed() {
	int seedValue = -1;
	
	while (seedValue < 0) {	
		cin >> seedValue;
	}
	return seedValue;
}

//double getTarget() {	
//	return tar_range(engine);
//}

double getAngle() {
	double angleValue = -1;
	while (angleValue < 0 || angleValue > 90) {
		cin >> angleValue;
	}
	return angleValue;
} 

double getPowder() { 
	double powderValue = -1;
	while (powderValue < 0) {
		cin >> powderValue;
	}
	return powderValue;
}

double calDistance(double angle, double velocity) {
	double gravity = -9.8;
	double v_vertical;
	double v_horizontal;
	double pi = 3.141592653589793238463;

	//calculating vertical velocity.
	double rad_angle = angle * (pi / 180);	
	v_vertical = velocity * sin(rad_angle);

	v_horizontal = velocity * cos(rad_angle);

	double t_apex = (- v_vertical / gravity);
	double horizontal_distance = v_horizontal * 2 * t_apex;
	
	return horizontal_distance;
}

double calVelo(double powder) {
	double velocity = powder * 30;
	return velocity;
} 

double hitCheck(double target_distance, double usr_distance) {
	if (usr_distance > (target_distance - 1) && usr_distance < target_distance + 1) {
		return 0;
	}
	else if (usr_distance > target_distance) {
		double over_dis = usr_distance - target_distance;
		return over_dis; 
	}
	else {
		double short_dis = usr_distance - target_distance;  
		return short_dis;
	}
}
