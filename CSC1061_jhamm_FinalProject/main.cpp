
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


int main()
{
    Cloud c = Cloud();

    gameLoop();
}

void gameLoop()
{
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(refreshPeriod));

        renderer.updateSprites();

        //renderer.renderMx();
        cout << renderer.getNumSprites();
    }
}


