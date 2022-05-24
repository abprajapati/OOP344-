

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Reservation.h"

using namespace std;
namespace sdds {

    void Reservation::update(int day, int time) 
    {
        partyTime = time;
        partyDay = day;
       
    };

    Reservation::Reservation(const string& res) {
        if (!res.empty()) 
        {
            string temp(res);
            reserveId = temp.substr(0, temp.find(":"));
            reserveId = reserveId.substr(reserveId.find_first_not_of(" "));
            reserveId = reserveId.substr(0, reserveId.find_last_not_of(" ") + 1);
            temp.erase(0, temp.find(":") + 1);

            nameOnReserv = temp.substr(0, temp.find(","));
            nameOnReserv = nameOnReserv.substr(nameOnReserv.find_first_not_of(" "));
            nameOnReserv = nameOnReserv.substr(0, nameOnReserv.find_last_not_of(" ") + 1);
            temp.erase(0, temp.find(",") + 1);

            reservEmail = temp.substr(0, temp.find(","));
            reservEmail = reservEmail.substr(reservEmail.find_first_not_of(" "));
            reservEmail = reservEmail.substr(0, reservEmail.find_last_not_of(" ") + 1);
            temp.erase(0, temp.find(",") + 1);

            peopleReserv = stoi(temp.substr(0, temp.find(",")));
            temp.erase(0, temp.find(",") + 1);

            partyDay = stoi(temp.substr(0, temp.find(",")));
            temp.erase(0, temp.find(",") + 1);

            partyTime = stoi(temp.substr(0, temp.find(",")));
            temp.erase(0, temp.find(",") + 1);
        }
        
    };
    ostream& operator<<(ostream& os, const Reservation& res) 
    {
        os << "Reservation " << right << setw(10) << res.reserveId << ": ";
        os << right << setw(20) << res.nameOnReserv << "  ";
        os << left << setw(20) << "<" + res.reservEmail + ">";
        if (res.partyTime >= 6 && res.partyTime <= 9)
        {
            os << "    Breakfast on day " << res.partyDay << " @ " << res.partyTime << ":00 for " << res.peopleReserv;
        }
        else if (res.partyTime >= 11 && res.partyTime <= 15)
        {
            os << "    Lunch on day " << res.partyDay << " @ " << res.partyTime << ":00 for " << res.peopleReserv;
        }
        else if (res.partyTime >= 17 && res.partyTime <= 21)
        {
            os << "    Dinner on day " << res.partyDay << " @ " << res.partyTime << ":00 for " << res.peopleReserv;
        }
        else
        {
            os << "    Drinks on day " << res.partyDay << " @ " << res.partyTime << ":00 for " << res.peopleReserv;
        }
        if (res.peopleReserv != 1)
        {
            os << " people.\n";
        }
        else
        {
            os << " person.\n";
        }
        return os;
    };

}