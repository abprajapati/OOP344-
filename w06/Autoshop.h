
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <iostream>
#include <iomanip>

#include <list>
#include <vector>
#include "Vehicle.h"
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();

		template<typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) 
		{
			size_t i = 0;
			while (i < m_vehicles.size())
			{
				if (test(m_vehicles[i]) == true) {
					vehicles.push_back(m_vehicles[i]);
				}
				i++;
			}
		}

	};
}

#endif