#include "stdafx.h"
#include<iostream>
using namespace std;

void swap(int items[], int i, int index)
{
	int small = items[index];
	int big = items[i];

	items[index] = big;
	items[i] = small;


}

int locateSmall(int items[], int min, int max)
{
	int small = items[min];
	int index = min;

	for (int i = min; i < max; i++)
	{
		if (items[i] < small)
		{
			small = items[i];
			index = i;
		}
	}
	return index;

}

void sort(int items[], int n)
{
	int small = items[0];
	int index = 0;

	for (int i = 0; i<n; i++)
	{
		index = locateSmall(items, i, n);
		swap(items, i, index);


	}
}



void printItems(int items[], int size)
{
	for (int i = 0; i <size; i++)
	{
		cout << items[i] << endl;
	}
}
int main()
{
	int items[] = { 52, 17, 38, 58, 1238, 4, 13, 53, 12 ,85, 11, 388, 3, 0, 19 };



	cout << locateSmall(items, 0, 14) << endl; // 13
	cout << locateSmall(items, 5, 8) << endl; // 5

	cout << endl << endl;
	//print items in array
	printItems(items, 15); //should print 52, 17, 38...etc.
	cout << endl << endl;
	//sort given array
	sort(items, 15);
	cout << endl << endl;
	printItems(items, 15); //should print 0, 3, 4, ...etc.
	cout << endl << endl;
	return 0;
}



