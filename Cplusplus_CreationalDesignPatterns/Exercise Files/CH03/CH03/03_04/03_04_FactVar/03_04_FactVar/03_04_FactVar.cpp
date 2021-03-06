// 03_04_FactVar.cpp 
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Rock
{
protected:
	char _type[15];
public:
	Rock()
	{
	}
	char *getType()
	{
		return _type;
	}
};

class Simple : public Rock
{
public:
	Simple()
	{
		strcpy_s(_type, "Simple");
	}
};

class Big : public Rock
{
public:
	Big()
	{
		strcpy_s(_type, "Big");
	}
};

class Metal : public Rock
{
public:
	Metal()
	{
		strcpy_s(_type, "Metal");
	}
};

// Abstract Factory
class RockFactory
{
public:
	virtual Rock * getRocks() = 0;
	virtual Rock * getRocks(int i) = 0;
};

// Concrete rock factory that returns the correct rock type based on the level
class LevelRockFactory : public RockFactory
{
private:
	Rock * _rock;
public:
	Rock * getRocks()
	{
		return getRocks(1);
	}
	Rock * getRocks(int level)
	{
		switch (level)
		{
		case 1:
			return new Simple[10];
		case 2:
			return new Big[10];
		case 3:
			return new Metal[10];
		default:
			cout << "Invalid Selection" << endl;
			return NULL;
		}
	}
};

// Concrete rock factory that returns the correct rock type based on user input
class PracticeRockFactory : public RockFactory
{
private:
	Rock * _rock;
public:
	Rock * getRocks()
	{
		int choice;

		cout << "Select type of rock to practice with: " << endl;
		cout << "1: Simple rock" << endl;
		cout << "2: Big rock" << endl;
		cout << "3: Metal rock" << endl;
		cout << "Selection: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			return new Simple;
		case 2:
			return new Big;
		case 3:
			return new Metal;
		default:
			cout << "Invalid Selection" << endl;
			return NULL;
		}
	}
	Rock * getRocks(int level)
	{
		return getRocks();
	}
};

int main()
{
	// Generate rocks based on level
	LevelRockFactory RockMachine;
	int level = 1;

	// generate rocks based on the level
	Rock *r = RockMachine.getRocks(level);

	// Show the type of rocks created for the level
	for (int i = 0; i < 10; i++)
	{
		cout << "The type of rock created is: " << r[i].getType() << endl;
	}

	cout << endl;

	// Generate rocks based on user input
	PracticeRockFactory RockMaker;
	Rock *practice = RockMaker.getRocks();

	//Show the type of rock the user wanted
	cout << endl << "Player asked for a " << practice->getType() << " rock" << endl;
}


