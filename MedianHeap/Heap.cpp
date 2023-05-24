#include "Heap.h"
#include "Item.h"
#include "utils.h"

bool Heap::compare(int ind1, int ind2) {
	if (ind1 == -1 || ind2 == -1) return false;
	if (type == MAX) return data[ind1].getKey() < data[ind2].getKey();
	else return data[ind1].getKey() > data[ind2].getKey();
}

void Heap::Insert(Item newItem) {
	int index = heapSize;
	data[heapSize++] = newItem;
	int parentIndex = getParentIndex(index);
	while (compare(parentIndex, index))
	{
		swapItems(&data[parentIndex], &data[index]);
		index = parentIndex;
		parentIndex = getParentIndex(index);
	}
}


void Heap::DeleteTop() {
	if (heapSize != 0) {
		heapSize--;
		swapItems(&data[0], &data[heapSize]);
		int index = 0;
		int rightIndex = getRightNodeKeyIndex(index);
		int leftIndex = getLeftNodeKeyIndex(index);

		while ((compare(index, rightIndex) || compare(index, leftIndex)) && 
			(leftIndex < heapSize && rightIndex < heapSize)) {
			if (compare(rightIndex, leftIndex)) {
				swapItems(&data[leftIndex], &data[index]);
				index = leftIndex;
			}
			else {
				swapItems(&data[rightIndex], &data[index]);
				index = rightIndex;
			}
			rightIndex = getRightNodeKeyIndex(index);
			leftIndex = getLeftNodeKeyIndex(index);
		}
	}
}