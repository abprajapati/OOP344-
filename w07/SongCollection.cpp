
#define CRT_SECURE_NO_WARNINGS
#include "SongCollection.h"
#include <iomanip>
#include <list>
#include <string>
#include <algorithm>
#include <functional>
#include <fstream>


namespace sdds {

	
	SongCollection::SongCollection(std::string nameOfFile) 
	{
		Song Scol;
		std::ifstream file(nameOfFile);	
		if (file) 
		{
			
			while (!file.eof()) {
				std::string info{};

				std::getline(file, info);

				Scol.titleOfSong = info.substr(0, 25);
				Scol.titleOfSong = spaceRemoval(Scol.titleOfSong);

				Scol.artistOfSong = info.substr(25, 25);
				Scol.artistOfSong = spaceRemoval(Scol.artistOfSong);

				Scol.nameOfAlbum = info.substr(50, 25);
				Scol.nameOfAlbum = spaceRemoval(Scol.nameOfAlbum);

				std::string record{};
				record = info.substr(75, 5);
				if (record != "     ") 
				{
					Scol.releaseYear = std::stoi(record);
				}
				else 
				{
					Scol.releaseYear = 0;
				}

				Scol.lengthOfSong = std::stoi(info.substr(80, 5));

				Scol.m_price = std::stod(info.substr(85, 5));
				m_songs.push_back(Scol);

			}
		}
		else 
		{
			throw "EXCEPTION: ";
		}
	}

	void SongCollection::display(std::ostream& out) const 
	{
		size_t seconds, minutes, hours, total = 0;
		std::for_each( m_songs.begin(), m_songs.end(), [&](Song song) { out << song << std::endl; });
		std::for_each( m_songs.begin(), m_songs.end(), [&](auto song) { total += song.lengthOfSong; });

		seconds = total;
		minutes = seconds / 60;
		hours = minutes / 60;

		out << "----------------------------------------------------------------------------------------";
		out << std::endl;
		out << "|" << std::setw(78) << std::right << "Total Listening Time: " << hours << ":" << size_t(minutes % 60) << ":" << size_t(seconds % 60) << " |" << std::endl;
	}

	void SongCollection::cleanAlbum()
	{
		std::transform(m_songs.begin(), m_songs.end(), m_songs.begin(), [](Song& info)
			{
				Song record;
				if (info.nameOfAlbum == "[None]") {
					record.nameOfAlbum = "";
					record.artistOfSong = info.artistOfSong;
					record.m_price = info.m_price;
					record.lengthOfSong = info.lengthOfSong;
					record.titleOfSong = info.titleOfSong;
					record.releaseYear = info.releaseYear;
					return record;
				}
				return info;
			});
	}

	bool SongCollection::inCollection(std::string artistName) const
	{
		return std::any_of(m_songs.begin(), m_songs.end(), [&](Song info) {return info.artistOfSong == artistName; });
	}

	void SongCollection::sort(std::string nameOfField) 
	{
		if (nameOfField == "album") 
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song LEFT, const Song RIGHT) { return LEFT.nameOfAlbum < RIGHT.nameOfAlbum; });
		}
		else if (nameOfField == "title") 
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song LEFT, const Song RIGHT) { return LEFT.titleOfSong < RIGHT.titleOfSong; });
			
		}
		else if (nameOfField == "length") 
		{
			std::sort(m_songs.begin(), m_songs.end(), [](const Song LEFT, const Song RIGHT) { return LEFT.lengthOfSong < RIGHT.lengthOfSong; });
		}
	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artistName) const 
	{
		std::list<Song> artist(5);
		std::copy_if(m_songs.begin(), m_songs.end(), artist.begin(), [&](Song info) {return info.artistOfSong == artistName; });
		return artist;
	}

	std::string& SongCollection::spaceRemoval(std::string& info)
	{
		info = info.substr(info.find_first_not_of(" "));
		info = info.substr(0, info.find_last_not_of(" ") + 1);
		return info;
	}


	std::ostream& operator<<(std::ostream& out, const Song& theSong) 
	{
		out << "| " << std::left << std::setw(20) << theSong.titleOfSong;
		out << " | " << std::setw(15) << theSong.artistOfSong;
		out << " | " << std::setw(20) << theSong.nameOfAlbum;

		int keep = theSong.releaseYear;
		switch (keep)
		{
		case 0 :
			out << " | " << std::right << std::setw(6) << " ";
			break;
		default:
			out << " | " << std::right << std::setw(6) << keep;
		}

		int record = theSong.lengthOfSong;
		out << " | " << record / 60 << ":";
		if (record % 60 >= 10)
		{
			out << record % 60;
		}
		else 
		{
			out << "0" << record % 60;
		}

		out << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |";
		return out;
	}

	
}