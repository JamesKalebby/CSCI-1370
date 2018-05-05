#include "stdafx.h"
#include <iostream>

using namespace std;

class stack
{
public:
	int numItems;
	double items[50];

	stack()
	{
		numItems = 0;
	}

	void push(double n)
	{
		items[numItems] = n;
		numItems++;
	}

	double pop()
	{
		numItems--;
		return items[numItems];
	}
};

class Calculator
{
public:

	double total;
	stack undoStack;
	stack redoStack;

	Calculator()
	{
		total = 0;
		undoStack.push(total);
	}


	Calculator(double n)
	{
		total = n;
		undoStack.push(total);
	}

	void clear()
	{
		total = 0;
	}

	void add(double n)
	{
		total = total + n;
		undoStack.push(total);
	}

	void divide(double n)
	{
		total = total / n;
		undoStack.push(total);
	}

	void multiply(double n)
	{
		total = total * n;
		undoStack.push(total);
	}

	void subtract(double n)
	{
		total = total - n;
		undoStack.push(total);
	}

	double display()
	{
		return total;
	}

	Calculator operator+(const Calculator &other)
	{
		double result = total + other.total;
		return result;
	}

	double undo()
	{
		redoStack.push(total);
		total = undoStack.pop();
		return total;
	}

	double redo()
	{
		total = redoStack.pop();
		return total;
	}
	
};




int main()
{
	Calculator mycalc;
	mycalc.clear();
	mycalc.add(4.52);
	mycalc.add(3.789);
	mycalc.divide(2.6);
	mycalc.multiply(3.12);
	mycalc.subtract(2.678);
	cout << mycalc.display() << endl;       // prints out "7.2928"
	mycalc.clear();
	mycalc.add(5.0);
	cout << mycalc.display() << endl;       // prints out "5"

											//advanced stuff #1: add a constructor
	Calculator calc1;
	cout << calc1.display() << endl;  //prints out 0

									  //advanced stuff #2: add a parameterized constructor
	Calculator calc2(5);
	cout << calc2.display() << endl; //prints out 5


									 //The remaining portions of this assignment are intended for
									 //students that are shooting for an ‘A’ in the course.
									 //Before messing with the stuff below, be sure you have mastered
									 //the material above.


									 //advanced stuff #3: Define calculator addition (overload the '+' operator) (see: http://lmgtfy.com/?q=+c%2B%2B+operator+overloading)
	Calculator calc3(7);
	calc1 = calc2 + calc3;
	cout << calc1.display() << endl;  //prints out 12

									  //advanced stuff #4:  Create an 'undo' method for the calculator
	mycalc.undo();
	mycalc.undo();
	cout << mycalc.display() << endl;  //prints out 7.2928

		   							   //advanced stuff #5:  Create a 'redo' method for the calculator
	mycalc.redo();
	mycalc.redo();
	cout << mycalc.display() << endl;  //prints out 5

	return 0;
}

