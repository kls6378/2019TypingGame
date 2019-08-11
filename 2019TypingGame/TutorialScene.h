#pragma once
#include<string>
class TutorialScene
{
public:
	std::string content;
	TutorialScene();
	~TutorialScene();

	void printTitle();
	void printContent();
	void printEnter();
};

