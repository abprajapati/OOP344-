
#include "SpellChecker.h"
#include <fstream>
#include <string>

using namespace std;
namespace sdds {

	SpellChecker::SpellChecker(const char* filename) 
	{
		size_t i = 0; 
		string str;
		ifstream file(filename);

		if (file) {
			while (file) {
				getline(file, str);
				if (file) {
					m_badWords[i] = str.substr(0, str.find(" "));
					str.erase(0, str.find(" ") + 1);
					m_goodWords[i] = str.substr(0, str.find("\n"));
					m_goodWords[i] = m_goodWords[i].substr(m_goodWords[i].find_first_not_of(" "));
					str.erase(0, str.find("\n"));
					i++;
				}
			} 
			file.close();
			
		}
		else {
			throw "** EXCEPTION: Bad file name!";
		}
	}

	void SpellChecker::showStatistics(std::ostream& out) const 
	{
		out << "Spellchecker Statistics" << endl;
		size_t i = 0;
		
		while (i < 6)
		{
			out << right << setw(15) << m_badWords[i] << ": " << count[i] << " replacements" << endl;
			i++;
		}
	};

	void SpellChecker::operator()(std::string& text) 
	{
		size_t i = 0;
		
		while (i < 6)
			{
			while (text.find(m_badWords[i]) != string::npos)
			{
				text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				count[i]++;
			}
			i++;
			}
	}

	
}