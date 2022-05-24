
#ifndef MOVIE_H_
#define MOVIE_H_

#include <iomanip>
#include "SpellChecker.h"
namespace sdds {

	class Movie 
	{
		std::string movieTitle;
		size_t releaseYear=0;
		std::string movieDescription;
		
	public:
		Movie() {};
		const std::string& title() const;
		Movie(const std::string& strMovie);
		std::string& removespaces(std::string& str);
		friend std::ostream& operator<<(std::ostream&, const Movie&);
		
		template<typename T>
		void fixSpelling(T& spellChecker) 
		{
			spellChecker(movieTitle);
			spellChecker(movieDescription);
		}

	};
}
#endif // !MOVIE_H_
