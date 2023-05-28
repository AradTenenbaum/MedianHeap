#include "Heap.h"
#include "Item.h"
#include "utils.h"

bool Heap::compare(int ind1, int ind2) {
	if (ind1 == -1 || ind2 == -1) return false;
	if (type == MAX) return data[ind1].getKey() < data[ind2].getKey();
	else return data[ind1].getKey() > data[ind2].getKey();
}

Item* Heap::Insert(Item newItem) {
	int index = heapSize;
	data[heapSize++] = newItem;
	data[index].setSelfIndex(index);
	int parentIndex = getParentIndex(index);
	while (compare(parentIndex, index) && index != 0)
	{
		swapItems(&data[parentIndex], &data[index]);
		index = parentIndex;
		parentIndex = getParentIndex(index);
	}
	return &data[index];
}


void Heap::DeleteTop() {
	if (heapSize != 0) {
		heapSize--;
		swapItems(&data[0], &data[heapSize]);
		int index = 0;
		int rightIndex = getRightNodeKeyIndex(index);
		int leftIndex = getLeftNodeKeyIndex(index);

		while (((compare(index, rightIndex) && rightIndex < heapSize) ||
			(compare(index, leftIndex) && leftIndex < heapSize))) {
			if (!(leftIndex < heapSize) || !(rightIndex < heapSize)) {
				if (!(leftIndex < heapSize)) {
					swapItems(&data[rightIndex], &data[index]);
					index = rightIndex;
				}
				else if (!(rightIndex < heapSize)) {
					swapItems(&data[leftIndex], &data[index]);
					index = leftIndex;
				}
			}
			else if (compare(rightIndex, leftIndex)) {
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


void Heap::DeleteIndex(int index) {
	if (heapSize != 0) {
		heapSize--;
		swapItems(&data[index], &data[heapSize]);
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

Item Heap::Top() {
	return data[0];
}