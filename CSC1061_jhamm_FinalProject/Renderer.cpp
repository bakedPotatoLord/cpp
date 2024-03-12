#include "Renderer.h"
#include <iostream>
#include "Constants.h"

using namespace std;
using namespace constants;


 void Renderer::renderMx()
{
	
	system("cls");
	for (auto row : mx) {
		for (auto c : row) {
			cout << c;
		}
		cout << endl;
	}
}

void Renderer::addSprite(Sprite* sprite)
{
	sprites.push_back(sprite);
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

int Renderer::getNumSprites()
{
	return  (int) sprites.size();
}

Renderer::Renderer()
{
	sprites = {};
	mx = vector<vector<char>>(screenHeight, vector<char>(screenWidth));


	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			if (i < (screenHeight/2)) mx[i][j] = ' ';
			else mx[i][j] = ((i + j) % 2 == 0) ? '*' : '%';
		}
	}

}

