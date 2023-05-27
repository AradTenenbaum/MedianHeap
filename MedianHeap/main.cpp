#include <iostream>
#include "Heap.h"
#include "MedianHeap.h"
using namespace std;

int main() {
	/*
	*/
	MedianHeap h = MedianHeap();
	h.Insert(5, "test");
	h.Insert(10, "say");
	h.Insert(3, "helo");
	h.Insert(7, "you");
	h.Insert(12, "say");
	h.Insert(17, "say");
	h.Insert(14, "say");


	return 0;
}