
#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <iomanip>
#include "Vehicle.h"

namespace sdds {
	class Car : public Vehicle {
		std::string maker{};
		std::string conditionOfCar{};
		double tSpeed{};
	public:
		Car() {};
		Car(std::istream&);
		double topSpeed() const;
		std::string condition() const;
		void display(std::ostream& out) const;
		std::string& removeWhiteSpaces(std::string&);
		~Car() {};
	};
}
#endif