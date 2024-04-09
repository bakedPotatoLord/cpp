#pragma once

#include <vector>

#include "Cactus.h"
#include "Renderer.h"
#include "Game.h"

using namespace std;

class CactusSpawner {
private:
	vector<Cactus*> cacti;
	bool enabled = false;
	Renderer* renderer;
	Game* game;
	long lastSpawn;
	long spawnTick;
	
public:
	void setEnabled(bool val);
	void update();

	long calculateSpawnTick();

	CactusSpawner();
	CactusSpawner(Renderer* renderer,Game* game);


};