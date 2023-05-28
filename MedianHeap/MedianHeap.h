#pragma once
#include "Heap.h"
#include <iostream>

using namespace std;

class MedianHeap {
	Heap smallNumMaxHeap;
	Heap smallNumMinHeap;
	Heap bigNumMaxHeap;
	Heap bigNumMinHeap;
public:
	MedianHeap() : smallNumMaxHeap(Heap(MAX)), smallNumMinHeap(Heap(MIN)), 
		bigNumMaxHeap(Heap(MAX)), bigNumMinHeap(Heap(MIN)) {};
	void Max() { cout << bigNumMaxHeap.Top(); };
	void DeleteMax();
	void Min();
	void DeleteMin();
	void Insert(int key, string value);
	void Median();
	int getHeapSize() { return bigNumMaxHeap.getHeapSize() + smallNumMaxHeap.getHeapSize(); };
private:
	void InsertToBigNumHeap(int key, string value);
	void InsertToSmallNumHeap(int key, string value);
	Item DeleteFromMinBigHeapTop();
	Item DeleteFromMaxBigHeapTop();
	Item DeleteFromMinSmallHeapTop();
	Item DeleteFromMaxSmallHeapTop();
};

MedianHeap CreateEmpty();