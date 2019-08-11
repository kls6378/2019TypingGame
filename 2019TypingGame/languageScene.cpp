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
	std::cout << "������������������������������������" << std::endl;
	gotoxy(5, 3);
	std::cout << "��    ��� ����   ��" << std::endl;
	gotoxy(5, 4);
	std::cout << "������������������������������������" << std::endl;
}

void languageScene::printContent() {
	gotoxy(6, 12);
	std::cout << "����Ű�� �̿��Ͽ� �ѱ۰� ���� �� ���Ͻô� �� �������ּ���..." << std::endl;
	gotoxy(7, 14);
	std::cout << "->";
	gotoxy(9, 14);
	std::cout << "�ѱ�";
	gotoxy(9, 16);
	std::cout << "����";
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