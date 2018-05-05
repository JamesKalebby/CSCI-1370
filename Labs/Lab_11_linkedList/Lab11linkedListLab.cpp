#include "stdafx.h"
#include <iostream>
#include <string>
#include "linkedList.h"
#include <algorithm>
using namespace std;


int main()
{
	//part 0:
	linkedList<string> list1;

	list1.addFront("pichacu");
	list1.addFront("elmo");
	list1.addFront("charmander");
	list1.addFront("ekans");

	list1.popFront();
	list1.popFront();

	list1.addFront("snorlax");

	list1.display(); //snorlax elmo pichacu


					 //part 1:  Implement an 'addAt(string x, int i)' method which inserts
					 //an item _after_ the first i items.  You may assume the given i
					 //is less or equal to the number of items currently in the list.
	list1.addAt("owlbear", 2);
	list1.display(); //snorlax elmo owlbear pichacu

	list1.addAt("demogorgan", 3);
	list1.display(); //snorlax elmo owlbear demogorgan pichacu


	list1.addAt("mindFlayer", 0);
	list1.display(); //mindFlayer snorlax elmo owlbear demogorgan pichacu


	list1.addAt("centaur", 6);
	list1.display(); //mindFlayer snorlax elmo owlbear demogorgan pichacu centaur



					 //part 2: implement "remove"
					 //Suggestion:  To remove an item, the key is locate
					 //the node right before the node you want to remove.
					 //So, recommended step #1:  locate the address of the node _before_ the node to be removed.  Say node * beforeDoomed points at this node.
					 //Step #2:  Now figure out how to get rid of the node given you have beforeDoomed.
					 //Also, be sure to consider special cases such as when the item to be removed is the first item (in which case there is no node before it).
	list1.remove("elmo");
	list1.remove("mindFlayer");
	list1.remove("centaur");

	list1.addFront("kobold");
	list1.addAt("stirge", 5);

	list1.display();    //kobold snorlax owlbear demogorgan pichacu stirge

	
						//part 3: implement "sort"
						//A basic sort such as selection sort is fine for this.
	
	list1.sort(&list1.head);

	list1.display(); //demogorgan kobold owlbear pichacu snorlax stirge

	
					 //(advanced) Part 4:  Template your class
	linkedList<double> list2;

	for (int i = 0; i<10000000; i++)
		list2.addFront(rand());

	list2.sort(&list2.head);
	list2.display();

	
	
	return 0;
}