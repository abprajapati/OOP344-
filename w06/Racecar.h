
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include <iomanip>
#include <iostream>
#include "Car.h"
namespace sdds {
	class Racecar : public Car{
		double m_booster{};
	public:
		
		Racecar(std::istream& in);
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif