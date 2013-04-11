//============================================================================
// Name        : pivot.cpp
// Author      : Alejandro Alcalde <algui91@gmail.com>
// Version     :
// Copyright   : GPLv3
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define SIZE 7

using namespace std;

vector<int> A(SIZE, 0);

int
getRandom() {
	return rand() % 10;
}

void
populateVector() {
	generate(A.begin(), A.end(), getRandom);
}

void swapValue(int a, int b){
	int temp = A[a];
	A[a] = A[b];
	A[b] = temp;
}

void
printArray() {
	for (std::vector<int>::iterator it = A.begin(); it != A.end(); ++it)
		std::cout << ' ' << *it;
	cout << endl;
}

/**
 * Find and returns the median of an array
 */
void
pivot(int i, int j, int &l) {
	int p = A[i]; /* Take as pivot the first element */
	int k = i;

	l = j;

	while( (A[k] <= p) | (k < j) ) k++;
	while(A[l] > p) l--;

	while(k < l){
		swapValue(k,l);
		while(A[k] <= p) k++;
		while(A[l] > p) l--;
	}
	swapValue(i, l);
}

int
select(int s){
	int i = 0;
	int j = A.size() - 1;
	int l = 0;

	while (l != s){
		pivot(i, j, l);
		printArray();
		if (s < l)
			j = l-1;
		else if(s > l)
			i = l+1;
	}

	return A[l];
}

int
main() {
	srand(time(NULL));
	populateVector();
	cout << "Original Vector: "; printArray();
	int s = ceil(SIZE/2);
	cout << "Median of A: " << select(s) << endl;

	return 0;
}
