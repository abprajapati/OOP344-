
#include "Movie.h"
#include <string>
using namespace std;
namespace sdds {

	const std::string& Movie::title() const 
	{
		return movieTitle;
 	}

	string& Movie::removespaces(string& str) 
	{
		str = str.substr(str.find_first_not_of(" "));
		str = str.substr(0, str.find_last_not_of(" ") + 1);
		return str;
	}

	Movie::Movie(const std::string& strMovie) 
	{
		if (!strMovie.empty()) {
			string temp(strMovie);

			movieTitle = temp.substr(0, temp.find(","));
			movieTitle = removespaces(movieTitle);
			temp.erase(0, temp.find(",") + 1);

			releaseYear = stoi(temp.substr(0, temp.find(",")));
			temp.erase(0, temp.find(",") + 1);

			movieDescription = temp.substr(0, temp.find("\n"));
			movieDescription = removespaces(movieDescription);
			temp.erase(0, temp.find("\n") + 1);
		}
	}

	ostream& operator<<(ostream& os, const Movie& mov) 
	{
		os << setw(40) << mov.movieTitle << " | ";
		os << setw(4) << mov.releaseYear << " | ";
		os << mov.movieDescription << endl;

		return os;
	}
}