#include "Cactus.h"      // Include header file for the Cactus class
#include "Constants.h"   // Include header file for constants used in the project
#include <iostream>      // Include iostream for input/output operations

using namespace constants;  // Using namespace of constants for easy access to constants

// Constructor for the Cactus class, initializes a small cactus by default
Cactus::Cactus() : Sprite()
{
    Cactus(small);  // Call parameterized constructor with default parameter
}

// Parameterized constructor for the Cactus class
Cactus::Cactus(cactusType type)
{
    x = screenWidth;                          // Initial x coordinate (right side of the screen)
    y = groundHeight - getHeight();           // Initial y coordinate (on the ground)
    this->type = type;                        // Set cactus type

    if (type == flying)
    {
        y -= 5;   // Adjust y coordinate if it's a flying cactus
    }
}

// Destructor for the Cactus class
Cactus::~Cactus()
{
    // Loop through the sprite matrix and delete each row
    for (auto &row : spriteMx)
    {
        delete &row;
    }
}

// Function to get the appropriate sprite matrix based on cactus type
std::vector<std::vector<char>> Cactus::getMatrix()
{
    switch (type)
    {
        case tiny:
            return smallCactus;   // Return matrix for tiny cactus
        case medium:
            return midCactus;     // Return matrix for medium cactus
        case large:
            return largeCactus;   // Return matrix for large cactus
        case flying:
            return flyingCactus;  // Return matrix for flying cactus
    };
}

// Function to update the cactus position
void Cactus::update()
{
    Sprite::update();  // Call base class update function
    x--;               // Move the cactus to the left
}
