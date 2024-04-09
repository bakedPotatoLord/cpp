#pragma once
#include <vector>
#include "Sprite.h"
#include "Game.h"


class Renderer {
private:
	Game* game;
	int width;
	int height;
	std::vector<std::vector<char>> mx;
	std::vector<Sprite*> sprites ;

public:
	
	void updateSprites();
	void clearConsole();
	void renderMx();
	void addSprite(Sprite* sprite);
	void destroySprite(Sprite* sprite);
	void setBackground();
	size_t getNumSprites();

	Renderer(Game* game);
	Renderer();
};