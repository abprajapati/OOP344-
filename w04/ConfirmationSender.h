
#ifndef CONFIRMATIONSENDER_H_
#define CONFIRMATIONSENDER_H_

#include <iostream>
#include <iomanip>
#include <string>
#include "Reservation.h"
#include "Restaurant.h"

namespace sdds {
	class ConfirmationSender {
		const Reservation** array{};
		size_t CNT = 0;
	public:
		ConfirmationSender() {};
		~ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender(ConfirmationSender&&)noexcept;
		ConfirmationSender& operator=(ConfirmationSender&&)noexcept;
		size_t size() const;
		friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
	};
}


#endif