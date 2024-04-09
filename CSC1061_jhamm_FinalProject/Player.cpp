
#include "Player.h"
#include "Constants.h"

#include <Windows.h>
#include <vector>
#include <iostream>

using namespace std;

Player::Player() : Sprite()
{
	reset();
}

void Player::reset()
{
	x = 4;
	y = 6;
	crouching = false;
	vy = 0;
	realY = 0;
}


vector<vector<char>> Player::getMatrix() {
	return crouching ?
		crouchingMx :
		regularMx;
}

void Player::update()
{
	Sprite::update();


	//gravity logic

	if (!onGround()) {
		//if in air
		vy += constants::gravityAccel;
	}
	else {
		//if on ground
		vy = min(vy,0);
		realY = constants::groundHeight - getHeight();
	}
	realY += vy;
	y = (int) round(realY);

	//key logic
	bool upPressed = GetKeyState(VK_UP) & 0x8000;
	if (upPressed && !upLast && onGround()) {
		cout << "up press" << endl;
		vy = -1.5;
	}
	upLast = upPressed;
	bool downPressed = GetKeyState(VK_DOWN) & 0x8000;
	crouching = downPressed;

}

Player::~Player()
{
}
