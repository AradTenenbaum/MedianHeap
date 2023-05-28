#include "utils.h"
#include "Item.h"
#include <iostream>
using namespace std;

void swapItems(Item* a, Item* b) {
	int tempAIndex = a->getSelfIndex();
	int tempBIndex = b->getSelfIndex();

	Item temp = *a;
	*a = *b;
	*b = temp;

	a->setSelfIndex(tempAIndex);
	b->setSelfIndex(tempBIndex);

	if(b->getSharedItem() != nullptr) b->getSharedItem()->setSharedItem(b);
	if (a->getSharedItem() != nullptr) a->getSharedItem()->setSharedItem(a);
}

bool isDigit(char c) {
	return (c >= '0' && c <= '9');
}

bool isNumber(string s) {
	for (int i = 0; i < s.length(); i++) {
		if (!isDigit(s[i]) && (i == 0 && s[i] != '-')) {
			return false;
		}
	}
	return true;
}

void handleError(bool condition) {
	if (condition) {
		cout << "wrong input";
		exit(1);
	}
}

void divideStringBySpace(const string& input, string& first, string& second) {
	string word;
	int i = 0;
	for (char c : input) {
		if (c == ' ' && i < 1) {
			if (!word.empty()) {
				first = word;
				i++;
				word.clear();
			}
		}
		else {
			word += c;
		}
	}
	if (!word.empty()) {
		second = word;
		word.clear();
	}
}

bool In(char src, string list) {
	for (char c : list) {
		if (c == src) {
			return true;
		}
	}
	return false;
}