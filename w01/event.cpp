
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "event.h"
using namespace std;

size_t g_sysClock = 0 ;

namespace sdds {

	Event::Event() 
	{
		numOfSeconds = 0;
		discriptionOfEvent = nullptr;
	}

	void Event::display()const 
	{
		int totalHours, totalMinutes, totalSeconds;
		static int INFO = 1;
		totalHours = numOfSeconds / 3600;
		totalMinutes = numOfSeconds / 60;
		totalMinutes = totalMinutes % 60;
		totalSeconds = numOfSeconds % 60;

		cout.setf(ios::right);
		cout.fill(' ');
		cout.width(2);
		cout << INFO << ". ";
		cout.unsetf(ios::right);

		if (discriptionOfEvent == nullptr || discriptionOfEvent[0] == '\0')
		{
			cout << "| No Event |" << endl;
		}
		else 
		{
			cout.setf(ios::right);
			cout.fill('0');
			cout.width(2);
			cout << totalHours << ":";
			cout.fill('0');
			cout.width(2);
			cout << totalMinutes << ":";
			cout.fill('0');
			cout.width(2);
			cout << totalSeconds << " => ";
			cout.unsetf(ios::right);
			cout << discriptionOfEvent << endl;
		}
		INFO++;

	}
	Event& Event::operator=(const Event& eve)
	{
		if (this != &eve) 
		{
			delete[] discriptionOfEvent;
			set(eve.discriptionOfEvent);
			numOfSeconds = eve.numOfSeconds;
		}
		return *this;
	}

	Event::Event(const Event& eve) 
	{
		delete[] discriptionOfEvent;
		set(eve.discriptionOfEvent);
		numOfSeconds = eve.numOfSeconds;
	}

	void Event::set(const char* add)
	{
		if (add == nullptr || add[0] == '\0')
		{
			delete[] discriptionOfEvent;
			numOfSeconds = 0;
			discriptionOfEvent = nullptr;
		}
		else
		{
			delete[] discriptionOfEvent;
			discriptionOfEvent = nullptr;
			discriptionOfEvent = new char[strlen(add) + 1];
			strcpy(discriptionOfEvent, add);
			discriptionOfEvent[strlen(add)] = '\0';
			numOfSeconds = g_sysClock;
		}
	}
	
	Event::~Event()
	{
		delete[] discriptionOfEvent;
		discriptionOfEvent = nullptr;
	}
}

