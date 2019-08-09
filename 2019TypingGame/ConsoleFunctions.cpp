#include "ConsoleFunctions.h"

static CursorType cursorType;

HANDLE getHandle(void) // �ܼ�â �ڵ��� ����
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

void gotoxy(int x, int y) // Ŀ�� �̵�
{
	COORD dwCursorPosition = { x, y };
	SetConsoleCursorPosition(getHandle(), dwCursorPosition);
}

void setCursorType(CursorType type) // Ŀ��Ÿ�Լ���
{
	CONSOLE_CURSOR_INFO curInfo;
	switch (cursorType = type)
	{
	case CursorInvisible: // �Ⱥ���
		curInfo.dwSize = 1;
		curInfo.bVisible = FALSE;
		break;

	case CursorInput: // �Է¸��
		curInfo.dwSize = 100;
		curInfo.bVisible = TRUE;
		break;

	case CursorNormal: // �Ϲ�
		curInfo.dwSize = 20;
		curInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(getHandle(), &curInfo);
}

CursorType getCursorType() // Ŀ��Ÿ�� ���
{
	return cursorType;
}

void setTextColor(Color color) // �ؽ�Ʈ�÷� ����
{
	SetConsoleTextAttribute(getHandle(), getBackgroundColor() * 16 + color);
}

Color getTextColor() // �ؽ�Ʈ �÷� ���
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	GetConsoleScreenBufferInfo(getHandle(), &bufInfo);
	return (Color)(bufInfo.wAttributes % 16);
}

void setBackgroundColor(Color color) // ��� �� ����
{
	SetConsoleTextAttribute(getHandle(), color * 16 + getTextColor());
}

Color getBackgroundColor(void) // ��� �� ���
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo = { 0, };
	GetConsoleScreenBufferInfo(getHandle(), &bufInfo);
	return (Color)(bufInfo.wAttributes / 16);
}

void setSize(int cols, int lines) // �ܼ� â ũ�� ����
{
	std::ostringstream s;
	std::string buf;
	s << "mode con: cols=" << cols << " lines=" << lines;
	buf = s.str();
	std::cout << buf << std::endl;
	system(buf.c_str());
}

void setTitle(const char *title) // Ÿ��Ʋ����
{
	SetConsoleTitleA(title);
}

void getTitle(char *out, int nSize) // Ÿ��Ʋ���
{
	GetConsoleTitleA(out, nSize);
}

void clearConsole() //�ܼ�â �ʱ�ȭ
{
	system("cls");
}