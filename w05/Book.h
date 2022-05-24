
#ifndef BOOK_H_
#define BOOK_H_
#include <iomanip>
#include "SpellChecker.h"
namespace sdds {
	class Book {
		std::string authorName;
		std::string titleOfBook;
		std::string countryOfPublic;
		size_t yearOfPublication = 0;
		double bookPrice = 0;
		std::string description;
	public:
		Book() {};
		
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		std::string& removespaces(std::string& str);
		friend std::ostream& operator<<(std::ostream&, const Book&);

		template<typename T>
		void fixSpelling(T& spellChecker) {
			spellChecker(description);
		}
	};
}

#endif 
