#include "Game.h"		// Include header file for the Game class
#include <iostream> // Include iostream for input/output operations

using namespace std; // Using standard namespace for convenience

// Function to get the number of ticks
long Game::getTicks() { return ticks; }

// Function to increment the number of ticks
void Game::tick() { ticks++; }

// Function to reset the game state (lives, jumps, ticks)
void Game::resetGame()
{
	lives = 3; // Set initial lives to 3
	jumps = 0; // Reset jumps
	ticks = 0; // Reset ticks
}

// Function to get the current number of lives
int Game::getLives() { return lives; }

// Function to subtract one life from the player
void Game::subtractLife() { lives--; }

// Function to check if the player is alive (has lives remaining)
bool Game::IsAlive() { return lives > 0; }

// Function to print the current number of lives
void Game::printLives() { cout << "lives: " << lives << endl; }

// Function to increment the number of jumps
void Game::addJump() { jumps++; }

// Function to print the current score
void Game::printScore() { cout << "score: " << (ticks + (jumps * 50)) << endl; }

// Constructor for the Game class, initializes game state
Game::Game() { resetGame(); }

// Destructor for the Game class (empty for now)
Game::~Game() {}
