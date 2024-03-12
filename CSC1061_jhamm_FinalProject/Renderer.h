#pragma once
#include <vector>
#include "Sprite.h"


class Renderer {
private:
	int width;
	int height;
	std::vector<std::vector<char>> mx;
	std::vector<Sprite*> sprites ;

public:
	
	void updateSprites();

	void renderMx();

	void addSprite(Sprite* sprite);

	void destroySprite(Sprite* sprite);

	size_t getNumSprites();

	Renderer();
};