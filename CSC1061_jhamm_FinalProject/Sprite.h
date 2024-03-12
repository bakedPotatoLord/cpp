#pragma once
#include <vector>



class Sprite {
protected:
	int x;
	int y;
	std::vector<std::vector<char>> spriteMx;

	int getX();
	int getY();
	std::vector<std::vector<char>> getMatrix();

	virtual void update() = 0;

	Sprite();
	~Sprite();
};