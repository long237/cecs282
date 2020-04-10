#pragma once

// In this lecture, I will put all implementations inside class declarations.
// This is not the preferred C++ style, but it is shorter.
#include <iostream>
class Animal {
private:
	double mWeight;
	double mHeight;

public:
	Animal(double weight) : mWeight(weight) {
		mHeight = 1;
	}
	Animal(double weight,double height) : mWeight(weight), mHeight(height) {
	}

	inline double GetWeight() const {
		return mWeight;
	}

	void SetWeight(double weight) {
		mWeight = weight;
	}

	virtual double getHeight() const{
		return mHeight;
	}

	void setHeight(double newHeight) {
		mHeight = newHeight;
	}







	virtual void Speak() const {
		std::cout << "I am an animal!" << std::endl;
	}
};