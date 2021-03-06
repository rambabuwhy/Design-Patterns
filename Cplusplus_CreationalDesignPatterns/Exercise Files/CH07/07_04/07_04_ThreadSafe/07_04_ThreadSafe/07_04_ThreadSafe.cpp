// 07_04_ThreadSafe.cpp 


#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;
CRITICAL_SECTION critical;

class Leader
{

public:
	// Define a public static accessor func
	static Leader * getInstance()
	{
		EnterCriticalSection(&critical);
		if (_instance == NULL)
		{
			_instance = new Leader();
		}
		return _instance;
		LeaveCriticalSection(&critical);
	}
	// Define private static attribute
private:
	static Leader * _instance;
	// Define the constructor to be protected
	Leader()
	{
		cout << "New Leader elected" << endl;
	}

public:
	void giveSpeech()
	{
		cout << "Address the public." << endl;
	}
};

// Null, because instance will be initialized on demand. 
Leader* Leader::_instance = 0;

int main()
{
	// Identify the start of the critical section
	InitializeCriticalSection(&critical);

	Leader::getInstance()->giveSpeech();

	// End of the critical section
	DeleteCriticalSection(&critical);

	cout << "No longer in critical section" << endl;
}


