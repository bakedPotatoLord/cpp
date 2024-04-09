#include "Game.h"
#include <iostream>

long Game::getTicks()
{
	return ticks;
}

void Game::tick()
{
	ticks++;
}

void Game::resetGame()
{
	lives = 3;
}

int Game::getLives()
{
	return lives;
}

void Game::subtractLife()
{
	lives--;
}

bool Game::IsAlive()
{
	return lives > 0;
}

void Game::printLives()
{
	std::cout << "lives: " << lives << std::endl;
}

Game::Game()
{
	resetGame();
}

Game::~Game()
{
}
