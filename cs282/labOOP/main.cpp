#include "Animal.h"
#include "Squirrel.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
	Animal animal1 = Squirrel(2, 3, "Neal");
	Squirrel animal2 = Squirrel(3, 4, "John");

	animal1.Speak();
	animal2.Speak();

	cout << "animal1 weight: " << animal1.GetWeight() << endl;
	cout << "animal2 weight: " << animal2.GetWeight() << endl;

	cout << "animal1 height: " << animal1.getHeight() << endl;
	cout << "animal2 height: " << animal2.getHeight() << endl;
}