
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Vehicle.h"
#include "Racecar.h"
#include "Car.h"

namespace sdds {

	Vehicle* createInstance(std::istream& in);
}
#endif