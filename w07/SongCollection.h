
#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H

#include <iostream>
#include <list>
#include <vector>

namespace sdds {

	struct Song 
	{  
		std::string artistOfSong;
        std::string titleOfSong;
		std::string nameOfAlbum;
		double m_price;
		size_t releaseYear;
		size_t lengthOfSong;
	};

	class SongCollection {
		std::vector<Song> m_songs;
	public:
		SongCollection(std::string nameOfFile);
		void display(std::ostream& out) const;
		void sort(std::string nameOfField);
		void cleanAlbum();
		bool inCollection(std::string artistName) const;
		std::list<Song> getSongsForArtist(std::string artistName) const;
		std::string& spaceRemoval(std::string&);

	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif