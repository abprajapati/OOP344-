
#include "Book.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;
namespace sdds {

	const string& Book::title() const 
	{
		return titleOfBook;
	}

	const size_t& Book::year() const
	{
		return yearOfPublication;
	};

	const string& Book::country() const 
	{
		return countryOfPublic;
	};
	
	double& Book::price() 
	{
		return bookPrice;
	};

	string& Book::removespaces(string& str) 
	{
		str = str.substr(str.find_first_not_of(" "));
		str = str.substr(0, str.find_last_not_of(" ") + 1);
		return str;
	}

	Book::Book(const std::string& strBook) 
	{
		if (!strBook.empty()) {
			string temp(strBook);
			authorName = temp.substr(0, temp.find(","));
			authorName = removespaces(authorName);
			temp.erase(0, temp.find(",") + 1);

			titleOfBook = temp.substr(0, temp.find(","));
			titleOfBook = removespaces(titleOfBook);
			temp.erase(0, temp.find(",") + 1);

			countryOfPublic = temp.substr(0, temp.find(","));
			countryOfPublic = removespaces(countryOfPublic);
			temp.erase(0, temp.find(",") + 1);

			bookPrice = stod(temp.substr(0, temp.find(",")));
			temp.erase(0, temp.find(",") + 1);

			yearOfPublication = stoi(temp.substr(0, temp.find(",")));
			temp.erase(0, temp.find(",") + 1);

			description = temp.substr(0, temp.find("\n"));
			description = removespaces(description);
			temp.erase(0, temp.find("\n") + 1);

		}
	};

	ostream& operator<<(std::ostream& os, const Book& strBook)
	{
		os << right << setw(20) << strBook.authorName << " | ";
		os << right << setw(22) << strBook.titleOfBook << " | ";
		os << right << setw(5) << strBook.countryOfPublic << " | ";
		os << strBook.yearOfPublication << " | ";
		os << right << setw(6) << fixed << setprecision(2) << strBook.bookPrice << " | ";
		os << strBook.description << endl;

		return os;
	};
}