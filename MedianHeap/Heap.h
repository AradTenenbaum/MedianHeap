#pragma once
#include "Item.h"
enum {MAX, MIN};

class Heap {
	int type;
	Item data[100];
	int heapSize = 0;
public:
	Heap(int _type=MAX) : type(_type) {};
	Item Max() { return data[0]; };
	void Insert(Item newItem);
	void DeleteMax();
private:
	int getRightNodeKey(int index) { return data[2 * index + 1].getKey(); }
	int getLeftNodeKey(int index) { return data[2 * index + 2].getKey(); }
	int getParent(int index) { return data[(index - 1)/2].getKey(); };
	void goRight(int& index) { index = 2 * index + 1; };
	void goLeft(int& index) { index = 2 * index + 2; };
};