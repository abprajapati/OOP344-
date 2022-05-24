
#include "ConfirmationSender.h"

using namespace std;

namespace sdds {
	ConfirmationSender::~ConfirmationSender() 
	{
		delete[] array;
		array = nullptr;
	};
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs) 
	{
		*this = cs;
	};
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs) 
	{
		if (this != &cs) {
			delete[] array;
			array = new const Reservation * [cs.size() + 1];
			size_t i = 0;
			while(i < cs.size()) {
				this->array[i] = cs.array[i];
				i++;
			}
			this->CNT = cs.size();

		}
		return *this;
	};
	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res) {
		bool record = true;
		size_t i = 0;
		while (i < CNT)
		{
			if (array[i] == &res)
			{
				record = false;
			}
			i++;
		}

		if (record == true)
		{
			const Reservation** info = nullptr;
			info = new const Reservation * [CNT + 1];
			size_t i = 0;
			while (i < CNT) {
				info[i] = array[i];
				i++;
			}
			info[CNT] = &res;
			CNT++;
			delete[] array;
			array = info;
		}

		return *this;
	};
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res) {
		bool record = true;
		size_t index{ 0 };
		for (size_t i = 0; i < CNT; i++) {
			if (array[i] == &res) {
				record = false;
				index = i;
				i = CNT;
			}
		}

		if (record == false) {
			const Reservation** info = nullptr;
			info = new const Reservation * [CNT - 1];
			size_t i = 0;
			while (i < (CNT - 1))
			{
				if (i >= index) {
					info[i] = array[i + 1];
				}
				else {
					info[i] = array[i];
				}
				i++;
			}
			CNT--;
			delete[] array;
			array = info;
		}

		return *this;
	};
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs)noexcept 
	{
		*this = move(cs);
	};
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs)noexcept 
	{
		if (this != &cs) {
			delete[] array;
			this->array = cs.array;
			this->CNT = cs.size();
			cs.array = nullptr;
			cs.CNT = 0;
		}
		return *this;
	};

	size_t ConfirmationSender::size() const 
	{
		return CNT;
	};
	ostream& operator<<(std::ostream& os, const ConfirmationSender& c) 
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;

		if (c.CNT != 0) {
			size_t i = 0;
			while (i < c.CNT)
			{
				os << *c.array[i];
				i++;
			}
		}
		else
		{
			os << "There are no confirmations to send!" << endl;
		}
		os << "--------------------------" << endl;
		return os;

	};
}