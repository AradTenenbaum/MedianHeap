#include <iostream>
#include "Heap.h"
#include "MedianHeap.h"
#include "utils.h"
using namespace std;

int main() {
	int actionsNum;
	cin >> actionsNum;
	handleError(actionsNum <= 0);
	string buffer;
	string parameters;
	string first;
	string second;
	const int maxWords = 3;
	string words[maxWords];
	bool isInit = false;
	int key;
	MedianHeap h;
	for (int i = 0; i < (actionsNum); i++) {
		cin >> buffer;
		std::getline(std::cin, parameters);
		divideStringBySpace(parameters, first, second);
		handleError(!(buffer[0] >= 'a' && buffer[0] <= 'g') && buffer[0] != ' ');
		handleError(buffer[0] != 'e' && !isInit);
		handleError(buffer[0] != 'f' && (first.length() > 0 || second.length()));
		handleError(In(buffer[0], "abcdg") && (h.getHeapSize() == 0));

		if (buffer[0] == 'a') {
			h.Max();
		}
		else if (buffer[0] == 'b') {
			h.DeleteMax();
		}
		else if (buffer[0] == 'c') {
			h.Min();
		}
		else if (buffer[0] == 'd') {
			h.DeleteMin();
		}
		else if (buffer[0] == 'e') {
			handleError(isInit);

			h = CreateEmpty();
			isInit = true;
		}
		else if (buffer[0] == 'f') {
			handleError(!isNumber(first));
			key = stoi(first);
			h.Insert(key, second);
		}
		else if (buffer[0] == 'g') {
			h.Median();
		}
		first = "";
		second = "";
	}
	std::getline(std::cin, buffer);
	handleError(buffer != "");


	return 0;
}