#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char newline = '\n';

/*
New search class which holds all the search algorithms
*/
class Search {
	vector<int> numbers;
	int dataSize;
public:
	void setRandomNumers(int numOfNums);
	int getNum(int index);
	int getSize();
};

/*
Set new random numbers in the vector (array)
*/
void Search::setRandomNumers(int arrySize) {
	dataSize = arrySize;
	numbers.reserve(dataSize);
	for (int i = 0; i < arrySize; i++) {
		int randomNum = rand() % 100 + 1;
		numbers.push_back(randomNum);
	}
}

/*
Grab the size of the vector
*/
int Search::getSize() {
	return dataSize;
}

/*
Grab the number at the reqested index
*/
int Search::getNum(int index) {
	return numbers.at(index);
}

/*
Function to printout each element (mainly for testing)
*/
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