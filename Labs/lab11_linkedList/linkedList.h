#include <iostream>
#include <string>
using namespace std;

template <class T>
class node
{
public:
	T data;
	node * next;
};

template <class t>
class linkedList
{
public:

	//attributes:  a pointer to first node in list
	node<t> * head;

	//constructor
	linkedList()
	{
		head = NULL;
	}

	//remove and return first item
	//in list.
	t popFront()
	{
		t output = head->data;

		//now, get rid of first item
		node<t> * doomedNode = head;
		head = head->next;

		//clean up memory leak
		delete doomedNode;

		return output;
	}

	void display()
	{
		node<t> * current;
		current = head;

		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}

	void addFront(t x)
	{
		if (head == NULL)
		{
			head = new node<t>;
			head->data = x;
			head->next = NULL;
		}
		else
		{
			node<t> * A = new node<t>;
			A->data = x;
			A->next = head;
			head = A;
		}
	}

	void addAt(t x, int i)
	{
		//create new nodes
		node<t> * current = head;
		node<t> * nN = new node<t>;
		nN->data = x;
		
		//locate the position in the linked list to insert our new node
		for (int j = 1; j < i; j++)
		{
			current = current->next;
		}

		//insert new node
		nN->next = current->next;
		current->next = nN;
	}

	void remove(t x)
	{
		if (head->data == x)
		{
			node<t> * doomed = head;
			head = head->next;
			delete doomed;
		}
		else
		{
			//create new node
			node<t> * beforeDoomed = head;

			//find the node in the position directly before the intended node to be removed
			while (beforeDoomed->next->data != x)
			{
				beforeDoomed = beforeDoomed->next;
			}

			//make new node to point at the doomedNode
			node<t> * nN = new node<t>;
			nN = beforeDoomed->next;

			//set beforeDoomed node to the node after the node that will be deleted
			beforeDoomed->next = nN->next;
			delete nN;
		}
		
	}

	node<t>* Merge(node<t>* first, node<t>* second)
	{
		node<t> *t1;
		node<t> *t2;
		node<t> *temp;

		// Return if first list is empty.
		if (first == NULL)
			return second;

		// Return if second list is empty.
		if (second == NULL)
			return first;

		t1 = first;

		// A loop to traverse the second list, to merge the nodes to first in sorted way.
		while (second != NULL)
		{
			// Taking head node of second list as t2.
			t2 = second;

			// Shifting second list head to the next.
			second = second->next;
			t2->next = NULL;

			// If the data value is lesser than the head of first list add that node at the beginning.
			if (first->data > t2->data)
			{
				t2->next = first;
				first = t2;
				t1 = first;
				continue;
			}

			// Traverse the first list.
		flag:
			if (t1->next == NULL)
			{
				t1->next = t2;
				t1 = t1->next;
			}
			// Traverse first list until t2->data more than node's data.
			else if ((t1->next)->data <= t2->data)
			{
				t1 = t1->next;
				goto flag;
			}
			else
			{
				// Insert the node as t2->data is lesser than the next node.
				temp = t1->next;
				t1->next = t2;
				t2->next = temp;
			}
		}

		// Return the head of new sorted list.
		return first;
	}

	void sort(node<t> **headRef)
	{
		node<t> *first;
		node<t> *second;
		node<t> *temp;
		first = *headRef;
		temp = *headRef;

		// Return if list have less than two nodes.
		if (first == NULL || first->next == NULL)
		{
			return;
		}
		else
		{
			// Break the list into two halves as first and second as head of list.
			while (first->next != NULL)
			{
				first = first->next;
				if (first->next != NULL)
				{
					temp = temp->next;
					first = first->next;
				}
			}
			second = temp->next;
			temp->next = NULL;
			first = *headRef;
		}

		// Implementing divide and conquer approach.
		sort(&first);
		sort(&second);

		// Merge the two part of the list into a sorted one.      
		*headRef = Merge(first, second);
	}
};