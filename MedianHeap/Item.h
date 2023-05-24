#pragma once
#include "Item.h"
#include <string>
using namespace std;

class Item {
	int key;
	string data;
	int indexInOtherHeap;
public:
	Item(int _key, string _data) : key(_key), data(_data), indexInOtherHeap(-1) {};
	Item() : key(-1), data(""), indexInOtherHeap(-1) {};
	int getKey() const { return key; };
	string getData() const { return data; };
};