
#include <iostream>
#include <stdlib.h>

#include <chrono>
#include <thread>
#include "main.h"
#include "Renderer.h"
#include "Constants.h"

using namespace constants;
using namespace std;


int main()
{




    gameLoop();
}

void gameLoop()
{
    while (true) {
        this_thread::sleep_for(chrono::milliseconds(500));

       renderer.renderMx();


    }
}


