#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

template <class T>
class stack
{
public:
	T * items;
	int capacity; //size of items array
	int numItems; //number of items currently in stack

	stack()
	{
		capacity = 5;
		items = new T[capacity];
		numItems = 0;
	}

	void resize(int n)
	{
		T * buffer = new T[n];
		for (int i = 0; i < numItems; i++)
		{
			buffer[i] = items[i];
		}
		delete[] items;
		items = buffer;
		capacity = n;abort
	}


	void push(T x)
	{
		//if (numItems == capacity) //uh oh, out of room
		//{
		//	resize(2*capacity); //let's double the capacity
		//}
		if (numItems == capacity)
		{
			resize(capacity * 2);
		}

		items[numItems] = x;
		numItems++;
	}

	T pop()
	{
		if (numItems <= capacity/4)
		{
			resize(capacity / 2);
		}
		numItems = numItems - 1;
		return items[numItems];
	}

	bool empty()
	{
		if (numItems == 0)
			return true;
		else
			return false;
	}

};

int main()
{
	//step 0: Implement basic push, pop, and empty methods.
	//For this step, you will just have a fixed size 5 array capacity.
	stack<string> dogStack;

	dogStack.push("Sammy");
	dogStack.push("Barffles");
	cout << dogStack.pop() << endl;
	dogStack.push("BilboDoggins");
	dogStack.push("Frodo");
	dogStack.push("Grendel");
	dogStack.push("Walter");
	cout << dogStack.pop() << endl;
	cout << dogStack.pop() << endl;
	dogStack.push("Zelda");
	dogStack.push("Katie");

	while (!dogStack.empty())
		cout << dogStack.pop() << endl;

	//step 1:  Modify your push routine so that it checks if array is at capacity before
	//adding a new item to the array.  If the array is full, call a 'resize(int biggerSize)' method
	//to make more room before adding the new item.

	stack<string> pancakes;

	pancakes.push("mustard");
	pancakes.push("captaincrunchy");
	pancakes.push("pokemon");
	pancakes.push("beef");
	pancakes.push("pita");
	pancakes.push("smurf"); 	//after pushing the 6th item, your resize should trigger
	pancakes.push("mightcore");
	pancakes.push("egg");
	pancakes.push("rotten");
	pancakes.push("tomato");
	pancakes.push("pizza");  //If you chose to double array capacity in the last resize, then after pushing the 11th item your resize will trigger again
	pancakes.push("carrot");
	pancakes.push("cheese");
	pancakes.push("cinamon");
	pancakes.push("chocochip");
	pancakes.push("blueberry");
	pancakes.push("strawberry");
	pancakes.push("original");

	cout << pancakes.pop() << endl; //original
	cout << pancakes.pop() << endl; //strawberry

	pancakes.push("banananana");
	cout << pancakes.pop() << endl; //bananananana
	cout << pancakes.pop() << endl; //blueberry

									//After you do step 3, check that the capacity decreases correctly as pancakes are eaten.
	while (!pancakes.empty())
	{
		cout << "capacity: " << pancakes.capacity << "  numitems: " << pancakes.numItems << ":: ";
		cout << "eating: " << pancakes.pop() << endl;
	}


	//step 3:  Modify your pop method so that if the stack drops below 25 percent full, it resizes down by half.
	//The purpose here is to ensure that your stack doesn't take up too much more memory than it needs at any given time.
	//You may set a minimum size (say 5) that the array will never drop below even if there are 0 items in the stack.
	//Check the output of the above while loop to verify that your stack capacity shrinks as items are popped.

	
	//Advanced stuff:
	//Now template your stack class so that your class will work for
	//any data type. (you will need to edit your step 1 test code so that it works with a templated stack class).

	stack<string> wordStack;
	wordStack.push("dog");
	wordStack.push("cat");
	wordStack.push("rat");
	cout << wordStack.pop() << endl;

	stack<int> numberStack;

	int size = 10000;
	for (int i = 0; i<size; i++)
		numberStack.push(i);

	while (!numberStack.empty())
		cout << "Popping number " << numberStack.pop() << endl;
		
}