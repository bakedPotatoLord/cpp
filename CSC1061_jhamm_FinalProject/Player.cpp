#include "Player.h"		 // Include header file for the Player class
#include "Constants.h" // Include header file for constants used in the project
#include <Windows.h>	 // Include Windows.h for Windows-specific functions
#include <vector>			 // Include vector for managing matrices
#include <iostream>		 // Include iostream for input/output operations

using namespace std; // Using standard namespace for convenience

// Constructor for the Player class, calls reset function to initialize player state
Player::Player() : Sprite() { reset(); }

// Function to reset the player's position and state
void Player::reset()
{
	x = 4;						 // Initial x coordinate
	y = 6;						 // Initial y coordinate
	crouching = false; // Player is not crouching
	vy = 0;						 // Vertical velocity
	realY = 0;				 // Real y coordinate
}

// Function to get the appropriate sprite matrix based on player state (crouching or regular)
vector<vector<char>> Player::getMatrix()
{
	return crouching ? crouchingMx : regularMx;
}

// Function to update the player's state
void Player::update()
{
	Sprite::update(); // Call base class update function

	// Gravity logic
	if (!onGround())
	{
		// If in air, apply gravity
		vy += constants::gravityAccel;
	}
	else
	{
		// If on ground, reset vertical velocity and update real y coordinate
		vy = min(vy, 0);
		realY = constants::groundHeight - getHeight();
	}
	realY += vy;
	y = (int)round(realY);

	// Key logic
	bool upPressed = GetKeyState(VK_UP) & 0x8000;
	if (upPressed && !upLast && onGround())
		vy = -1.5; // Jumping
	upLast = upPressed;
	bool downPressed = GetKeyState(VK_DOWN) & 0x8000;
	crouching = downPressed;
}

// Destructor for the Player class (empty for now)
Player::~Player() {}
