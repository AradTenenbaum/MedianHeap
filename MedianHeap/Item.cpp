#include "Item.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const Item& item) {
	os << item.getKey() << " " << item.getData() << endl;
	return os;
}