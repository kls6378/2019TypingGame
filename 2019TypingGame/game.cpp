#include<iostream>
#include "Screen.h"
#include "MainScene.h"
#include "TutorialScene.h"
#include "languageScene.h"

int main() {
	Screen s;
	MainScene m;
	TutorialScene t;
	languageScene l;
	
	m.printTitle();
	m.printScore();
	m.printEnter();
	t.printTitle();
	t.printContent();
	t.printEnter();
	l.printTitle();
	l.printContent();
	l.select();
	system("cls");
	std::cout << l.language << std::endl;


	return 0;
}