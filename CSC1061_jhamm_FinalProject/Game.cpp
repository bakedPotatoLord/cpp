#include "Game.h"
#include <iostream>

using namespace std;

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
	jumps = 0;
	ticks = 0;
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
	cout << "lives: " << lives << endl;
}

void Game::addJump()
{
	jumps++;
}

void Game::printScore()
{
	cout << "score: " << (ticks + (jumps * 50)) << endl;
}

Game::Game()
{
	resetGame();
}

Game::~Game()
{
}
