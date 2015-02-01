
void gotoxy(int x, int y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void setcolor(int color, int bgcolor) 
{
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible=show;
	ConsoleCursor.dwSize=1;
	SetConsoleCursorInfo(hConsole,&ConsoleCursor);
}
