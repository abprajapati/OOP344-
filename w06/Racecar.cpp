
#include "Racecar.h"

using namespace std;
namespace sdds {
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		string strRecord{};
		getline(in, strRecord);
		if (!strRecord.empty())
		{
			m_booster = stod(strRecord);
		}
	};

	double Racecar::topSpeed() const
	{
		double carSpeed = 0;
		carSpeed = Car::topSpeed() + (m_booster * Car::topSpeed());
		return carSpeed;
	};

	void Racecar::display(std::ostream& out) const 
	{
		Car::display(out);
		out << "*";
	};	
}