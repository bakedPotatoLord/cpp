
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

#include <chrono>
#include <thread>
#include "main.h"
#include "Renderer.h"
#include "Constants.h"
#include "Player.h"
#include "Cactus.h"
#include "Game.h"
#include "CactusSpawner.h"

using namespace constants;
using namespace std;

Player player;
Game game;
Renderer renderer = Renderer(&game);
CactusSpawner spawner{&renderer, &game, &player};

int main()
{
    renderer.addSprite(&player);
    game.resetGame();
    gameLoop();
    spawner.setEnabled(true);
}

void gameLoop()
{
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(refreshPeriod));
        renderer.clearConsole();
        game.printScore();
        renderer.renderMx();
        game.printLives();

        if (game.getLives() > 0)
        {
            player.update();
            spawner.update();
            game.tick();
        }
        else
        {
            // game reset logic
            bool returnPressed = GetKeyState(VK_RETURN) & 0x8000;
            if (returnPressed)
            {
                game.resetGame();
                spawner.reset();
                player.reset();
                spawner.setEnabled(true);
            }
        };
    }
}
