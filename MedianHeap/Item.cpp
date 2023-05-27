#include "Item.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& os, const Item& item) {
	os << "Key: " << item.getKey() << " Data: " << item.getData() << endl;
	return os;
}