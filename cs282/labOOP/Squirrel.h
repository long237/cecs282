#pragma once
#include "Animal.h"
#include <string>
#include <iostream>

class Squirrel : public Animal {
private:
		std::string mName;

public:
	Squirrel(double weight, double height, std::string name)
		: Animal(weight,height), mName(name) {
	}

	double getHeight() const override {
		return (Animal::getHeight() / 2);
	}

	void Speak() const override {
		std::cout << "Appreciate your garbage collector!!!!" << std::endl;
	}

	std::string getName() const{
		return mName;
	}

	void setName(std::string name) {
		mName = name;
	}
};