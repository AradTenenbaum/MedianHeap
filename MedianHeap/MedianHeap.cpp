#include "MedianHeap.h"

void MedianHeap::Insert(int key, string value) {
	if (key > smallNumMaxHeap.Top().getKey()) {
		if (bigNumMaxHeap.getHeapSize() == smallNumMaxHeap.getHeapSize()) {
			InsertToBigNumHeap(key, value);
		}
		else if (smallNumMaxHeap.getHeapSize() < bigNumMaxHeap.getHeapSize()) {
			Item minInBig = DeleteFromMinHeapTop(bigNumMinHeap, bigNumMaxHeap);
;			InsertToSmallNumHeap(minInBig.getKey(), minInBig.getData());
			InsertToBigNumHeap(key, value);
		}
	}
	else if(key < smallNumMaxHeap.Top().getKey()) {
		if (bigNumMaxHeap.getHeapSize() > smallNumMaxHeap.getHeapSize()) {
			InsertToSmallNumHeap(key, value);
		}
		else if (bigNumMaxHeap.getHeapSize() == smallNumMaxHeap.getHeapSize()) {
			Item maxInSmall = DeleteFromMaxHeapTop(smallNumMinHeap, smallNumMaxHeap);
			InsertToBigNumHeap(maxInSmall.getKey(), maxInSmall.getData());
			InsertToSmallNumHeap(key, value);
		}
	}
}

void MedianHeap::InsertToBigNumHeap(int key, string value) {
	Item* maxItem = bigNumMaxHeap.Insert(Item(key, value));
	Item* minItem = bigNumMinHeap.Insert(Item(key, value, maxItem));
	bigNumMaxHeap.setSharedItem(maxItem->getSelfIndex(), minItem);
}

void MedianHeap::InsertToSmallNumHeap(int key, string value) {
	Item* maxItem = smallNumMaxHeap.Insert(Item(key, value));
	Item* minItem = smallNumMinHeap.Insert(Item(key, value, maxItem));
	smallNumMaxHeap.setSharedItem(maxItem->getSelfIndex(), minItem);
}

Item MedianHeap::DeleteFromMinHeapTop(Heap& minHeap, Heap& maxHeap) {
	Item min = minHeap.Top();
	minHeap.DeleteTop();
	maxHeap.DeleteIndex(min.getIndexInOtherHeap());
	return min;
}

Item MedianHeap::DeleteFromMaxHeapTop(Heap& minHeap, Heap& maxHeap) {
	Item max = maxHeap.Top();
	maxHeap.DeleteTop();
	minHeap.DeleteIndex(max.getIndexInOtherHeap());
	return max;
}