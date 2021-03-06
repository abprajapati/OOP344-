#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "List.h"
#include "Element.h"
#include <algorithm>

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif