
#include "Utilities.h"

using namespace std;

namespace sdds {	
	Vehicle* createInstance(std::istream& in) 
	{

		Vehicle* record = nullptr;
		string stringRecord{};
		stringstream strStream{};

		getline(in, stringRecord);
		if (!stringRecord.empty())
		{
			stringRecord = stringRecord.substr(stringRecord.find_first_not_of(" "));
			stringRecord = stringRecord.substr(0, stringRecord.find_last_not_of(" ") + 1);
		
			if (stringRecord[0] == 'R' || stringRecord[0] == 'r')
			{
				strStream << stringRecord;
				record = new Racecar(strStream);
			}
			else if (stringRecord[0] == 'C' || stringRecord[0] == 'c')
			{
				strStream << stringRecord;
				record = new Car(strStream);
			}
			else 
			{
				throw stringRecord[0];
			}
		}
		return record;
	}
}