// 06_02_ProtoSetUp_Start.cpp 
//

#include "stdafx.h"
#include <iostream>

using namespace std;

// Abstract Animal class
class Animal
{
protected:
	char _hairColor[10];
	int _hairLength, _tail, _weight, _height, _age;
	int _intelligence, _stubbornness, _agressiveness;

public:


	int setHairLength(int length)
	{
		_hairLength = length;
	}

	void setHairColor(const char *color)
	{
		strcpy_s(_hairColor, color);
	}

	void setTail(int length)
	{
		_tail = length;
	}

	void setWeight(int kg)
	{
		_weight = kg;
	}

	void setHeight(int m)
	{
		_height = m;
	}

	void setAge(int age)
	{
		_age = age;
	}

};

// Derived Sheep class
class Sheep : public Animal
{
public:
	Sheep()
	{
		_hairLength = 5;
		_stubbornness = 3;
		_agressiveness = 2;
		_intelligence = 7;
	}

};

// Derived Cow class
class Cow : public Animal
{
public:
	Cow()
	{
		_stubbornness = 6;
		_agressiveness = 5;
		_intelligence = 8;
	}

};

int main()
{
	//create initial instance of a Sheep


	//create initial instance of a Cow




	//use cloning to populate the farm


	//change a cow property


	//shear a Sheep and clone it



}

