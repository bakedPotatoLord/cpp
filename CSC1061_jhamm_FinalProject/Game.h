#pragma once

class Game {
private:
	int lives = 0;
	long ticks = 0;
public:

	long getTicks();
	void tick();

	void resetGame();

	int getLives();
	void subtractLife();
	bool IsAlive();
	void printLives();

	Game();
	~Game();



};
