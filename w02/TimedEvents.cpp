
#define _CRT_SECURE_NO_WARNINGS
#include "TimedEvents.h"
#include <cstring>
using namespace std;
namespace sdds {

	TimedEvents::TimedEvents() 
	{
		numOfRecords = 0;
		sTime = chrono::steady_clock::now();
		eTime = chrono::steady_clock::now();
	}

	TimedEvents::~TimedEvents() 
	{
		numOfRecords = 0;
		sTime = chrono::steady_clock::now();
		eTime = chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* name)
	{
		auto dur = chrono::duration_cast<chrono::nanoseconds>(eTime - sTime);
		int record;
		record = numOfRecords < maxNumOfEventObj;
	
		switch(record)
		{
		case 1:
			this->events[numOfRecords].nameOfEvent = name;
			this->events[numOfRecords].durationOfEvent = dur;
			this->events[numOfRecords].timeUnits = "nanoseconds";
			numOfRecords++;
			break;
		}
	}

	void TimedEvents::startClock()
	{
		sTime = chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		eTime = chrono::steady_clock::now();
	}

	ostream& operator<<(ostream& ostr, const TimedEvents& event) 
	{
		ostr << "--------------------------" << endl;
		ostr << "Execution Times:" << endl;
		ostr << "--------------------------" << endl;
		int i = 0;
		while(i < event.numOfRecords)
		{
	
			ostr.setf(ios::left);
			ostr.width(21);
			ostr << event.events[i].nameOfEvent << " ";
			ostr.unsetf(ios::left);
			ostr.setf(ios::right);
			ostr.width(13);
			ostr << event.events[i].durationOfEvent.count() << " ";
			ostr.unsetf(ios::right);
			ostr << event.events[i].timeUnits << endl;
			i++;
		}
		ostr << "--------------------------" << endl;
		return ostr;
	}
	
}