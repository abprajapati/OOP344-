

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
			for (size_t i = 0; i < desc.size(); i++) {
				for (size_t j = 0; j < price.size(); j++) {
					if (desc[i].code == price[j].code) {
						Product* newPro = new Product(desc[i].desc, price[j].price);
						newPro->validate();
						priceList += newPro;
						delete newPro;
						newPro = nullptr;
						break;
					}
				}
			}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (size_t i = 0; i < desc.size(); i++) {
			for (size_t j = 0; j < price.size(); j++) {
				if (desc[i].code == price[j].code) {
					std::unique_ptr<Product> newPro(new Product(desc[i].desc, price[j].price));
					newPro->validate();
					priceList += newPro;
					break;
				}
			}
		}
		return priceList;
	}
}