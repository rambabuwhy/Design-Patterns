// 02_02_Comp_Start.cpp 
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Base Entree class
class Entree
{
protected:
	char _entree[10];
public:
	const char *getEntree()
	{
		return _entree;
	}
};


// Base Side class
class Side
{
protected:
	char _side[10];
public:
	char *getSide()
	{
		return _side;
	}
};

class Drink
{
protected:
	char _drink[10];
public:
	Drink()
	{
		cout << "\n Fill cup with soda" << endl;
		strcpy_s(_drink, "soda");
	}
	char *getDrink()
	{
		return _drink;
	}
};

// Complex MealCombo object that contains an Entree, a Side and a Drink object
