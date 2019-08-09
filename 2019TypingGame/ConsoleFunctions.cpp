#include "ConsoleFunctions.h"

static CursorType cursorType;

HANDLE getHandle(void) // 콘솔창 핸들을 얻음
{
	return GetStdHandle(STD_OUTPUT_HANDLE);
}

void gotoxy(int x, int y) // 커서 이동
{
	COORD dwCursorPosition = { x, y };
	SetConsoleCursorPosition(getHandle(), dwCursorPosition);
}

void setCursorType(CursorType type) // 커서타입설정
{
	CONSOLE_CURSOR_INFO curInfo;
	switch (cursorType = type)
	{
	case CursorInvisible: // 안보임
		curInfo.dwSize = 1;
		curInfo.bVisible = FALSE;
		break;

	case CursorInput: // 입력모드
		curInfo.dwSize = 100;
		curInfo.bVisible = TRUE;
		break;

	case CursorNormal: // 일반
		curInfo.dwSize = 20;
		curInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(getHandle(), &curInfo);
}

CursorType getCursorType() // 커서타입 얻기
{
	return cursorType;
}

void setTextColor(Color color) // 텍스트컬러 지정
{
	SetConsoleTextAttribute(getHandle(), getBackgroundColor() * 16 + color);
}

Color getTextColor() // 텍스트 컬러 얻기
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo;
	GetConsoleScreenBufferInfo(getHandle(), &bufInfo);
	return (Color)(bufInfo.wAttributes % 16);
}

void setBackgroundColor(Color color) // 배경 색 설정
{
	SetConsoleTextAttribute(getHandle(), color * 16 + getTextColor());
}

Color getBackgroundColor(void) // 배경 색 얻기
{
	CONSOLE_SCREEN_BUFFER_INFO bufInfo = { 0, };
	GetConsoleScreenBufferInfo(getHandle(), &bufInfo);
	return (Color)(bufInfo.wAttributes / 16);
}

void setSize(int cols, int lines) // 콘솔 창 크기 변경
{
	std::ostringstream s;
	std::string buf;
	s << "mode con: cols=" << cols << " lines=" << lines;
	buf = s.str();
	std::cout << buf << std::endl;
	system(buf.c_str());
}

void setTitle(const char *title) // 타이틀설정
{
	SetConsoleTitleA(title);
}

void getTitle(char *out, int nSize) // 타이틀얻기
{
	GetConsoleTitleA(out, nSize);
}

void clearConsole() //콘솔창 초기화
{
	system("cls");
}