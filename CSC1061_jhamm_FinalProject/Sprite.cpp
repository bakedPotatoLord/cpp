#include "Sprite.h"    // Include header file for the Sprite class
#include "Constants.h" // Include header file for constants used in the project
#include <vector>      // Include vector for managing matrices
#include <iostream>    // Include iostream for input/output operations

using namespace std;       // Using standard namespace for convenience
using namespace constants; // Using namespace of constants for easy access to constants

// Getters for the x and y coordinates of the sprite
int Sprite::getX() { return x; }
int Sprite::getY() { return y; }

// Getter for the sprite matrix
vector<vector<char>> Sprite::getMatrix() { return spriteMx; }

// Getter for the height of the sprite
int Sprite::getHeight() { return (int)getMatrix().size(); }

// Getter for the width of the sprite
int Sprite::getWidth() { return (int)getMatrix()[0].size(); }

// Check if the sprite is on the ground
bool Sprite::onGround() { return y + getHeight() >= groundHeight; }

// Check if the sprite is touching another sprite
bool Sprite::touching(Sprite &other)
{
    // Get the position and dimensions of both sprites
    int thisX = getX();
    int thisY = getY();
    int thisWidth = getWidth();
    int thisHeight = getHeight();

    int otherX = other.getX();
    int otherY = other.getY();
    int otherWidth = other.getWidth();
    int otherHeight = other.getHeight();

    // Check for collision by comparing the positions and dimensions
    if ((thisX + thisWidth) >= otherX &&
        thisX <= (otherX + otherWidth) &&
        (thisY + thisHeight) >= otherY &&
        thisY <= (otherY + otherHeight))
    {
        // Collision detected
        return true;
    }

    // No collision
    return false;
}

// Update function for the sprite (empty for now, can be overridden by derived classes)
void Sprite::update() {}

// Constructor for the Sprite class, initializes x and y coordinates to 0
Sprite::Sprite()
{
    x = 0;
    y = 0;
}

// Destructor for the Sprite class (empty for now)
Sprite::~Sprite(){};
