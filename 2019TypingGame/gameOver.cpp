#include<iostream>
#include<fstream>
#include "gameOver.h"
#include "Player.h"
#include "ConsoleFunctions.h"


gameOver::gameOver()
{
}


gameOver::~gameOver()
{
}

void gameOver::printTitle() {
	gotoxy(28, 5);
	std::cout << "������������������������������������" << std::endl;
	gotoxy(28, 6);
	std::cout << "��                ��" << std::endl;
	gotoxy(28, 7);
	std::cout << "��    ���� ����   ��" << std::endl;
	gotoxy(28, 8);
	std::cout << "��                ��" << std::endl;
	gotoxy(28, 9);
	std::cout << "������������������������������������" << std::endl;
}

void gameOver::printScore() {
	int highScore;
	std::fstream file;
	file.open("highScore.txt");
	file >> highScore;

	gotoxy(31, 14);
	std::cout << "���� ���� : " << Player().currentScore;
	gotoxy(31, 16);
	std::cout << "�ְ� ���� : "<<highScore;

	file.close();
	gotoxy(0, 29);
	Sleep(3000);
}