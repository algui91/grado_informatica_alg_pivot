//============================================================================
// Name        : pivot.cpp
// Author      : Alejandro Alcalde <algui91@gmail.com>
// Version     :
// Copyright   : GPLv3
// Description : Pivot, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sys/time.h>

#define SIZE 1000000
#define MEASURE_PIVOT 1 /* Print execution time in us */
#define PRINT_VECTOR 0	/* Set to true for print the array's reordering */

using namespace std;

vector<int> A(SIZE, 0);

int
getRandom() {
	return rand() % 1024;
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

	l = j + 1;

	do k++; while( !(A[k] > p || k >= j) );
	do l--; while(!(A[l] <= p));

	while(k < l){
		swapValue(k,l);
		do k++; while(!(A[k] > p));
		do l--; while(!(A[l] <= p));
	}
	swapValue(i, l);
}

int
select(int s){
	int i = 0;
	int j = A.size() - 1;
	int l = 0;

	do {
		pivot(i, j, l);
#if PRINT_VECTOR
		printArray();
#endif
		if (s < l)
			j = l - 1;
		else if (s > l)
			i = l + 1;
	}
	while ( !(l == s) );

	return A[l];
}

int
crono(int (*func)(int), int s) {
	struct timeval tv1, tv2; /* gettimeofday() secs-usecs */
	long tv_usecs; 		 /* y sus cuentas */

	gettimeofday(&tv1, NULL);
	int result = func(s);
	gettimeofday(&tv2, NULL);

	tv_usecs = (tv2.tv_sec - tv1.tv_sec) * 1E6
	                + (tv2.tv_usec - tv1.tv_usec);

	cout << "Measured execution time " << tv_usecs << " us" << endl;

	return result;
}

int
main() {
	srand(time(NULL));
	populateVector();
	cout << "Original Vector: "; printArray();
	int s = ceil(SIZE/2);
	int resultado;

#if MEASURE_PIVOT
	resultado = crono(select, s);
#else
	resultado = select(s);
#endif

	cout << "Median of A: " << resultado;

	return 0;
}
