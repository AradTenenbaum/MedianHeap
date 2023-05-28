#include "MedianHeap.h"

void MedianHeap::Insert(int key, string value) {
	if (smallNumMaxHeap.getHeapSize() > 0) {
		if (key > smallNumMaxHeap.Top().getKey()) {
			if (bigNumMaxHeap.getHeapSize() == smallNumMaxHeap.getHeapSize()) {
				InsertToBigNumHeap(key, value);
			}
			else if (smallNumMaxHeap.getHeapSize() < bigNumMaxHeap.getHeapSize()) {
				if (bigNumMinHeap.Top().getKey() < key) {
					Item minInBig = DeleteFromMinBigHeapTop();
					InsertToSmallNumHeap(minInBig.getKey(), minInBig.getData());
					InsertToBigNumHeap(key, value);
				}
				else {
					InsertToSmallNumHeap(key, value);
				}
			}
		}
		else if(key < smallNumMaxHeap.Top().getKey()) {
			if (bigNumMaxHeap.getHeapSize() > smallNumMaxHeap.getHeapSize()) {
				InsertToSmallNumHeap(key, value);
			}
			else if (bigNumMaxHeap.getHeapSize() == smallNumMaxHeap.getHeapSize()) {
				Item maxInSmall = DeleteFromMaxSmallHeapTop();
				InsertToBigNumHeap(maxInSmall.getKey(), maxInSmall.getData());
				InsertToSmallNumHeap(key, value);
			}
		}
	}
	else {
		if (bigNumMaxHeap.getHeapSize() > 0) {
			if (key > bigNumMinHeap.Top().getKey()) {
				Item minInBig = DeleteFromMinBigHeapTop();
				InsertToSmallNumHeap(minInBig.getKey(), minInBig.getData());
				InsertToBigNumHeap(key, value);
			}
			else {
				InsertToSmallNumHeap(key, value);
			}
		}
		else {
			InsertToBigNumHeap(key, value);
		}
	}
}

void MedianHeap::Median() {
	if (bigNumMaxHeap.getHeapSize() == smallNumMaxHeap.getHeapSize()) {
		cout << smallNumMaxHeap.Top();
	}
	else {
		cout << bigNumMinHeap.Top();
	}
}

void MedianHeap::Min() {
	if (smallNumMinHeap.getHeapSize() > 0) {
		cout << smallNumMinHeap.Top();
	}
	else {
		cout << bigNumMinHeap.Top();
	}
}

void MedianHeap::DeleteMax() {
	Item max = DeleteFromMaxBigHeapTop();
	if (bigNumMaxHeap.getHeapSize() < smallNumMaxHeap.getHeapSize()) {
		Item maxInSmall = DeleteFromMaxSmallHeapTop();
		InsertToBigNumHeap(maxInSmall.getKey(), maxInSmall.getData());
	}
	cout << max;
}

void MedianHeap::DeleteMin() {
	Item min;
	if (smallNumMinHeap.getHeapSize() > 0) {
		min = DeleteFromMinSmallHeapTop();
		if (bigNumMaxHeap.getHeapSize() == (smallNumMaxHeap.getHeapSize() + 2)) {
			Item minInBig = DeleteFromMinBigHeapTop();
			InsertToSmallNumHeap(minInBig.getKey(), minInBig.getData());
		}
	}
	else {
		min = DeleteFromMinBigHeapTop();
	}
	cout << min;
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

Item MedianHeap::DeleteFromMinBigHeapTop() {
	Item min = bigNumMinHeap.Top();
	bigNumMinHeap.DeleteTop();
	bigNumMaxHeap.DeleteIndex(min.getIndexInOtherHeap());
	return min;
}

Item MedianHeap::DeleteFromMinSmallHeapTop() {
	Item min = smallNumMinHeap.Top();
	smallNumMinHeap.DeleteTop();
	smallNumMaxHeap.DeleteIndex(min.getIndexInOtherHeap());
	return min;
}

Item MedianHeap::DeleteFromMaxBigHeapTop() {
	Item max = bigNumMaxHeap.Top();
	bigNumMaxHeap.DeleteTop();
	bigNumMinHeap.DeleteIndex(max.getIndexInOtherHeap());
	return max;
}

Item MedianHeap::DeleteFromMaxSmallHeapTop() {
	Item max = smallNumMaxHeap.Top();
	smallNumMaxHeap.DeleteTop();
	smallNumMinHeap.DeleteIndex(max.getIndexInOtherHeap());
	return max;
}

MedianHeap CreateEmpty() { 
	return MedianHeap(); 
}