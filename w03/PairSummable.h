
#ifndef PAIR_SUMMABLE_H_
#define PAIR_SUMMABLE_H_
#include<iostream>
#include<string>
#include"Pair.h"

namespace sdds
{

	template<typename V, typename K>
	class PairSummable :public Pair<V, K>
	{
		static V initVal;
		static size_t minWidth;
	public:
		PairSummable()
		{
			minWidth = 0;
		};

		PairSummable(const K& key, const V& value = initVal) :Pair<V, K>(key, value)
		{
			int record;
			record = minWidth < key.size();
			switch(record)
			{
			case 1:
				minWidth = key.size();
				break;
			}

		}

		bool isCompatibleWith(const PairSummable<V, K>& b) const
		{

			bool info = false;
			int record;
			record = b.key() == this->key();
			switch(record)
			{
			case 1:
				info = true;
				break;
			}

			return info;
		}

		PairSummable<V, K>& operator+=(const PairSummable<V, K>& pair)
		{

			*this = PairSummable(pair.key(), pair.value() + this->value());

			return *this;

		}

		void display(std::ostream& os) const
		{

			os.setf(std::ios::left);
			os.width(minWidth);
			Pair<V, K>::display(os);
			os.unsetf(std::ios::left);

		}

	};

	template<typename V, typename K>
	V PairSummable<V, K>::initVal{};

	template<typename V, typename K>
	size_t PairSummable<V, K>::minWidth = 0;

	template<>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>:: operator+=(const PairSummable<std::string, std::string>& pair)
	{
		if (this->value() == "")
		{
			*this = PairSummable(pair.key(), pair.value());
		}
		else
		{
			*this = PairSummable(pair.key(), this->value() + ", " + pair.value());
		}
		return *this;
	}
}

#endif