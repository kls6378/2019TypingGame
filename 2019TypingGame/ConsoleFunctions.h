#pragma once
#include <Windows.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <sstream>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

void gotoxy(int x, int y);   //커서 위치 이동

typedef enum CursorType //바꿀 커서의 타입
{
	CursorInvisible,//커서 숨기기
	CursorInput, //커서 입력모드
	CursorNormal //일반커서
}CursorType;

void setCursorType(CursorType type); //커서 바꾸기
CursorType getCursorType();          //커서 모양 얻어오기

typedef enum Color // 색
{
	ColorBlack = 0x0,   // 검정색
	ColorBlue = 0x1,   // 파랑색
	ColorGreen = 0x2,   // 초록색
	ColorSkyblue = 0x3,   // 옥색
	ColorRed = 0x4,   // 빨간색
	ColorPurple = 0x5,   // 자주색
	ColorYellow = 0x6,   // 노랑색
	ColorWhite = 0x7,   // 흰색
	ColorGray = 0x8,   // 회색
	ColorLightBlue = 0x9,   // 연한 파랑색
	ColorLightGreen = 0xA,   // 연한 초록색
	ColorLightSkyblue = 0xB,   // 연한 옥색
	ColorLightRed = 0xC,   // 연한 빨간색
	ColorLightPurple = 0xD,   // 연한 자주색
	ColorLightYellow = 0xE,   // 연한 노랑색
	ColorLightWhite = 0xF,   // 밝은 흰색
}Color;

void setTextColor(Color color); //텍스트 색변경
Color getTextColor(); //배경색 얻기

void setBackgroundColor(Color color); //배경색 변경
Color getBackgroundColor(); //배경색 얻기

void setSize(int cols, int lines); //콘솔 창 크기 변경

void setTitle(const char *title);//타이틀 설정
void getTitle(char *out, int nSize); //타이틀 얻기

void clearConsole();	//화면 지우기