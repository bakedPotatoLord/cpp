#pragma once

#include <iostream>
#include <string>
#include "Shape.h"

class Rectangle : public Shape
{
private:
	double length;
	double width;
public:
	Rectangle();
	Rectangle(double, double);
	Rectangle(double, double, std::string);
	void setLength(double);
	double getLength();
	void setWidth(double);
	double getWidth();
	double Area();
	double Perimeter();
};