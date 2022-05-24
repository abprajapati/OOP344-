
#include "Car.h"

using namespace std;
namespace sdds {

	string& Car::removeWhiteSpaces(std::string& str) 
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
		return str;
	}

	Car::Car(std::istream& is) 
	{
		std::string str{};
		std::string TAG{};
		size_t i = 0;
		while (i < 4)
		{
			std::getline(is, str, ',');
			removeWhiteSpaces(str);
			if (i == 0) {
				TAG = str;
				removeWhiteSpaces(TAG);
			}
			else if (i == 1) {
				maker = str;
				removeWhiteSpaces(maker);
			}
			else if (i == 2) {
				if ((!str.empty()) && str.find_first_not_of(' ') != str.npos)
				{
					removeWhiteSpaces(str);
					if (str != "n" && str != "b" && str != "u") 
					{
						throw string("Invalid record!");
					}
					else {
						if (str == "n") 
						{
							conditionOfCar = "new";
						}
						else if (str == "b")
						{
							conditionOfCar = "broken";
						}
						else if (str == "u") 
						{
							conditionOfCar = "used";
						}
					}
					
				}
				else 
				{
					conditionOfCar = "new";
				}
			}
			else if (i == 3) {
				bool record = true;
				size_t i = 0;
				while (i < str.length())
				{
					if (!isdigit(str[i]))
					{
						record = false;
					}
					i++;
				}
			
				if (!record) 
				{
					throw string("Invalid record!");
				}
				else 
				{
					tSpeed = double(stod(str));
				}
			}
			i++;
		}
	}

	double Car::topSpeed() const
	{
		return tSpeed;
	}

	std::string Car::condition() const 
	{
		return conditionOfCar;
	}

	void Car::display(std::ostream& out) const 
	{
		out << "| " << setw(10) << right << maker << " | ";
		out << left << setw(6) << condition() << " | ";
		out << fixed << setprecision(2) <<topSpeed()  << " |";
	}
}