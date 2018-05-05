#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;


void displayArray(double * items, int start, int end)
{
	for (int i = start; i <= end; i++)
		cout << items[i] << " ";
	cout << endl;
}


int partition(double items[], int start, int end)
{
	int pIndex, j, k;
	double p;
	p = items[start];
	pIndex = start;
	j = start - 1;
	k = start;
	for (int i = start; i <= end; i++)
	{
		if (items[k] < p)
		{
			j++;
			swap(items[j], items[k]);
			if (items[k] == p)
			{
				pIndex = k;
			}
		}
		k++;
	}
	if (items[(end - 1)] > items[end])
	{
		swap(items[(end - 1)], items[end]);
		if (items[(end - 1)] == p)
		{
			pIndex = end - 1;
		}
	}
	return pIndex;
}



//The legendary "Blaze Sort" algorithm.
//Sorts the specified portion of the array between index start and end (inclusive)
//Hmmm... how fast is it?

void blazeSort(double * items, int start, int end)
{
if (end - start > 0)
{
int p = partition(items, start, end);
blazeSort(items, start, p - 1);
blazeSort(items, p + 1, end);
}
}


int main()
{
	////////////////////////////////////////////////////
	//Part 1:  Implement a method called partition.
	////////////////////////////////////////////////////

	//Paritition is a function that takes in an array and a range (start and end).
	//
	//Call the first item in the range the 'pivot'.
	//
	//Partition's job is to simply separate items within the range based on whether they are bigger or smaller than the pivot.
	//In the example array below, 13 is the pivot, so all items smaller than 13 are placed in indices 0-3.  The pivot is then placed at index 4, and all 
	//Remaining items, which are larger than the pivot, are placed at positions 5-10.  Note that the array is NOT sorted, just "partitioned" around
	//the pivot value.  After doing this, the function must return the new index of the pivot value.

	double testNumsA[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };

	//The partition will place all items <= 13 to the left of value 13, and all items large than 13 to the right of 13 in the array.
	int p = partition(testNumsA, 0, 10);
	cout << p << endl; //should be 4, the new index of 13.
	displayArray(testNumsA, 0, 10);  //should display something like this:  5 3 4.5 4 13 18.35 85 189 37.2 43 34.1

									 //One more example:
	double testNumsB[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };
	p = partition(testNumsB, 2, 6);  //Here we are only interested in items from indices 2-6, ie, 43, 189, 4, 4.5, 18.35
	cout << p << endl; //should be 5
	displayArray(testNumsB, 0, 10); //Notice only indices 2-6 have been partioned:  13 34.1 18.35 4 4.5 43 189 85 3 37.2 5


									/////////////////////////////////////////////////////////////////////////////////
									//Part 2:  Uncomment "Blaze Sort".
									//Blaze Sort uses/needs your partition to work properly.
									/////////////////////////////////////////////////////////////////////////////////


									//Test if Blaze Sort correctly sorts the following array.
	double testNums[] = { 13, 34.1, 43, 189, 4, 4.5, 18.35, 85, 3, 37.2, 5 };

	blazeSort(testNums, 0, 10);

	displayArray(testNums, 0, 10);

	/////////////////////////////////////////////////////////////////////
	//Part 3:  Test how fast Blaze Sort is for large arrays.
	//What do you think the run-time (big-Oh) of blaze sort is?
	/////////////////////////////////////////////////////////////////////

	//Stress test:
	int size = 10; //test with: 1000, 10000, 100000,1000000, 10000000
	double * numbers = new double[size];

	for (int i = 0; i < size; i++)
	{
		numbers[i] = rand();
	}

	clock_t startTime, endTime;

	startTime = clock();
	blazeSort(numbers, 0, size - 1);
	endTime = clock();

	//displayArray(numbers, 0, size - 1);
	cout << "Blaze sort took: " << endTime - startTime << " milliseconds to sort " << size << " doubles." << endl;
	
	return 0;
}