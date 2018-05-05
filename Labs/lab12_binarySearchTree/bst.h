#pragma once
#include <iostream>
#include <fstream>
#include <string> 
using namespace std;

class node
{
public:
	string data;
	node * left;
	node * right;
	int counter;

	node(string x)
	{
		data = x;
		left = NULL;
		right = NULL;
		counter = 1;
	}
};

class bst
{
public:
	node * root;
	int counter = 0;

	bst()
	{
		root = NULL;
	}

	void recInsert(node * &p, string x)
	{
		if (p == NULL)
		{
			p = new node(x);
		}
		else
		{
			if (x < p->data)
			{
				recInsert(p->left, x);
			}
			else if (x > p->data)
			{
				recInsert(p->right, x);
			}
			else if (x == p->data)
			{
				p->counter++;
			}
		}
	}

	void insert(string x)
	{
		recInsert(root, x);
	}

	void recWrite(node * p, ofstream& output)
	{
		if (p == NULL)
		{
		}

		else
		{
			recWrite(p->left, output);
			output << p->data << " : " << p->counter << endl;
			recWrite(p->right, output);
		}
	}

	void write(ofstream& output)
	{
		recWrite(root, output);
	}
};