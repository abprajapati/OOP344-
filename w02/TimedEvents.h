
#ifndef _SDDS_TIMEDEVENTS_H_
#define _SDDS_TIMEDEVENTS_H_
#include <iostream>
#include <chrono>
#include <cstring>

namespace sdds {

	const int maxNumOfEventObj = 10;

	class TimedEvents {
		int numOfRecords{ 0 };
		std::chrono::steady_clock::time_point sTime;
		std::chrono::steady_clock::time_point eTime;
		struct {
			std::string nameOfEvent;
			std::string timeUnits;
			std::chrono::steady_clock::duration durationOfEvent;
		}events[maxNumOfEventObj];

	public:
		TimedEvents();
		~TimedEvents();
		void addEvent(const char*);
		void startClock();
		void stopClock();
		friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
	};
}



#endif 