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

void gotoxy(int x, int y);   //Ŀ�� ��ġ �̵�

typedef enum CursorType //�ٲ� Ŀ���� Ÿ��
{
	CursorInvisible,//Ŀ�� �����
	CursorInput, //Ŀ�� �Է¸��
	CursorNormal //�Ϲ�Ŀ��
}CursorType;

void setCursorType(CursorType type); //Ŀ�� �ٲٱ�
CursorType getCursorType();          //Ŀ�� ��� ������

typedef enum Color // ��
{
	ColorBlack = 0x0,   // ������
	ColorBlue = 0x1,   // �Ķ���
	ColorGreen = 0x2,   // �ʷϻ�
	ColorSkyblue = 0x3,   // ����
	ColorRed = 0x4,   // ������
	ColorPurple = 0x5,   // ���ֻ�
	ColorYellow = 0x6,   // �����
	ColorWhite = 0x7,   // ���
	ColorGray = 0x8,   // ȸ��
	ColorLightBlue = 0x9,   // ���� �Ķ���
	ColorLightGreen = 0xA,   // ���� �ʷϻ�
	ColorLightSkyblue = 0xB,   // ���� ����
	ColorLightRed = 0xC,   // ���� ������
	ColorLightPurple = 0xD,   // ���� ���ֻ�
	ColorLightYellow = 0xE,   // ���� �����
	ColorLightWhite = 0xF,   // ���� ���
}Color;

void setTextColor(Color color); //�ؽ�Ʈ ������
Color getTextColor(); //���� ���

void setBackgroundColor(Color color); //���� ����
Color getBackgroundColor(); //���� ���

void setSize(int cols, int lines); //�ܼ� â ũ�� ����

void setTitle(const char *title);//Ÿ��Ʋ ����
void getTitle(char *out, int nSize); //Ÿ��Ʋ ���

void clearConsole();	//ȭ�� �����