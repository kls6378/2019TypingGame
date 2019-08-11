#include<iostream>
#include<fstream>
#include "MainScene.h"
#include "ConsoleFunctions.h"



MainScene::MainScene()
{
}


MainScene::~MainScene()
{
}

void MainScene::printTitle() {
	gotoxy(24, 5);
	std::cout << "┌───────────────────────┐" << std::endl;
	gotoxy(24, 6);
	std::cout << "│    자나 깨나 타이핑   │" << std::endl;
	gotoxy(24, 7);
	std::cout << "└───────────────────────┘" << std::endl;
}

void MainScene::printScore() {
	int highScore;
	std::fstream file;
	file.open("highScore.txt");
	file >> highScore;
	gotoxy(30, 15);
	std::cout << "최고점수 : "<< highScore << std::endl;
	file.close();
}

void MainScene::printEnter() {
	setCursorType(CursorInvisible);
	std::string temp;
	gotoxy(28, 25);
	std::cout << "Press Enter Key..." << std::endl;
	while (1) {
		if (_kbhit()) {
			if (_getch() == 13) {
				break;
			}
			else {
				continue;
			}
		}
	}
}
