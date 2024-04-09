#include "Renderer.h"	 // Include header file for the Renderer class
#include <iostream>		 // Include iostream for input/output operations
#include "Constants.h" // Include header file for constants used in the project

using namespace std;			 // Using standard namespace for convenience
using namespace constants; // Using namespace of constants for easy access to constants

// Function to update the state of all sprites
void Renderer::updateSprites()
{
	for (auto sprite : sprites)
		sprite->update();
}

// Function to clear the console screen
void Renderer::clearConsole() { system("cls"); }

// Function to render the matrix representing the game screen
void Renderer::renderMx()
{
	if (game->getLives() <= 0)
	{
		cout << "Game Over! Press Enter to try again." << endl;
	}
	else
	{
		setBackground(); // Set background based on ground height

		// Render each sprite onto the screen matrix
		for (auto sprite : sprites)
		{
			for (size_t i = 0; i < sprite->getMatrix().size(); i++)
			{
				for (size_t j = 0; j < sprite->getMatrix()[i].size(); j++)
				{
					auto sy = sprite->getY() + i;
					auto sx = sprite->getX() + j;
					if (sy >= 0 && sy < screenHeight && sx >= 0 && sx < screenWidth)
						mx[sy][sx] = sprite->getMatrix()[i][j];
				}
			}
		}

		// Output the screen matrix to the console
		for (auto &row : mx)
		{
			for (auto c : row)
			{
				cout << c;
			}
			cout << endl;
		}
	}
}

// Function to add a sprite to the renderer
void Renderer::addSprite(Sprite *sprite)
{
	sprites.push_back(sprite); // Add sprite to the list of sprites
	getNumSprites();					 // Update the number of sprites
}

// Function to destroy a sprite in the renderer
void Renderer::destroySprite(Sprite *sprite)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] == sprite)
		{
			sprites[i] = sprites.back();
			sprites.pop_back();
		}
	}
}

// Function to set the background of the game screen
void Renderer::setBackground()
{
	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			if (i >= groundHeight)
				mx[i][j] = ((i + j) % 2 == 0) ? '*' : '%'; // Alternate characters for ground
			else
				mx[i][j] = ' '; // Empty space above ground
		}
	}
}

// Function to get the number of sprites currently in the renderer
size_t Renderer::getNumSprites()
{
	size_t s = sprites.size(); // Get the size of the sprites vector
	return s;									 // Return the size
}

// Constructor for the Renderer class
Renderer::Renderer(Game *game)
{
	height = screenHeight;																							// Set height of the renderer
	width = screenWidth;																								// Set width of the renderer
	sprites = vector<Sprite *>();																				// Initialize empty vector of sprites
	mx = vector<vector<char>>(screenHeight, vector<char>(screenWidth)); // Initialize empty game screen matrix
	setBackground();																										// Set initial background
	this->game = game;																									// Set game pointer
}

// Default constructor for the Renderer class (not to be used)
Renderer::Renderer() { throw "do not use this constuctor"; }
