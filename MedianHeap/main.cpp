#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
	/*
	*/
	Heap h = Heap(MAX);
	h.Insert(Item(5, "test"));
	h.Insert(Item(10, "say"));
	h.Insert(Item(3, "helo"));
	h.Insert(Item(7, "you"));
	h.Insert(Item(12, "say"));
	h.DeleteTop();
	h.Insert(Item(17, "say"));
	h.Insert(Item(14, "say"));

	return 0;
}