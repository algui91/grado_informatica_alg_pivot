//============================================================================
// Name        : pivot.cpp
// Author      : Alejandro Alcalde <algui91@gmail.com>
// Version     :
// Copyright   : GPLv3
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdlib> /* For RAND_MAX */
#include <algorithm>
#include <time.h>

using namespace std;

int getRandom() {
	return rand() % 1024;
}

vector<int> A(256, 0);

int
main()
{
	srand(time(NULL));

	//A.reserve(256);
	generate(A.begin(), A.end(), getRandom);
	for (std::vector<int>::iterator it = A.begin(); it != A.end();
	                ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}

void
populateVector(vector<int>& a)
{

}

/**
 * Find and returns the median of an array
 */
int
pivot(int i, int j, int l)
{
	int p = 0;
	int k = 0;

}
