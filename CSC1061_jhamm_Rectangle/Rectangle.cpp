#pragma once

#include <iostream>
#include <string>
#include "Rectangle.h"

using namespace std;

// Implementation of the Rectangle class

// Default constructor
Rectangle::Rectangle(): Shape() {
    length = 0;
    width = 0;
}

// Parameterized constructor with length and width parameters
Rectangle::Rectangle(double l, double w): Shape() {
    length = l;
    width = w;
}

// Parameterized constructor with length, width, and color parameters
Rectangle::Rectangle(double l, double w, string c) : Shape(c) {
    length = l;
    width = w;
}

// Setter method for setting the length
void Rectangle::setLength(double l) {
    length = l;
}

// Getter method for retrieving the length
double Rectangle::getLength() {
    return length;
}

// Setter method for setting the width
void Rectangle::setWidth(double w) {
    width = w;
}

// Getter method for retrieving the width
double Rectangle::getWidth() {
    return width;
}

// Method to calculate and return the area of the rectangle
double Rectangle::Area() {
    return length * width;
}

// Method to calculate and return the perimeter of the rectangle
double Rectangle::Perimeter() {
    return 2 * (length + width);
}
