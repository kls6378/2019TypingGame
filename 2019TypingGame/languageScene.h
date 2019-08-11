#pragma once
class languageScene
{
public:
	std::string language = "korean";

	languageScene();
	~languageScene();
	
	void printTitle();
	void printContent();
	void select();
};

