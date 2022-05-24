
#ifndef COLLECTION_H_
#define COLLECTION_H_

#include <iomanip>
#include <string>

namespace sdds {

	template<typename T>
	class Collection 
	{
		T* arrayOfItem{};
		std::string nameOfCollection{};
		size_t collecSize = 0;
		void (*observer)(const Collection<T>&, const T&) { nullptr };

	public:
		Collection(const std::string& name) 
		{
			nameOfCollection = name;
			collecSize = 0;
			arrayOfItem = nullptr;
			observer = nullptr;
		};
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		Collection& operator=(Collection&&) = delete;
		Collection(Collection&&) = delete;

		~Collection() 
		{
			delete[] arrayOfItem;
			arrayOfItem = nullptr;
		};

		const std::string& name() const 
		{
			return nameOfCollection;
		};

		 size_t size() const 
		 {
			return collecSize;
		 };

		void setObserver(void (*observer)(const Collection<T>&, const T&)) 
		{
			this->observer = observer;
		};

		T* operator[](const std::string& title) const
		{
			bool record = false;
			T* temp{};
			size_t i = 0;
			while (i < size()) {
				if (arrayOfItem[i].title() == title) {
					record = true;
					temp = &arrayOfItem[i];
				}
				i++;
			};

			if (record == false) {
				return nullptr;
			}
			else {
				return temp;
			}
		};

		Collection<T>& operator+=(const T& item) 
		{
			bool record = false;
			
			for (size_t i = 0; i < size(); i++) {
				if (arrayOfItem[i].title() == item.title()) {
					record = true;
				}
			}
			

			if (record == false) {
				T* temp = nullptr;
				temp = new T[collecSize + 1];
				size_t i = 0;
				while (i < collecSize) {
					temp[i] = arrayOfItem[i];
					i++;
				};
				temp[collecSize] = item;
				collecSize++;
				delete[] arrayOfItem;
				arrayOfItem = temp;
			}

			if (record == false && observer) {
				observer(*this, item);
			}
			return *this;
		};

		T& operator[](size_t idx) const 
		{
			if (idx < collecSize && idx >= 0) {
				return arrayOfItem[idx];
			}
			else {
				throw std::out_of_range("** EXCEPTION: Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(collecSize) + "] items.");
			}
		};


		friend std::ostream& operator<<(std::ostream& os, const Collection& c) 
		{
			size_t i = 0;
			while (i < c.size()) {
				os << c.arrayOfItem[i];
				i++;
			};
		
			return os;
		};
	};
	template<typename T>
    std::ostream& operator<<(std::ostream& os, const Collection<T>& c) 
	{
		size_t i = 0;
		while (i < c.size()) {
			os << c[i];
			i++;
		};
		return os;
	};
}


#endif // !COLLECTION_H_
