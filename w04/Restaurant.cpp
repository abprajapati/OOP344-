
#include "Restaurant.h"

using namespace std;

namespace sdds {
	Restaurant::~Restaurant() 
	{
		delete[] array;
		array = nullptr;
	};

	Restaurant::Restaurant(const Restaurant& res) 
	{
		*this = res;
	};

	Restaurant& Restaurant::operator=(const Restaurant& res) 
	{
		if (this != &res) {
				delete[] array;
				array = new Reservation[res.size() + 1];
				size_t i = 0;
				while(i < res.size())
				{
					this->array[i] = res.array[i];
					i++;
				}
				this->CNT = res.size();
			
		}
		return *this;
	};

	Restaurant::Restaurant(Restaurant&& res)noexcept 
	{
		*this = move(res);
	};

	Restaurant& Restaurant::operator=(Restaurant&& res)noexcept 
	{
		if (this != &res) {
				delete[] array;
				this->array = res.array;
				this->CNT = res.size();
				res.array = nullptr;
				res.CNT = 0;
			
	   }
		return *this;
	};
	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		CNT = cnt;
		array = new Reservation[cnt + 1];
		size_t i = 0;
		while (i < cnt)
		{
			array[i] = *reservations[i];
			i++;
		}
	};


	size_t Restaurant::size() const 
	{
		return CNT;
	}
	ostream& operator<<(std::ostream& os, const Restaurant& res) 
	{
		static int CALL_CNT = 1;
		os << "--------------------------" << endl;
		os << "Fancy Restaurant (" << CALL_CNT << ")" << endl;
		os << "--------------------------" << endl;
		if (res.size() != 0)
		{
			size_t i = 0;
			while (i < res.size())
			{
				os << res.array[i];
				i++;
			}
		}
		
		else {
			os << "This restaurant is empty!" << endl;
		}
		os << "--------------------------" << endl;
		CALL_CNT++;
		return os;
	};
}