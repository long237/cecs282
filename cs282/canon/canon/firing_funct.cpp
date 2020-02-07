#include <iostream> 
#include <random>
#include "firing_header.h"
#include <cmath>
using namespace std;

//Get the seed from the user, keep asking until a positive value is entered
int getSeed() {
	int seedValue = -1;
	
	while (seedValue <= 0) {
		cout << "Enter a seed value to start the game: " << endl;
		cin >> seedValue;
	}
	return seedValue;
}

//Prompt the user for the firing angle and continue until the user enter a 
//value between 0 < x < 90
double getAngle() {
	double angleValue = -1;
	while (angleValue < 0 || angleValue > 90) {
		cout << "Enter the angle of fire below: " << endl;
		cin >> angleValue;
	}
	return angleValue;
} 

//Prompt the user for the amount of powder to fire the canon
double getPowder() { 
	double powderValue = -1;
	while (powderValue < 0) {
		cout<< "Enter the amount of gun powder below: " << endl;
		cin >> powderValue;
	}
	return powderValue;
}

//Calculate the distance of the bomb with angle and velocity
double calDistance(double angle, double velocity) {
	double gravity = -9.81;
	double v_vertical;
	double v_horizontal;
	double pi = 3.141592653589793238463;

	//calculating vertical velocity.
	double rad_angle = angle * (pi / 180);	
	v_vertical = velocity * sin(rad_angle);

	//calculating horizontal velocity
	v_horizontal = velocity * cos(rad_angle);

	//calculating time it takes for the bomb to return to ground from the apex
	double t_apex = (- v_vertical / gravity);

	//calculate the horizontal distance traveled by the bomb
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
		//cout << "user: " << usr_distance << endl;
		return over_dis; 
	}
	else {
		double short_dis = target_distance - usr_distance; 
		//cout << "user2: " << usr_distance << endl;
		return short_dis;
	}
}
