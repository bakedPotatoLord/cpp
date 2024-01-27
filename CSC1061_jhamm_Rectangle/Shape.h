#pragma once

#include <iostream>
#include <string>

class Shape
{
private:
    std::string color
public:
    Shape();
    Shape(std::string);
    virtual double Area() = 0;
    virtual double Perimeter() = 0;
};