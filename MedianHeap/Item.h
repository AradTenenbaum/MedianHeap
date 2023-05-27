#pragma once
#include "Item.h"
#include <string>
using namespace std;

class Item {
	int key;
	string data;
	Item* sharedItem;
	int selfIndex;
public:
	Item(int _key, string _data) : key(_key), data(_data), sharedItem(nullptr), selfIndex(-1) {};
	Item(int _key, string _data, Item* _sharedItem) : key(_key), data(_data), sharedItem(_sharedItem), selfIndex(-1) {};
	Item(int _key, string _data, Item* _sharedItem, int _selfIndex) : key(_key), 
		data(_data), sharedItem(_sharedItem), selfIndex(_selfIndex) {};
	Item() : key(-1), data(""), sharedItem(nullptr), selfIndex(-1) {};
	int getKey() const { return key; };
	string getData() const { return data; };
	int getSelfIndex() { return selfIndex; };
	void setSelfIndex(int num) { selfIndex = num; };
	int getIndexInOtherHeap() { return sharedItem->getSelfIndex(); };
	void setSharedItem(Item* _sharedItem) { sharedItem = _sharedItem; };
	friend ostream& operator<< (ostream& os, const Item& item);
};