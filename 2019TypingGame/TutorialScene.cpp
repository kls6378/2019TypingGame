#include<iostream>
#include "TutorialScene.h"
#include "ConsoleFunctions.h"

TutorialScene::TutorialScene()
{
}


TutorialScene::~TutorialScene()
{
}

void TutorialScene::printTitle() {
	system("cls");
	gotoxy(5, 2);
	std::cout << "┌────────────────┐" << std::endl;
	gotoxy(5, 3);
	std::cout << "│    게임 방법   │" << std::endl;
	gotoxy(5, 4);
	std::cout << "└────────────────┘" << std::endl;
}

void TutorialScene::printContent() {
	this->content = "\t- 타이핑만을 이용한 게임입니다\n\n\t- 한글과 영어중 하나를 선택하여 플레이할 수 있습니다.\n\n\t- 화면에서 날아오는 글자들을 기억하여 타이핑하세요!\n\n\t- 클리어를 하면 할 수록 속도는 점점 올라갈 것 입니다.\n\n\t- 생명은 총 3개를 가지고 있습니다.\n\n\t- 최고 점수를 향해 도전하세요!\n\n\n\n\t- 자판 : 입력\n\n\t- Enter : 입력값 전송";
	gotoxy(0, 6);
	std::cout << this->content << std::endl;
}

void TutorialScene::printEnter() {
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