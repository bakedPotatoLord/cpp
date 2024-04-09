#pragma once


#include "Sprite.h"
#include <vector>

class Player : public Sprite {
private:
	double vy;
	bool crouching;
	double realY;

	bool downLast = false;
	bool upLast = true;

    std::vector<std::vector<char>> regularMx = {
		{' ', '\\', '/', 'o'},
		{' ', ' ', 'o', '>'},
		{' ', '/', ' ', '\\', '|'},
		{'/', ' ', '~', '(', '*'},
		{'/', '_', '_', '_', '\\'},
		{'/', ' ', ' ', ' ', '\\'}
	};

	std::vector<std::vector<char>> crouchingMx = {
		{' ', '\\', '_', '/', 'o'},
		{' ', '(', ' ', ')', ' '},
		{'<', '_', '_', '_', '_'},
		{'/', ' ', ' ', ' ', ' '},
	};

public:
	Player();

	void reset();

	std::vector<std::vector<char>> getMatrix() override;

	void update() override;

	~Player();
};