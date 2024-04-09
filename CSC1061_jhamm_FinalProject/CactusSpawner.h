#pragma once

#include <vector>

#include "Cactus.h"
#include "Renderer.h"
#include "Game.h"
#include "Player.h"

using namespace std;

class CactusSpawner
{
private:
	vector<Cactus *> cacti;
	bool enabled = false;
	Renderer *renderer;
	Game *game;
	Player *player;
	long lastSpawn;
	long spawnTick;

public:
	void setEnabled(bool val);
	void update();
	void spawnCactus(Cactus *cactus);
	void deleteCactus(Cactus *cactus);
	void reset();
	long calculateSpawnTick();

	CactusSpawner();
	CactusSpawner(Renderer *renderer, Game *game, Player *player);
};