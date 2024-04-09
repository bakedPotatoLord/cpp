#include <iostream>  // Include iostream for input/output operations
#include <stdlib.h>  // Include stdlib.h for standard library functions
#include <Windows.h> // Include Windows.h for Windows-specific functions

#include <chrono>          // Include chrono for time-related functions
#include <thread>          // Include thread for multi-threading support
#include "main.h"          // Include header file for main function declaration
#include "Renderer.h"      // Include header file for the Renderer class
#include "Constants.h"     // Include header file for constants used in the project
#include "Player.h"        // Include header file for the Player class
#include "Cactus.h"        // Include header file for the Cactus class
#include "Game.h"          // Include header file for the Game class
#include "CactusSpawner.h" // Include header file for the CactusSpawner class

using namespace constants; // Using namespace of constants for easy access to constants
using namespace std;       // Using standard namespace for convenience

Player player;                                    // Declare a Player object
Game game;                                        // Declare a Game object
Renderer renderer = Renderer(&game);              // Declare a Renderer object and initialize with the Game object
CactusSpawner spawner{&renderer, &game, &player}; // Declare a CactusSpawner object and initialize with the Renderer, Game, and Player objects

// Function to start the game loop
void gameLoop();

// Main function
int main()
{
    renderer.addSprite(&player); // Add the player to the renderer
    game.resetGame();            // Reset the game state
    gameLoop();                  // Start the game loop
    spawner.setEnabled(true);    // Enable the cactus spawner
    return 0;                    // Return 0 to indicate successful execution
}

// Game loop function
void gameLoop()
{
    while (true)
    {
        this_thread::sleep_for(chrono::milliseconds(refreshPeriod)); // Delay for a specified time
        renderer.clearConsole();                                     // Clear the console screen
        game.printScore();                                           // Print the current score
        renderer.renderMx();                                         // Render the game matrix
        game.printLives();                                           // Print the current number of lives

        if (game.getLives() > 0) // Check if the player is still alive
        {
            player.update();  // Update the player
            spawner.update(); // Update the cactus spawner
            game.tick();      // Increment the tick count
        }
        else
        {
            // Game reset logic
            bool returnPressed = GetKeyState(VK_RETURN) & 0x8000; // Check if the return key is pressed
            if (returnPressed)                                    // If return key is pressed
            {
                game.resetGame();         // Reset the game state
                spawner.reset();          // Reset the cactus spawner
                player.reset();           // Reset the player state
                spawner.setEnabled(true); // Enable the cactus spawner
            }
        };
    }
}
