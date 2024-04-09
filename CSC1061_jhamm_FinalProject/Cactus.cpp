#include "Cactus.h"

#include "Constants.h"
#include <iostream>

using namespace constants;



Cactus::Cactus(): Sprite()
{
	x = screenWidth;
	

	y = groundHeight- getHeight();
	
}

Cactus::Cactus(cactusType type)
{
	this->type = type;
}

Cactus::~Cactus()
{
	for (auto &row : spriteMx) {
		delete &row;
	}
}

void Cactus::update()
{
	Sprite::update();
	x--;
}
