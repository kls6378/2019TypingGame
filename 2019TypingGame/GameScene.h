#pragma once
#include "Player.h"
#include "TargetText.h"
#include <string>
class GameScene
{
public:
	Player* player;
	TargetText* target;
	int speed;
	std::string text;
	std::string answer;
	GameScene();
	~GameScene();
	void GAME();
	void printLife();
	void printScore();
	void countDown();
	void printTarget();
	void printInput();
	void inputText();
};

