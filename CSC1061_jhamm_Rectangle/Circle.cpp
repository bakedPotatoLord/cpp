// Include necessary header files
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <math.h>
#include "Circle.h"  // Include the header file for the Circle class

using namespace std;

// Circle class implementation

// Default constructor
Circle::Circle() {
    radius = 0;
}

// Parameterized constructor that also initializes the base class Shape with a color
Circle::Circle(double r, string c) : Shape(c) {
    radius = r;
}

// Calculate and return the area of the circle
double Circle::Area() {
    return M_PI * pow(radius, 2);
}

// Calculate and return the perimeter of the circle
double Circle::Perimeter() {
    return M_PI * 2 * radius;
}

// Get the radius of the circle
double Circle::GetRadius() {
    return radius;
}

// Set the radius of the circle
void Circle::SetRadius(double r) {
    radius = r;
}
