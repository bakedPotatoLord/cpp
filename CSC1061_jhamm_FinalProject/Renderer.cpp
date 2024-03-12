#include "Renderer.h"
#include <iostream>
#include "Constants.h"

using namespace std;
using namespace constants;


void Renderer::updateSprites()
{
	for (auto sprite : sprites) {
		sprite->update();
		cout << "updating sprite " << sprite << endl;;
	};
}

void Renderer::renderMx()
{
	
	system("cls");
	for (auto& row : mx) {
		for (auto c : row) {
			cout << c;
		}
		cout << endl;
	}
}

void Renderer::addSprite(Sprite* sprite)
{
	cout << "sprite add: " << sprite;
	sprites.push_back(sprite);
	getNumSprites();
}

void Renderer::destroySprite(Sprite* sprite)
{
	for (int i = 0; i < sprites.size(); i++) {
		if (sprites[i] == sprite) {
			sprites[i] = sprites.back();
			sprites.pop_back();
		}
	}
}

 size_t Renderer::getNumSprites()
{

	size_t s = sprites.size();
	cout << "size: " << s;
	return s;
}

Renderer::Renderer()
{
	height = screenHeight;
	width = screenWidth;

	sprites = vector<Sprite*>(5);
	mx = vector<vector<char>>(screenHeight, vector<char>(screenWidth));


	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			if (i < (screenHeight/2)) mx[i][j] = ' ';
			else mx[i][j] = ((i + j) % 2 == 0) ? '*' : '%';
		}
	}

}

