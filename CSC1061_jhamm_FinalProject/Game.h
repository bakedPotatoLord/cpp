#pragma once

class Game
{
private:
	int lives = 0;
	long ticks = 0;
	long jumps = 0;

public:
	long getTicks();
	void tick();

	void resetGame();

	int getLives();
	void subtractLife();
	bool IsAlive();
	void printLives();

	void addJump();

	void printScore();

	Game();
	~Game();
};
