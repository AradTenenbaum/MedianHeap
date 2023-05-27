#include "utils.h"
#include "Item.h"
#include <iostream>
using namespace std;

void swapItems(Item* a, Item* b) {
	int tempAIndex = a->getSelfIndex();
	int tempBIndex = b->getSelfIndex();

	Item temp = *a;
	*a = *b;
	*b = temp;

	a->setSelfIndex(tempBIndex);
	b->setSelfIndex(tempAIndex);
}