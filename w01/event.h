
#ifndef SDDS_EVENT_H_
#define SDDS_EVENT_H_

extern size_t g_sysClock;
namespace sdds 
{

	class Event {
		char* discriptionOfEvent{};
		unsigned int numOfSeconds;
	public:
		Event();
		void display()const;
		void set(const char* add = nullptr);
		Event(const Event&);
		Event& operator=(const Event&);
		~Event();
	};
}
#endif





