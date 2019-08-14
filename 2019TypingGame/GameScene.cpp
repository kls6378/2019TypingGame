#include<iostream>
#include<string>
#include<fstream>
#include<time.h>
#include "GameScene.h"
#include "ConsoleFunctions.h"


GameScene::GameScene()
{
	this->player = new Player();
	this->target = new TargetText();
	this->speed = 100;
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
		this->printInput();
		this->countDown();
		this->printTarget();
		this->inputText();
	}
	if (this->player->life == 0) {
		int highScore;
		std::fstream file;
		file.open("highScore.txt");
		file >> highScore;

		system("cls");
		this->player->setCurrentScore(this->player->score);
		
		if (this->player->score > highScore) {
			std::ofstream input("highScore.txt");
			input << this->player->score;
			input.close();
		}
		file.close();
	}
}

void GameScene::printLife() {
	system("cls");
	setTextColor(ColorRed);
	gotoxy(5, 2);
	for (int i = 0; i < player->life; i++) {
		std::cout << "��";
	}
	setTextColor(ColorWhite);
}
void GameScene::printScore() {
	int highScore;
	std::fstream file;
	file.open("highScore.txt");
	file >> highScore;

	gotoxy(55, 2);
	std::cout << "���� ���� : " << player->score << std::endl;
	gotoxy(55, 4);
	std::cout << "�ְ� ���� : " << highScore << std::endl;

	file.close();
}
void GameScene::countDown() {
	for (int i = 3; i > 0; i--) {
		gotoxy(37, 15);
		std::cout << i;
		Sleep(1000);
	}
	gotoxy(37, 15);
	std::cout << " ";
	
}
void GameScene::printTarget() {
	this->text = this->target->getText();
	for (int i = 1; i < 75 - this->text.length(); i++) {
		gotoxy(i - 1, 15);
		std::cout << " ";
		gotoxy(i, 15);
		std::cout << this->text;
		Sleep(this->speed);
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
	std::cout << "����������������������������������������������������������������������������������������������������������������������������������������������������";
}
void GameScene::inputText() {
	int getTimer;
	time_t timer = time(NULL);
	gotoxy(55, 6);
	std::cout << "�ð� üũ��...";
	setCursorType(CursorNormal);
	gotoxy(0, 25);
	std::cout << "���� : ";
	std::getline(std::cin, this->answer);
	setCursorType(CursorInvisible);
	getTimer = time(NULL) - timer;
	gotoxy(55, 6);
	std::cout << "              ";
	gotoxy(55, 6);
	if (getTimer <= 10) {
		setTextColor(ColorLightGreen);
		std::cout << "�ð� : " << getTimer << "��";
		setTextColor(ColorWhite);
	}
	else if (getTimer > 10) {
		setTextColor(ColorRed);
		std::cout << "�ð� : " << getTimer << "��";
		setTextColor(ColorWhite);
	}
	
	gotoxy(30, 15);
	if (this->answer == this->text && getTimer <= 10) {
		setTextColor(ColorLightGreen);
		std::cout << "�����Դϴ�!" << std::endl;
		this->player->score++;
		setTextColor(ColorWhite);
		gotoxy(67, 2);
		std::cout << this->player->score;
		if (this->player->score % 5 == 0 && this->speed > 10) {
			this->speed -= 15;
		}
	}
	else if(this->answer != this->text && getTimer <= 10) {
		setTextColor(ColorRed);
		std::cout << "Ʋ�Ƚ��ϴ�!" << std::endl;
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
	else if (getTimer > 10) {
		setTextColor(ColorRed);
		std::cout << "�ð� �ʰ�!" << std::endl;
		this->player->life--;
		if (this->player->life > 0) {
			gotoxy(7 + this->player->life, 2);
			std::cout << " ";
		}
		else {
			gotoxy(5, 2);
			std::cout << " ";
		}
	}
	this->answer = "";
	Sleep(2000);
	setTextColor(ColorWhite);
}
