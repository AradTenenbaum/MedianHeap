#pragma once
#include "Item.h"
enum {MAX, MIN};

class Heap {
	int type;
	Item data[100];
	int heapSize = 0;
public:
	Heap(int _type=MAX) : type(_type) {};
	Item Top() { return data[0]; };
	void Insert(Item newItem);
	void DeleteTop();
private:
	int getLeftNodeKeyIndex(int index) { return 2 * index + 1; }
	int getRightNodeKeyIndex(int index) { return 2 * index + 2; }
	int getParentIndex(int index) { return (index - 1) / 2; };
	void goRight(int& index) { index = 2 * index + 1; };
	void goLeft(int& index) { index = 2 * index + 2; };
	bool compare(int ind1, int inde2);
};