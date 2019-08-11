#include "Player.h"

int Player::currentScore = 0;

Player::Player()
{
	this->life = 3;
	this->score = 0;
}


Player::~Player()
{
}

void Player::setCurrentScore(int score) {
	currentScore = score;
}
