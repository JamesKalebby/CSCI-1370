// Lab1csci137003.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	//Program cin's three sides of a triangle and then cout's the Area and the type (equilateral, isosolis, right)

	//variables
	double sA;
	double sB;
	double sC;
	double Area;
	double s;
	string yn;

	//Begin Prompt, Take data from user and calculate Area
	
start:
	cout << "Welcome U$ER! Please enter three sides of a triangle and press enter. " << endl;
	cin >> sA;
	cin >> sB;
	cin >> sC;
	s = ((sA + sB + sC) / 2);
	Area = sqrt(s * (s - sA) *(s - sB) * (s - sC));

	cout << "The area of the triangle is: " << Area << endl;

	//determine whether a triangle is isosceles, scalene, or equalateral using if statements
	if (sA == sB && sA == sC)
	{
		cout << "This is an Equalateral Triangle" << endl;
	}
	if (sA != sB && sA != sC && sB != sC)
	{
		cout << "This is a Scalene Triangle" << endl;
	}
	if (sA == sB && sA != sC)
	{
		cout << "This is an Isosceles Triangle" << endl;
	}
	if (sA == sC && sA != sB)
	{
		cout << "This is an Isosceles Triangle" << endl;
	}
	if (sC == sB && sC != sA)
	{
		cout << "This is an Isosceles Triangle" << endl;
	}

	cout << endl << endl << "Would you like to try again?" << endl << "Please type y or n: " << endl;
	cin >> yn;
	if (yn == "y")
	{
		goto start;
	}
	else if (yn == "n")
	{
		return 0;
	}
	else if (yn != "y" || "n")
	{
		return 0;
	}

    return 0;
}