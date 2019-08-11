#pragma once
class Player
{
public:
	static int currentScore;
	int life;
	int score;

	Player();
	~Player();

	static void setCurrentScore(int score);
};

