

#define _CRT_SECURE_NO_WARNIGS
#include <iostream>
#include <fstream>
#include "StringSet.h"
using namespace std;
namespace sdds {
	StringSet::StringSet() {};

	StringSet::StringSet(const char* name) 
	{
		delete[] array;
		array = nullptr;
		totalString = 0;
		int record;
		record = name != nullptr && name[0] != '\0';
		
		switch(record)
		{
		case 1: ifstream FILE;
			FILE.open(name);
			string temp;
			while (!FILE.eof()) {
					getline(FILE, temp, ' ');
					totalString++;
			}
			FILE.clear();
			FILE.seekg(0);
			array = new string[totalString];
			while (!FILE.eof()) {
				size_t i = 0;
		
				while(i < totalString)
				{
					getline(FILE, array[i], ' ');
					i++;
				}
			}
			FILE.close();
			break;
		}
	}

	StringSet::~StringSet() 
	{
		delete[] array;
		array = nullptr;
	}

	size_t StringSet::size() 
	{
		return totalString;
	}

	string StringSet::operator[](size_t index) 
	{
		string temp = {};
		int record;
		record = array != nullptr && index < totalString;
		switch(record)
		{
		case 1:
			temp = array[index];
			break;
		}
		return temp;
	}

	StringSet::StringSet(const StringSet& S) 
	{
		*this = S;
	}

	StringSet& StringSet::operator=(const StringSet& S) 
	{
		int record;
		record = this != &S;
		switch(record)
		{
		case 1:
			delete[] array;
			array = nullptr;
			totalString = S.totalString;
			array = new string[totalString];
			size_t i = 0;
			while(i < totalString)
			{
				array[i] = S.array[i];
				i++;
			}
			break;
		}
		return *this;
	}

	StringSet::StringSet(StringSet&& S)noexcept 
	{
		*this = move(S);
	}
	StringSet& StringSet::operator=(StringSet&& S)noexcept 
	{
		int record;
		record = this != &S;
		switch(record)
		{
		case 1:
			delete[] array;
			array = nullptr;
			array = S.array;
			totalString = S.totalString;
			S.array = nullptr;
			S.totalString = 0;
			break;
		}
		return *this;
	}
}