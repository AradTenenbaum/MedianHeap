#include "utils.h"
#include "Item.h"
#include <iostream>
using namespace std;

void swapItems(Item* a, Item* b) {
	Item temp = *a;
	*a = *b;
	*b = temp;
}