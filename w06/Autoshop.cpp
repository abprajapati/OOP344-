

#include "Car.h"
#include "Autoshop.h"

using namespace std;
namespace sdds {

	Autoshop& Autoshop::operator +=(Vehicle* theVehicle) 
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	};

	void Autoshop::display(std::ostream& out) const 
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;
		auto i = m_vehicles.begin();
		while(i < m_vehicles.end())
		{
			(*i)->display(out);
			out << endl;
			i++;
		}
		
		out << "--------------------------------" << endl;
	};

	Autoshop::~Autoshop() 
	{
		size_t i = 0;
		while (i < m_vehicles.size())
		{
			delete m_vehicles[i];
			i++;
		}
	}
}