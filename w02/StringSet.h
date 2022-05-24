

#ifndef _SDDS_STRINGSET_H_
#define _SDDS_STRINGSET_H_
#include <iostream>
#include <string>

namespace sdds {
	class StringSet {
		std::string* array = nullptr;
		size_t totalString = 0;
	public:
		StringSet();
		~StringSet();
		StringSet(const char*);
		StringSet(const StringSet&);
		StringSet& operator=(const StringSet&);
		StringSet(StringSet&&)noexcept;
		StringSet& operator=(StringSet&&)noexcept;
		size_t size();
		std::string operator[](size_t);
	};
}

#endif 