#include "Animal.h"
#include "Squirrel.h"
#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	//Squirrel squir1 = Squirrel(6, 7, "Jane");
	//Animal* animal3 = &squir1;

	//Animal* animal1 = new Squirrel(2, 3, "Neal");
	//Squirrel animal2 = Squirrel(3, 4, "John");

	//Animal* animal5 = new Squirrel(3, 5, "Sam");

	//unique_ptr<Animal> animal4 = make_unique<Squirrel>(4, 5, "Anna");

	//animal1->Speak();
	//animal2.Speak();

	//cout << "animal1 weight: " << animal1->GetWeight() << endl;
	//cout << "animal2 weight: " << animal2.GetWeight() << endl;
	//cout << "" << endl;
	//cout << "animal1 height: " << animal1->getHeight() << endl;
	//cout << "animal2 height: " << animal2.getHeight() << endl;

	//cout << "animal3 name: " << squir1.getName() << endl;
	vector<int> values = { 1, 6, 3, -4, 10 };

	auto itr = std::find_if(values.begin(), values.end(),
		// Syntax: [](parameters) { body }
		[](int value) { return value % 5 == 0; }
	);
	cout << "Found " << *itr << endl;
}