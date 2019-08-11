#include<iostream>
#include "Screen.h"
#include "MainScene.h"
#include "TutorialScene.h"
#include "languageScene.h"
#include "GameScene.h"
#include "TargetText.h"
#include "ConsoleFunctions.h"

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

	GameScene g;
	g.GAME();

	return 0;
}