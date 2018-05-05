#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <queue> //This is the STL's efficient implementation of a priority queue using a min heap
using namespace std;


//What is the big-oh run time of this sorting routine with respect
//to the number of items n?
//How does this compare to bubble sort or selection sort?

class priorityQueue
{
public:
	double items[100];
	int numItems;

	priorityQueue()
	{
		numItems = 0;
	}

	void insert(int n)
	{
		items[numItems] = n;
		numItems++;
	}

	double extractMin()
	{
		int minLocation = 0;
		int min = items[0];
		for (int i = 0; i < numItems; i++)
		{
			if (items[i] < min)
			{
				min = items[i];
				minLocation = i;
			}
		}

		for (int i = minLocation; i < numItems; i++)
		{
			items[i] = items[i + 1];
		}
		numItems--;
		return min;
	}

	bool empty()
	{
		if (numItems == 0)
			return true;
		else
			return false;
	}
};

void priorityQueueSort(int * numbers, int size)
{
	priorityQueue PQ;

	//Step 1:  insert each item from 'numbers' into PQ.
	for (int i = 0; i < size; i++)
	{
		PQ.insert(numbers[i]);
	}
	//Step 2:  Extract from PQ until PQ is empty, each time placing the extracted item into the numbers array, one after another.
	while (!PQ.empty())
	{
		for (int i = 0; i < size; i++)
		{
			numbers[i] = PQ.extractMin();
		}
	}
}

//For this part you will need to use the built in priority queue in the STL libary.
//The STL priority_queue is implemented using a "min heap".  Feel free to read about this on your own
//to understand why it is so fast.
//The STL priority_queue has the following methods:
// push(x), which adds x to the priority queue (this is like your "insert" method)
// pop(), which removes the highest value item from the priority queue
// top(), which returns the highest value item in the priority queue (but does not remove it).
// Run time:  Inserting 1 item into a min heap takes O(log n) time.  Extracting the biggest takes O(log n).
// Therefore, the run time of this sorting algorithm is O(n log n), and that is why it sorts a billion items so fast.
// Which "fast" sort is better?  Blaze sort (aka quick sort), or heap sort?

void heapSort(int * numbers, int size)
{
	priority_queue<int> PQ;

	//Step 1:  insert each item from 'numbers' into PQ.
	for (int i = 0; i < size; i++)
	{
		PQ.push(numbers[i]);
	}
	//Step 2:  Extract from PQ until PQ is empty, each time placing the extracted item into the numbers array, one after another.
	for(int i = 0; i < size; i++)
	{
		numbers[i] = PQ.top();
		PQ.pop();
	}
}


int main()
{
	//Part 1:  Implement a priority queue data structure
	priorityQueue pq;

	pq.insert(59);
	pq.insert(12);
	pq.insert(548);
	pq.insert(45);
	pq.insert(18);
	pq.insert(345);

	cout << "Extracting min: " << pq.extractMin() << endl; //12
	cout << "Extracting min: " << pq.extractMin() << endl; //18
	cout << "Extracting min: " << pq.extractMin() << endl; //45
	cout << "Extracting min: " << pq.extractMin() << endl; //59

	pq.insert(2);
	pq.insert(400);
	pq.insert(600);
	pq.insert(20);

	
	//2 20 345 400 548 600
	while (!pq.empty())
	{
		cout << "Extracting min: " << pq.extractMin() << endl;
	}

	
	//Part 2:  create a sorting function that uses your priority queue data structure to sort
	int numbers[] = { 53, 359, 31, 95, 345, 52, 13, 58, 2, 78 };

	priorityQueueSort(numbers, 10);

	for (int i = 0; i < 10; i++)	//should be in sorted order now
		cout << numbers[i] << endl;


	//Part 3:  Implement the "heap sort" algorithm using the STL built in priority queue.
	int size = 10; //replace with 10000000 to stress test and time
	int * bignums = new int[size];
	for (int i = 0; i < size; i++)
		bignums[i] = rand();

	clock_t start, end;

	start = clock();
	heapSort(bignums, size);
	end = clock();

	cout << "Heap sort took: " << end - start << " milleseconds." << endl;

	//comment out display for stress test
	for (int i = 0; i < size; i++)
		cout << bignums[i] << endl;

	return 0;
}