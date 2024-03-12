#include "Cloud.h"

#include "Constants.h"

using namespace constants;

Cloud::Cloud() : Sprite()
{
	x = screenWidth;
	y = screenHeight / 4;

	spriteMx = {
		{' ','0','0','0',' '},
		{'0',' ',' ',' ','0'},
		{' ','0','0','0',' '}
	};
}

void Cloud::update()
{
	x--;
}
