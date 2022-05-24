

#ifndef SET_H_
#define SET_H_
#include <iostream>

namespace sdds
{

	template<size_t N, typename T>
	class Set
	{
		T array[N];
		size_t curElements = 0;
	public:
		size_t size() const
		{
			return curElements;
		};
		const T& get(size_t idx) const
		{
			return array[idx];
		}
		void operator+=(const T& item)
		{
			int record;
			record = curElements < N;
		 switch(record)
			{
		 case 1:
				array[curElements] = item;
				curElements++;
				break;
			}
		}
	};

}
#endif
