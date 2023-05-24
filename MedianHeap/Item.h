#pragma once
#include <string>
using namespace std;

class Item {
	int key;
	string data;
public:
	Item(int _key, string _data) : key(_key), data(_data) {}
	Item()=default;
	int getKey() const { return key; };
	string getData() const { return data; };
};