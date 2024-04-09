#include "CactusSpawner.h"
#include <iostream>

void CactusSpawner::setEnabled(bool val)
{
	enabled = val;
	lastSpawn = game->getTicks();
	spawnTick = lastSpawn;
}

void CactusSpawner::update()
{
	// try to spawn new cacti
	if (spawnTick <= game->getTicks())
	{
		cactusType type = (cactusType)(rand() % 4);
		Cactus *cactus = new Cactus(type);

		spawnCactus(cactus);
		spawnTick = calculateSpawnTick();
	}

	// update living cacti
	for (auto cactus : cacti)
	{
		cactus->update();
	}
	// iterate over cacti
	for (auto cactus : cacti)
	{
		// delete off-screen cacti
		if (cactus->getX() < 0)
		{
			deleteCactus(cactus);
			game->addJump();
			continue;
		}

		// handle collision
		if (cactus->touching(*player))
		{
			deleteCactus(cactus);
			game->subtractLife();
		}
	}
}

void CactusSpawner::spawnCactus(Cactus *cactus)
{
	cacti.push_back(cactus);
	renderer->addSprite(cactus);
}

void CactusSpawner::deleteCactus(Cactus *cactus)
{
	// delete in renderer
	renderer->destroySprite(cactus);

	// delete in spawner
	for (int i = 0; i < cacti.size(); i++)
	{
		if (cacti[i] == cactus)
		{
			cacti[i] = cacti.back();
			cacti.pop_back();
		}
	}
}

void CactusSpawner::reset()
{
	for (auto cactus : cacti)
	{
		deleteCactus(cactus);
	}
}

long CactusSpawner::calculateSpawnTick()
{
	long tick = game->getTicks();
	return tick + 20 + (rand() % 20);
}

CactusSpawner::CactusSpawner()
{
	throw "don't use this constructor";
}

CactusSpawner::CactusSpawner(Renderer *renderer, Game *game, Player *player)
{
	this->renderer = renderer;
	this->game = game;
	this->player = player;
	lastSpawn = 0;
	// spawnTick = 0;
}
