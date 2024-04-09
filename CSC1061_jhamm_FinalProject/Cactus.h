#pragma once

#include "Sprite.h"
#include <vector>

enum cactusType {
	small,
	medium,
	large,
	none
};

class Cactus : public Sprite {
private:
	cactusType type;

	const std::vector<std::vector<char>> smallCactus = {
		{'\\','|'},
		{' ','H',},
		{' ','H',}
	};

	const std::vector<std::vector<char>> midCactus = {
		{'w','w','/'},
		{'W','H',' '},
		{'\\','H',' ' }
	};

	const std::vector<std::vector<char>> largeCactus = {
		{'w','w','/'},
		{'W','H','|'},
		{'\\','H','|' }
	};


	
	
public:
	Cactus();
	Cactus(cactusType);

	~Cactus();

	void update() override;
};