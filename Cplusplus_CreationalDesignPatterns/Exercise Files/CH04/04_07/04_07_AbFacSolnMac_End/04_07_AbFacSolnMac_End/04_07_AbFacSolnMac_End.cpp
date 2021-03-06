// 04_07_AbFacSolnMac_End.cpp
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>   // WinApi header

using namespace std;

#pragma region Backgrounds
// Base Background class
class Background
{
protected:
	char _theme[10];
public:
	Background()
	{
	}
	virtual void getTheme() = 0;
};

// Derived Light Background class
class LightBkgd : public Background
{
public:
	LightBkgd()
	{

		cout << "\x1b[30;47m Making the background white " << endl;
		strcpy_s(_theme, "light");
	}
	void getTheme()
	{
		cout << "This is a part of the light theme" << endl;
	}
};

// Derived Dark Background class
class DarkBkgd : public Background
{
public:
	DarkBkgd()
	{

		cout << "\x1b[37;40m Making the background black " << endl;
		strcpy_s(_theme, "dark");
	}
	void getTheme()
	{
		cout << "This is a part of the dark theme" << endl;
	}
};
#pragma endregion Background

#pragma region Text
// Base Text class
class Text
{
protected:
	char _theme[10];
public:
	Text()
	{
	}
	virtual void message() = 0;
};

// Derived Black Text class
class BlackText : public Text
{
public:
	BlackText()
	{

		strcpy_s(_theme, "light");
		cout << "\x1b[30m Making the text black" << endl;
	}
	void message()
	{

		cout << "\x1b[30m This is the default font from the light theme" << endl;
	}
};

// Derived White Text class
class WhiteText : public Text
{
public:
	WhiteText()
	{

		strcpy_s(_theme, "dark");
		cout << "\x1b[37m Making the text white" << endl;
	}
	void message()
	{

		cout << "\x1b[37m This is the default font for the dark theme" << endl;
	}
};

// Derived Dark Green Text class
class DarkGreenText : public Text
{
public:
	DarkGreenText(HANDLE hConsole)
	{
		
		cout << "\x1b[32m Making the text green" << endl;
	}
	void message(HANDLE hConsole)
	{
		
		cout << "x1b[32m This is the green font for the light theme" << endl;
	}
};

// Derived Light Green Text class
class LightGreenText : public Text
{
public:
	LightGreenText(HANDLE hConsole)
	{
		
		cout << "\x1b[32m Making the text green" << endl;
	}
	void message(HANDLE hConsole)
	{
		
		cout << "\x1b[32m This is the green font for the dark theme" << endl;
	}
};
#pragma endregion Text

#pragma region Factories
// Base Factory
class ThemeFactory
{
public:
	virtual Background* setBackground() = 0;
	virtual Text* getDefaultText() = 0;

};

// Derived Light Theme Factory which pairs the white background with darker text
class LightFactory : public ThemeFactory
{
public:
	Background * setBackground()
	{
		return new LightBkgd();
	}
	Text * getDefaultText()
	{
		return new BlackText();
	}

};

// Derived Dark Theme Factory which pairs the black background with lighter text
class DarkFactory : public ThemeFactory
{
public:
	Background * setBackground()
	{
		return new DarkBkgd();
	}
	Text * getDefaultText()
	{
		return new WhiteText();
	}

};
#pragma endregion Factories

int main()
{
	// Configure console variables and colours (Windows only)
	// HANDLE  hConsole;
	// hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	// SetConsoleTextAttribute(hConsole, 30);

	ThemeFactory* app;
	int choice;

	cout << "\x1b[33;44m Select a theme: " << endl;
	cout << "1: Light" << endl;
	cout << "2: Dark" << endl;
	cout << "Selection: ";
	cin >> choice;
	cout << endl;

	// Initiate the correct factory based on user input
	switch (choice)
	{
	case 1:
		app = new LightFactory;
		break;
	case 2:
		app = new DarkFactory;
		break;
	default:
		cout << "Invalid Selection" << endl;
		app = NULL;
		break;
	}

	// Get the correct objects based on factory selected
	if (app != NULL)
	{
		Background* appBkgd = app->setBackground();
		Text *appDefaultText = app->getDefaultText();


		appDefaultText->message();

	}

	cout << endl;
	system("pause");
}
