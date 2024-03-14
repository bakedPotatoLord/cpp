
#include <iostream>
#include <stdlib.h>

#include <chrono>
#include <thread>
#include "main.h"
#include "Renderer.h"
#include "Constants.h"
#include "Cloud.h"

using namespace constants;
using namespace std;

Cloud c = Cloud();

int main()
{
    renderer.addSprite(&c);

    gameLoop();
}

void gameLoop()
{
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(refreshPeriod));


        renderer.renderMx();
        renderer.getNumSprites();

        c.update();


    }
}


