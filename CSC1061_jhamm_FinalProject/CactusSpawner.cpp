#include "CactusSpawner.h" // Include header file for the CactusSpawner class
#include <iostream>				 // Include iostream for input/output operations

// Function to set whether the cactus spawner is enabled
void CactusSpawner::setEnabled(bool val)
{
	enabled = val;								// Set enabled flag
	lastSpawn = game->getTicks(); // Set last spawn time to current tick
	spawnTick = lastSpawn;				// Set spawn tick to last spawn time
}

// Function to update the cactus spawner
void CactusSpawner::update()
{
	// Try to spawn new cacti
	if (spawnTick <= game->getTicks())
	{
		cactusType type = (cactusType)(rand() % 4); // Randomly select cactus type
		Cactus *cactus = new Cactus(type);					// Create new cactus object
		spawnCactus(cactus);												// Spawn the cactus
		spawnTick = calculateSpawnTick();						// Calculate next spawn tick
	}

	// Update living cacti
	for (auto cactus : cacti)
		cactus->update();

	// Iterate over cacti
	for (auto cactus : cacti)
	{
		// Delete off-screen cacti
		if (cactus->getX() < 0)
		{
			deleteCactus(cactus); // Delete the cactus
			game->addJump();			// Increment jump count
			continue;							// Continue to next iteration
		}

		// Handle collision with player
		if (cactus->touching(*player))
		{
			deleteCactus(cactus); // Delete the cactus
			game->subtractLife(); // Subtract one life from the player
		}
	}
}

// Function to spawn a cactus
void CactusSpawner::spawnCactus(Cactus *cactus)
{
	cacti.push_back(cactus);		 // Add cactus to the list of cacti
	renderer->addSprite(cactus); // Add cactus to the renderer
}

// Function to delete a cactus
void CactusSpawner::deleteCactus(Cactus *cactus)
{
	renderer->destroySprite(cactus); // Delete cactus from the renderer

	// Delete cactus from the spawner
	for (int i = 0; i < cacti.size(); i++)
	{
		if (cacti[i] == cactus)
		{
			cacti[i] = cacti.back();
			cacti.pop_back();
		}
	}
}

// Function to reset the cactus spawner
void CactusSpawner::reset()
{
	for (auto cactus : cacti)
	{
		deleteCactus(cactus); // Delete each cactus
	}
}

// Function to calculate the next spawn tick for a cactus
long CactusSpawner::calculateSpawnTick()
{
	long tick = game->getTicks();			// Get current tick
	return tick + 20 + (rand() % 20); // Return a random value for next spawn tick
}

// Constructor for the CactusSpawner class (not to be used)
CactusSpawner::CactusSpawner()
{
	throw "don't use this constructor"; // Throw exception to indicate not to use this constructor
}

// Constructor for the CactusSpawner class
CactusSpawner::CactusSpawner(Renderer *renderer, Game *game, Player *player)
{
	this->renderer = renderer; // Set renderer pointer
	this->game = game;				 // Set game pointer
	this->player = player;		 // Set player pointer
	lastSpawn = 0;						 // Initialize last spawn time
}
