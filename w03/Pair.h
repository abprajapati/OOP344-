

#ifndef PAIR_H_
#define PAIR_H_
#include<iostream>

namespace sdds
{

	template<typename V, typename K>
	class Pair
	{
		V typeValue{};
		K typeKey{};
	public:
		Pair()
		{

		}

		Pair(const K& key, const V& value)
		{

			typeValue = value;
			typeKey = key;
		}

		const V& value() const
		{
			return typeValue;
        }

		const K& key() const
		{
			return typeKey;
		}

		virtual void display(std::ostream& os) const
		{
			os << typeKey << " : ";
			os << typeValue << std::endl;
		}

	};

	template<typename V, typename K>
	std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair)
	{
		pair.display(os);
		return os;
	}
}

#endif