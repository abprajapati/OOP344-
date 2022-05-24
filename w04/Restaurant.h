
#ifndef RESTAURANT_H_
#define RESTAURANT_H_
#include <iostream>
#include <iomanip>
#include <string>
#include "Reservation.h"

namespace sdds {
	class Restaurant 
	{
		Reservation* array{};
		size_t CNT = 0;
	public:
		Restaurant() {};
		~Restaurant();
		Restaurant(const Restaurant&);
		Restaurant(Restaurant&&)noexcept;
		Restaurant& operator=(Restaurant&&)noexcept;
		Restaurant& operator=(const Restaurant&);
		Restaurant(const Reservation* reservations[], size_t cnt);
		size_t size() const;
		friend std::ostream& operator<<(std::ostream&, const Restaurant&);
	};
}

#endif // !RESTAURANT_H_

