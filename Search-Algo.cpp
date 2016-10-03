#include "stdafx.h"
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
	int minRange;
	int maxRange;
	void swapInfo(int first, int second);
public:
	void setRandomNumers(int numOfNums, int min, int max);
	int getNum(int index);
	int getSize();
	void bubbleSort();
	int binarySearch(int x);
};

/*
Set new random numbers in the vector (array)
*/
void Search::setRandomNumers(int arrySize, int min, int max) {
	dataSize = arrySize;
	minRange = min;
	maxRange = max;
	numbers.reserve(dataSize);
	for (int i = 0; i < arrySize; i++) {
		int randomNum = rand() % max + min;
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
Bubble sort the vector
*/
void Search::bubbleSort() {
	for (int i = dataSize - 1; i >= 0; i--) {
		for (int j = 1; j <= i; j++) {
			if (numbers.at(j) < numbers.at(j - 1)) {
				swapInfo(j, j - 1);
			}
		}
	}
}

/*
@param
	first: the index in the array for the first number
@param
	second: the index in the array for the second number
*/
void Search::swapInfo(int first, int second) {
	int temp = numbers.at(first);
	numbers.at(first) = numbers.at(second);
	numbers.at(second) = temp;
}

/*
Binary search for the number specified
*/
int Search::binarySearch(int findNum) {
	int upperBound = dataSize - 1;
	int lowerBound = 0;
	int midPoint;
	
	bool found = false;

	while (!found) {
		midPoint = lowerBound + (upperBound - lowerBound) / 2;

		if (lowerBound > upperBound) {
			break;
		}

		if (numbers.at(midPoint) > findNum) {
			upperBound = midPoint;
		}
		
		if(numbers.at(midPoint) < findNum){
			lowerBound = midPoint;
		}

		if (numbers.at(midPoint) == findNum) {
			found = true;
		}
	}

	return midPoint;
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
	int foundAt;
	binarySearch.setRandomNumers(10, 0, 10);
	binarySearch.bubbleSort();
	printOutVector(binarySearch);
	foundAt = binarySearch.binarySearch(7);
	cout << "The item was found at " << foundAt << newline;
}