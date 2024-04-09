
#include <iostream>
#include <stdlib.h>

#include <chrono>
#include <thread>
#include "main.h"
#include "Renderer.h"
#include "Constants.h"
#include "Cloud.h"
#include "Player.h"
#include "Cactus.h"
#include "Game.h"
#include "CactusSpawner.h"

using namespace constants;
using namespace std;

//Cactus* cactus = new Cactus();
Player* player = new Player();

Renderer renderer = Renderer();
Game game;

CactusSpawner spawner{ &renderer,&game };

int main()
{
    renderer.addSprite(player);

    game.resetGame();
    gameLoop();
    spawner.setEnabled(true);
}

void gameLoop()
{
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(refreshPeriod));


        renderer.renderMx();
        game.printLives();
        renderer.getNumSprites();

        player->update();
        spawner.update();

        game.tick();
    }
}


