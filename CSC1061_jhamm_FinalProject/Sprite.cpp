
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
	cout << "base sprite update" << endl;
}

Sprite::Sprite()
{
	cout << "sprite constructor";
	x = 0;
	y = 0;
}
Sprite::~Sprite()
{
	cout << "sprite destroyed";
};