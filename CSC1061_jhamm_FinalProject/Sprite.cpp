
#include "Sprite.h"
#include "Renderer.h"
#include "Constants.h"
#include <vector>

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

Sprite::Sprite()
{
	renderer.addSprite(this);
	x = 0;
	y = 0;
	spriteMx = {};
}
Sprite::~Sprite()
{
	renderer.destroySprite(this);
};