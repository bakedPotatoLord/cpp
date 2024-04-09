#pragma once
#include <vector>

class Sprite
{
protected:
	int x;
	int y;
	std::vector<std::vector<char>> spriteMx;

public:
	int getX();
	int getY();
	int getHeight();
	int getWidth();

	bool onGround();
	bool touching(Sprite &other);

	virtual std::vector<std::vector<char>> getMatrix();
	virtual void update();

	Sprite();
	~Sprite();
};