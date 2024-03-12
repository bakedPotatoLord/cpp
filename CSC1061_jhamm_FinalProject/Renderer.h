#pragma once
#include <vector>
#include "Sprite.h"


class Renderer {
private:
	int width;
	int height;
	double refreshPeriod;
	std::vector<std::vector<char>> mx;
	std::vector<Sprite*> sprites ;

public:
	

	void renderMx();

	void addSprite(Sprite* sprite);

	void destroySprite(Sprite* sprite);

	int getNumSprites();

	Renderer();
};