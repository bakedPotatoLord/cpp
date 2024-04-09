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
	//try to spawn new cacti
	if (spawnTick <= game->getTicks() ){
		Cactus* cactus = new Cactus();

		cacti.push_back(cactus);
		renderer->addSprite(cactus);


		spawnTick = calculateSpawnTick();
	}

	//update living cacti
	for (auto cactus : cacti) {
		cactus->update();
	}

	//delete off-screen cacti
	for (auto cactus : cacti) {
		if (cactus->getX() < 0 ) {
			//delete in renderer
			renderer->destroySprite(cactus);

			//delete in spawner
			for (int i = 0; i < cacti.size(); i++) {
				if (cacti[i] == cactus) {
					cacti[i] = cacti.back();
					cacti.pop_back();
				}
			}

		}
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

CactusSpawner::CactusSpawner(Renderer* renderer, Game* game)
{
	this->renderer = renderer;
	this->game = game;
	lastSpawn = 0;
}
