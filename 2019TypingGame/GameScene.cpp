#include<iostream>
#include<string>
#include "GameScene.h"
#include "ConsoleFunctions.h"


GameScene::GameScene()
{
	this->player = new Player();
	this->target = new TargetText();
	this->time = 10;
}


GameScene::~GameScene()
{
	delete player;
	delete target;
}

void GameScene::GAME() {
	for (int i = 0; this->player->life != 0; i++) {
		this->printLife();
		this->printScore();
		this->printTime();
		this->printInput();
		this->printTarget();
		this->inputText();
	}
	if (this->player->life == 0) {

	}
}

void GameScene::printLife() {
	system("cls");
	setTextColor(ColorRed);
	gotoxy(5, 2);
	for (int i = 0; i < player->life; i++) {
		std::cout << "♥";
	}
	setTextColor(ColorWhite);
}
void GameScene::printScore() {
	gotoxy(55, 2);
	std::cout << "현재 점수 : " << player->score << std::endl;
}
void GameScene::printTime() {
	gotoxy(55, 4);
	std::cout << "제한 시간 : " << this->time << std::endl;
}
void GameScene::timeStart() {
	for (int i = 10; i > 0; i--) {
		gotoxy(67, 4);
		std::cout << "  ";
		std::cout << i;
		Sleep(1000);
	}
}
void GameScene::printTarget() {
	this->text = this->target->getText();
	for (int i = 1; i < 75 - this->text.length(); i++) {
		gotoxy(i - 1, 15);
		std::cout << " ";
		gotoxy(i, 15);
		std::cout << this->text;
		Sleep(100);
	}
	gotoxy(74 - this->text.length(), 15);
	for (int k = 0; k < this->text.length(); k++) {
		std::cout << " ";
	}
	while (_kbhit())
	{
		_getch();
	}
}
void GameScene::printInput() {
	gotoxy(0, 23);
	std::cout << "──────────────────────────────────────────────────────────────────────────";
}
void GameScene::inputText() {
	setCursorType(CursorNormal);
	gotoxy(0, 25);
	std::cout << "정답 : ";
	std::getline(std::cin, this->answer);
	setCursorType(CursorInvisible);
	gotoxy(30, 15);
	if (this->answer == this->text) {
		setTextColor(ColorLightGreen);
		std::cout << "정답입니다!" << std::endl;
		this->player->score++;
		setTextColor(ColorWhite);
		gotoxy(67, 2);
		std::cout << this->player->score;
	}
	else {
		setTextColor(ColorRed);
		std::cout << "틀렸습니다!" << std::endl;
		this->player->life--;
		if (this->player->life > 0) {
			gotoxy(7+this->player->life, 2);
			std::cout << " ";
		}
		else {
			gotoxy(5, 2);
			std::cout << " ";
		}
	}
	this->answer = "";
	Sleep(1000);
	setTextColor(ColorWhite);
}
