

#ifndef SPELLCHECKER_H_
#define SPELLCHECKER_H_

#include <iomanip>
namespace sdds {

	class SpellChecker 
	{
		std::string m_badWords[6];
		std::string m_goodWords[6];
		size_t count[6]{};

	public:
		SpellChecker(const char* filename = nullptr);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}

#endif // !SPELLCHECKER_H_
