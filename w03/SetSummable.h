
#ifndef SETSUMMABLE_H_
#define SETSUMMABLE_H_
#include <iostream>
#include "Set.h"


namespace sdds
{
	template <size_t N, typename T>
	class SetSummable : public Set<N, T>
	{
	public:

		T accumulate(const std::string& filter) const
		{
			size_t i;
			T acc(filter);
			for ( i = 0; i < this->size(); i++)
			{
				int record;
				record = acc.isCompatibleWith(this->get(i)) == true;
				switch(record)
				{
				case 1:
					acc += this->get(i);
					break;
				}
			}
			return acc;
		};
	};
}
#endif