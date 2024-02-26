#include<iostream>﻿;
enum clickmenu
{
	UP = 72,
	DOWN = 80,
	ENTER = 13
};
enum colormenu {
	BLACK,
	BLUE,
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_AQUA,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	BRIGHT_WHITE
};
void displayRentACarAnimation() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int backColor = BLACK;
	int foreColor = YELLOW;
	WORD wcolor(((backColor & 0x0f) << 4) + (foreColor & 0x0F));
	SetConsoleTextAttribute(hConsole, wcolor);
	for (size_t i = 0; i < 1; i++)
	{
		WORD wcolor(((backColor & 0x0f) << 4) + (foreColor & 0x0F));
		SetConsoleTextAttribute(hConsole, wcolor);
		cout << "\t\t\t\t\t\t\t&&&&&  &&&&&  &&  &&  &&&&&&     &&&&      &&&&   &&&&  &&&&&" << endl;
		cout << "\t\t\t\t\t\t\t&&  &  &&     &&& &&    &&      &&  &&    &&  && &&  && &&  &" << endl;
		cout << "\t\t\t\t\t\t\t&&&&&  &&&&&  && &&&    &&      &&&&&&    &&     &&&&&& &&&&&" << endl;
		cout << "\t\t\t\t\t\t\t&&  && &&     &&  &&    &&      &&  &&    &&  && &&  && &&  &&" << endl;
		cout << "\t\t\t\t\t\t\t&&  && &&&&&  &&  &&    &&      &&  &&     &&&&  &&  && &&  &&" << endl;
		cout << '\n';
		cout << "\t\t\t\t\t\t\t\t\t\t      _____       " << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t  ___/__|__\\____ " << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t |           |  | " << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t |___\\_____/_|__|" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t   (0)     (0)    " << endl;

	}
}
void displayExitAnimation()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int backColor1 = WHITE;
	int foreColor1 = RED;

	WORD wcolor1(((backColor1 & 0x0f) << 4) + (foreColor1 & 0x0F));
	WORD wcolor2(((foreColor1 & 0x0f) << 4) + (backColor1 & 0x0F));


	for (int i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
		{
			SetConsoleTextAttribute(hConsole, wcolor1);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, wcolor2);
		}
		cout << " $$$$  $$$$$  $$$$$   $$$$  $$$$$$ $$$$$  $$$$$" << endl;
		cout << "$$  $$ $$  $$ $$     $$  $$   $$   $$     $$  $$" << endl;
		cout << "$$     $$$$$  $$$$   $$$$$$   $$   $$$$   $$$$$" << endl;
		cout << "$$  $$ $$  $$ $$     $$  $$   $$   $$     $$  $$" << endl;
		cout << " $$$$  $$  $$ $$$$$  $$  $$   $$   $$$$$  $$  $$" << endl;

		cout << "$$   $$ $$  $$ $$$$$   $$$$  $$$$$     $$  $$ $$  $$ $$$$$" << endl;
		cout << "$$$ $$$ $$  $$ $$  $$ $$  $$ $$  $$    $$$ $$ $$  $$ $$  $$" << endl;
		cout << "$$ $ $$ $$  $$ $$$$$  $$$$$$ $$  $$    $$ $$$ $$  $$ $$$$$" << endl;
		cout << "$$   $$ $$  $$ $$  $$ $$  $$ $$  $$    $$  $$ $$  $$ $$  $$" << endl;
		cout << "$$   $$  $$$$  $$  $$ $$  $$ $$$$$     $$  $$  $$$$  $$  $$" << endl;
		cout << '\n' << endl;
		cout << '\n' << endl;
		cout << '\n' << endl;
		cout << '\n' << endl;
		cout << '\n' << endl;
		cout << '\n' << endl;
		cout << "\t\t\t\t\t\t\t    &&&&   &&&&   &&&&   &&&&     &&&&&  &&  && &&&&&" << endl;
		cout << "\t\t\t\t\t\t\t   &&     &&  && &&  && &&  &&    &&  &&  &&&&  &&   " << endl;
		cout << "\t\t\t\t\t\t\t   && &&& &&  && &&  && &&  &&    &&&&&    &&   &&&&&" << endl;
		cout << "\t\t\t\t\t\t\t   &&  && &&  && &&  && &&  &&    &&  &&   &&   &&   " << endl;
		cout << "\t\t\t\t\t\t\t    &&&&   &&&&   &&&&  &&&&&     &&&&&    &&   &&&&&" << endl;
		Sleep(100);
		system("cls");

	}
	SetConsoleTextAttribute(hConsole, wcolor1);
	exit(0);
}