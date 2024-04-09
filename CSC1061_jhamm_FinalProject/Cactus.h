#pragma once

#include "Sprite.h"
#include <vector>


enum cactusType {
	tiny,
	medium,
	large,
	flying,
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
		{'\\','w','/','w'},
		{'|','H','|','/'},
		{'\\','H','|' ,' '}
	};

	const std::vector<std::vector<char>> flyingCactus = {
		{' ','/','-','\\'},
		{'<','o','^','>'},
		{'\\','-','-' ,'/'}
	};

	
public:
	Cactus();
	Cactus(cactusType);

	~Cactus();

	std::vector<std::vector<char>> getMatrix() override;

	void update() override;
};