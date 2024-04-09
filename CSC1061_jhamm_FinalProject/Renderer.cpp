#include "Renderer.h"
#include <iostream>
#include "Constants.h"

using namespace std;
using namespace constants;

void Renderer::updateSprites()
{
	for (auto sprite : sprites)
		sprite->update();
}

void Renderer::clearConsole() { system("cls"); }

void Renderer::renderMx()
{
	if (game->getLives() <= 0)
	{
		cout << "Game Over! Press Enter to try again." << endl;
	}
	else
	{
		setBackground();
		for (auto sprite : sprites)
		{
			for (size_t i = 0; i < sprite->getMatrix().size(); i++)
			{
				for (size_t j = 0; j < sprite->getMatrix()[i].size(); j++)
				{
					auto sy = sprite->getY() + i;
					auto sx = sprite->getX() + j;
					if (sy >= 0 && sy < screenHeight && sx >= 0 && sx < screenWidth)
						mx[sy][sx] = sprite->getMatrix()[i][j];
				}
			}
		}

		for (auto &row : mx)
		{
			for (auto c : row)
			{
				cout << c;
			}
			cout << endl;
		}
	}
}

void Renderer::addSprite(Sprite *sprite)
{
	sprites.push_back(sprite);
	getNumSprites();
}

void Renderer::destroySprite(Sprite *sprite)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		if (sprites[i] == sprite)
		{
			sprites[i] = sprites.back();
			sprites.pop_back();
		}
	}
}

void Renderer::setBackground()
{
	for (int i = 0; i < screenHeight; i++)
	{
		for (int j = 0; j < screenWidth; j++)
		{
			if (i >= groundHeight)
				mx[i][j] = ((i + j) % 2 == 0) ? '*' : '%';
			else
				mx[i][j] = ' ';
		}
	}
}

size_t Renderer::getNumSprites()
{

	size_t s = sprites.size();
	return s;
}

Renderer::Renderer(Game *game)
{
	height = screenHeight;
	width = screenWidth;
	sprites = vector<Sprite *>();
	mx = vector<vector<char>>(screenHeight, vector<char>(screenWidth));
	setBackground();
	this->game = game;
}

Renderer::Renderer() { throw "do not use this constuctor"; }
