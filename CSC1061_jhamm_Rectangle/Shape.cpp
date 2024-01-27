
#include <iostream>
#include <string>
#include "Shape.h"

using namespace std;


/**
 * Constructor for the Shape class.
 */
Shape::Shape::Shape()
{
    color = "blue"; // Set the default color to blue
}

/**
 * Constructor for the Shape class.
 *
 * @param c the color to initialize the Shape with
 */
Shape::Shape(std::string c)
{
    color = c; // Initialize color attribute with the provided color
}
