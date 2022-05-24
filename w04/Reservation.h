
#ifndef RESERVATION_H_
#define RESERVATION_H_
#include <iostream>
#include <string>
#include <iomanip>

namespace sdds {
    class Reservation 
    {
        std::string reserveId{};
        std::string reservEmail{};
        std::string nameOnReserv{};
        int peopleReserv{};
        int partyTime{};
        int partyDay{};
      
    public:
        Reservation() {};
        void update(int day, int time);
        Reservation(const std::string& res);
        friend std::ostream& operator<<(std::ostream&, const Reservation&);
       };
}
#endif 
