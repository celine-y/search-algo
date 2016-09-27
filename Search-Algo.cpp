#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char newline = '\n';

class Search {
	vector<int> numbers;
	int dataSize;
public:
	void setRandomNumers(int numOfNums);
	int getNum(int index);
	int getSize();
};

void Search::setRandomNumers(int arrySize) {
	dataSize = arrySize;
	numbers.reserve(dataSize);
	for (int i = 0; i < arrySize; i++) {
		int randomNum = rand() % 100 + 1;
		numbers.push_back(randomNum);
	}
}

int Search::getSize() {
	return dataSize;
}

int Search::getNum(int index) {
	return numbers.at(index);
}

void printOutVector(Search searchType) {
	for (int i = 0; i < searchType.getSize(); i++) {
		cout << searchType.getNum(i) << newline;
	}
}

int main() {
	Search binarySearch;
	binarySearch.setRandomNumers(90);
	printOutVector(binarySearch);
}