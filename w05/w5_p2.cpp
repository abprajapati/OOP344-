#include <iostream>
#include <iomanip>
#include <fstream>
#include "Collection.h"
#include "Collection.h"
#include "Book.h"
#include "Book.h"
#include "Movie.h"
#include "Movie.h"
#include "SpellChecker.h"
#include "SpellChecker.h"

using namespace sdds;

enum AppErrors
{
	CannotOpenFile = 1, // An input file cannot be opened
	BadArgumentCount = 2, // The application didn't receive anough parameters
};

// The observer function for adding books to the collection:
//   should be called every time a new book is added to the collection
void bookAddedObserver(const Collection<Book>& theCollection,
	const Book& theBook)
{
	std::cout << "Book \"" << theBook.title() << "\" added!\n";
}

// The observer function for adding movies to the collection:
//   should be called every time a new movie is added to the collection
void movieAddedObserver(const Collection<Movie>& theCollection,
	const Movie& theMovie)
{
	std::cout << "Movie \"" << theMovie.title()
		<< "\" added to collection \"" << theCollection.name()
		<< "\" (" << theCollection.size() << " items).\n";
}

// ws books.txt movies.txt file_missing.txt file_words.txt
int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	// get the books
	sdds::Collection<sdds::Book> library("Bestsellers");
	size_t cnt = 0;
	if (argc == 5) {
		std::ifstream file(argv[1]);
		if (file)
		{
			std::string strBook;
			if (!file)
			{
				std::cerr << "ERROR: Incorrect number of arguments.\n";
				exit(AppErrors::BadArgumentCount);

			}
			else
			{
				while (cnt < 4)
				{
					std::getline(file, strBook);
					if (!strBook.empty())
					{
						if (strBook[0] != '#')
						{
							library += Book(strBook);
							cnt++;
						}
					}
				}

				library.setObserver(bookAddedObserver);

				while (std::getline(file, strBook))
				{
					if (!strBook.empty())
					{
						if (strBook[0] != '#')
						{
							library += Book(strBook);
							cnt++;
						}
					}
				}
				
			}
			
		}
		else 
		{
			std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
			exit(AppErrors::CannotOpenFile);
		}
			double usdToCad = 1.3;
			double gbpToCad = 1.5;

			auto update = [=](Book& strBook)
			{
				if (strBook.country() == "UK")
				{
					if (strBook.year() <= 1999 && strBook.year() >= 1990)
					{
						strBook.price() *= gbpToCad;
					}
				}
				if (strBook.country() == "US")
				{
					strBook.price() *= usdToCad;
				}
				
				return strBook.price();
			};


			std::cout << "-----------------------------------------\n";
			std::cout << "The library content\n";
			std::cout << "-----------------------------------------\n";
			std::cout << library;
			std::cout << "-----------------------------------------\n\n";

			// TODO (from part #1): iterate over the library and update the price of each book
			//         using the lambda defined above.
			size_t i = 0;
			while (i < cnt) {
				update(library[i]);
				i++;
			};

			std::cout << "-----------------------------------------\n";
			std::cout << "The library content (updated prices)\n";
			std::cout << "-----------------------------------------\n";
			std::cout << library;
			std::cout << "-----------------------------------------\n\n";

			Collection<Movie> theCollection("Action Movies");

			// Process the file
			Movie movies[5];
			if (argc > 2) {
				// TODO: load 5 movies from the file "argv[2]".
				//       - read one line at a time, and pass it to the Movie constructor
				//       - store each movie read into the array "movies"
				//       - lines that start with "#" are considered comments and should be ignored

				std::ifstream file(argv[2]);
				size_t cnt2 = 0;
				if (file)
				{
					std::string strMovie;

					if (file)
					{
						while (cnt2 < 5)
						{
							std::getline(file, strMovie);
							if (!strMovie.empty())
							{
								if (strMovie[0] != '#')
								{
									movies[cnt2++] = Movie(strMovie);
								}
							}
						}

					}
					
				}
				else
				{
					std::cerr << "ERROR: Cannot open file [" << argv[1] << "].\n";
					exit(AppErrors::CannotOpenFile);

				}

				std::cout << "-----------------------------------------\n";
				std::cout << "Testing addition and callback function\n";
				std::cout << "-----------------------------------------\n";
				if (argc > 2)
				{
					// Add a few movies to collection; no observer is set
					((theCollection += movies[0]) += movies[1]) += movies[2];
					theCollection += movies[1];
					// add more movies; now we get a callback from the collection
					theCollection.setObserver(movieAddedObserver);
					theCollection += movies[3];
					theCollection += movies[3];
					theCollection += movies[4];
				}
				else
				{
					std::cout << "** No movies in the Collection\n";
				}
				std::cout << "-----------------------------------------\n\n";

				std::cout << "-----------------------------------------\n";
				std::cout << "Testing exceptions and operator[]\n";
				std::cout << "-----------------------------------------\n";

				bool record = true;
				for (auto i = 0u; i < 10; i++)
				{
					if (record) {
						try
						{
							std::cout << theCollection[i];
						}
						catch (const std::out_of_range& msg) {
							record = false;
							std::cerr << msg.what() << std::endl;
						}
					}
				}

				std::cout << "-----------------------------------------\n\n";


				std::cout << "-----------------------------------------\n";
				std::cout << "Testing the functor\n";
				std::cout << "-----------------------------------------\n";
				for (auto i = 3; i < argc; ++i)
				{

					try {
					      SpellChecker sp(argv[i]);
						  for (auto j = 0u; j < library.size(); ++j)
							  library[j].fixSpelling(sp);
						      sp.showStatistics(std::cout);
						  for (auto j = 0u; j < theCollection.size(); ++j)
								theCollection[j].fixSpelling(sp);
							sp.showStatistics(std::cout);
						}
						catch (const char* msg) {
							std::cerr << msg << std::endl;
						}


				}
				if (argc < 3)
				{
					std::cout << "** Spellchecker is empty\n";
					std::cout << "-----------------------------------------\n";
				}
				std::cout << "\n";

				std::cout << "=========================================\n";
				std::cout << "Wrapping up this workshop\n";
				std::cout << "--------------- Movies ------------------\n";
				std::cout << theCollection;
				std::cout << "--------------- Books -------------------\n";
				std::cout << library;
				std::cout << "-----------------------------------------\n";
				std::cout << "Testing operator[] (the other overload)\n";
				std::cout << "-----------------------------------------\n";
				const Movie* aMovie = theCollection["Terminator 2"];
				if (aMovie == nullptr)
					std::cout << "** Movie Terminator 2 not in collection.\n";
				aMovie = theCollection["Dark Phoenix"];
				if (aMovie != nullptr)
					std::cout << "In this collection:\n" << *aMovie;
				std::cout << "-----------------------------------------\n\n";

				return 0;
			}
		}
	}
