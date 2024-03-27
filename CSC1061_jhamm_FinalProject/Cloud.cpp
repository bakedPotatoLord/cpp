#include "Cloud.h"

#include "Constants.h"
#include <iostream>

using namespace constants;
using namespace std;

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
	if (x == -5) x = screenWidth;
	else x--;
	cout << "cloud update" << endl;
	cout <<"x: " << x << " y: " << y << endl;
}
