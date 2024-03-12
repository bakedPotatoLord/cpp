
#include "Sprite.h"
#include "Renderer.h"
#include "Constants.h"
#include <vector>
#include <iostream>

using namespace std;
using namespace constants;

int Sprite::getX()
{
	return x;
}

int Sprite::getY()
{
	return y;
}

vector<vector<char>> Sprite::getMatrix()
{
	return spriteMx;
}

void Sprite::update()
{
}

Sprite::Sprite()
{
	cout << "sprite constructor";
	renderer.addSprite(this);
	x = 0;
	y = 0;
	spriteMx = {};
}
Sprite::~Sprite()
{
	cout << "sprite destroyed";
	renderer.destroySprite(this);
};