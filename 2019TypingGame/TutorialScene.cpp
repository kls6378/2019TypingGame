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
	std::cout << "������������������������������������" << std::endl;
	gotoxy(5, 3);
	std::cout << "��    ���� ���   ��" << std::endl;
	gotoxy(5, 4);
	std::cout << "������������������������������������" << std::endl;
}

void TutorialScene::printContent() {
	this->content = "\t- Ÿ���θ��� �̿��� �����Դϴ�\n\t- ȭ�鿡�� ���ƿ��� ���ڵ��� ����Ͽ� Ÿ�����ϼ���!\n\t- Ŭ��� �ϸ� �� ���� ���̵��� ���� �ö� �� �Դϴ�.\n\n\t- ���� : �Է�\n\t- Enter : �Է°� ����";
	gotoxy(0, 12);
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