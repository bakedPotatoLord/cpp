#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include "Shape.h"

class Circle : Shape {
private:
	double radius;
public:
	Circle();
	Circle(double, std::string);
	double Area();
	double Perimeter();
	double GetRadius();
	void SetRadius(double r);
};