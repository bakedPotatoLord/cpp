#pragma once

class Game
{
private:
	int lives = 0;
	long ticks = 0;
	long jumps = 0;
public:
	void tick();
	void resetGame();
	void subtractLife();
	void printLives();
	void addJump();
	void printScore();

	long getTicks();
	int getLives();
	bool IsAlive();

	Game();
	~Game();
};
