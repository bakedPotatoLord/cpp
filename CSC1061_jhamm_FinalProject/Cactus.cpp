#include "Cactus.h"

#include "Constants.h"
#include <iostream>

using namespace constants;



Cactus::Cactus(): Sprite()
{
	Cactus(small);
}

Cactus::Cactus(cactusType type)
{
	x = screenWidth;
	y = groundHeight - getHeight();
	this->type = type;

	if (type == flying) {
		y -= 5;
	}
}

Cactus::~Cactus()
{
	for (auto &row : spriteMx) {
		delete &row;
	}
}

std::vector<std::vector<char>> Cactus::getMatrix()
{
	switch (type)
	{
	case tiny:
		return smallCactus;
	case medium:
		return midCactus;
	case large:
		return largeCactus;
	case flying:
		return flyingCactus;
	};

}

void Cactus::update()
{
	Sprite::update();
	x--;
}
