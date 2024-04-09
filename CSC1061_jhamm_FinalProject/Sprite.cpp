
#include "Sprite.h"
#include "Constants.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace constants;

int Sprite::getX() { return x; }

int Sprite::getY() { return y; }

vector<vector<char>> Sprite::getMatrix() { return spriteMx; }

int Sprite::getHeight() { return (int)getMatrix().size(); }

int Sprite::getWidth() { return (int)getMatrix()[0].size(); }

bool Sprite::onGround() { return y + getHeight() >= groundHeight; }

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

void Sprite::update() {}

Sprite::Sprite()
{
    x = 0;
    y = 0;
}

Sprite::~Sprite(){};