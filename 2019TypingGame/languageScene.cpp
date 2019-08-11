#include<iostream>
#include "languageScene.h"
#include"ConsoleFunctions.h"


languageScene::languageScene()
{
}


languageScene::~languageScene()
{
}

void languageScene::printTitle() {
	system("cls");
	gotoxy(5, 2);
	std::cout << "┌────────────────┐" << std::endl;
	gotoxy(5, 3);
	std::cout << "│    언어 선택   │" << std::endl;
	gotoxy(5, 4);
	std::cout << "└────────────────┘" << std::endl;
}

void languageScene::printContent() {
	gotoxy(6, 12);
	std::cout << "방향키를 이용하여 한글과 영어 중 원하시는 언어를 선택해주세요..." << std::endl;
	gotoxy(7, 14);
	std::cout << "->";
	gotoxy(9, 14);
	std::cout << "한글";
	gotoxy(9, 16);
	std::cout << "영어";
}

void languageScene::select() {
	setCursorType(CursorNormal);
	int key;
	while (1) {
		if (_kbhit()) {
			key = _getch();
			switch (key) {
			case 72:
				gotoxy(7, 16);
				std::cout << "  ";
				gotoxy(7, 14);
				std::cout << "->";
				this->language = "korean";
				break;
			case 80:
				gotoxy(7, 14);
				std::cout << "  ";
				gotoxy(7, 16);
				std::cout << "->";
				this->language = "english";
				break;
			}
			if (key == 13) {
				gotoxy(7, 18);
				break;
			}
		}
	}
}