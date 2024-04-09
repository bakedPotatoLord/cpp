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
	virtual std::vector<std::vector<char>> getMatrix();

	int getHeight();
	int getWidth();
	bool onGround();

	bool touching(Sprite& other);

	virtual void update();

	Sprite();
	~Sprite();
};