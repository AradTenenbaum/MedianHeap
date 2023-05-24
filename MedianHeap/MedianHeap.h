#pragma once
#include "Heap.h"

class MedianHeap {
	Heap smallNumMaxHeap;
	Heap bigNumMaxHeap;
	Heap bitNumMinHeap;
public:
	MedianHeap() : smallNumMaxHeap(Heap(MAX)), bigNumMaxHeap(Heap(MAX)), bitNumMinHeap(Heap(MIN)) {};
	MedianHeap CreateEmpty() { return MedianHeap(); };
	void Max();
	void DeleteMax();
	void Min();
	void DeleteMin();
	void Insert(int key, int value);
	void Median();
};