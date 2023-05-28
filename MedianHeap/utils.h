#pragma once
#include "utils.h"
#include "Item.h"

void swapItems(Item* a, Item* b);
bool isNumber(string s);
void handleError(bool condition);
void divideStringBySpace(const string& input, string& first, string& second);
bool In(char src, string list);