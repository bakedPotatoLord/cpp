#pragma once
#include <vector>



class Sprite {
protected:
	int x;
	int y;
	std::vector<std::vector<char>> spriteMx;

public:
	int getX();
	int getY();
	std::vector<std::vector<char>> getMatrix();

	void update();

	Sprite();
	~Sprite();
};