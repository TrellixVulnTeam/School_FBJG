#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "function.h"

void clear()
{
        COORD coordScreen = { 0, 0 };
        DWORD cCharsWritten;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        DWORD dwConSize;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        GetConsoleScreenBufferInfo(hConsole, &csbi);
        dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
        FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
        SetConsoleCursorPosition(hConsole, coordScreen);
}

void gotoxy(int x, int y)
{
        COORD point;
        point.X = x; point.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
int MyGetch (void)
{
  int Ret = getch();
  if ((!Ret || Ret == 0xE0) && kbhit())
    Ret = 256 + getch();
  return Ret;
}

void color(int chosen_color)
{
    
    switch(chosen_color)
    {
                        
        case 0: /* black on black background */
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
                break;
        case 1:  /* red on black background */
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
                        FOREGROUND_RED);
                break;
        case 2:  /* green on black background */
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
                        FOREGROUND_GREEN);
                break;
        case 3:  /* yellow on black background */
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0 | BACKGROUND_INTENSITY | BACKGROUND_GREEN);
                break;

        default: /* white on black background */
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |
                        FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
                break;     
                        
    } 
     
}
