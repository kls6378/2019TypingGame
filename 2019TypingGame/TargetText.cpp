#include<iostream>
#include "TargetText.h"
#include<time.h>

char TargetText::language = 'k';

TargetText::TargetText()
{
}


TargetText::~TargetText()
{
}

void TargetText::setLanguage(char l) {
	this->language = l;
}

std::string TargetText::getText() {
	if (this->language == 'k') {
		srand(time(0));
		int random = rand() % 50;
		return this->koreanText[random];
	}
	else if(this->language == 'e') {
		srand(time(0));
		int random = rand() % 50;
		return this->englishText[random];
	}
}