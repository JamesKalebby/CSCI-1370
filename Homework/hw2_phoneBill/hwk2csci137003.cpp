// hwk2csci137003.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


int main()
{
	//declaration of variable-pendance
	string basic;
	string gold;
	string platinum;
	string plan;
	int hpm;
	string yn;

	//beginning of loop
start:

	//Social Engineer U$ER to get phone plan
	cout << "Welcome U$ER!" << endl << endl << "To calculate your phone bill please enter your plan type: " << endl;
	cin >> plan;
	cout << "How many hours have you used on your " << plan << " plan?" << endl;
	cin >> hpm;

	//Run if statements to calculate bill based on plan
	if (plan == "basic" && hpm <= 10)
	{
		cout << "Your bill will be 9.95 this month" << endl;
	}
	else if (plan == "basic" && hpm > 10)
	{
		cout << "Your bill will be " << (9.95 + ((hpm - 10) * 2)) << " this month " << endl;
	}
	else if (plan == "gold" && hpm <= 20)
	{
		cout << "Your bill will be 14.95 this month " << endl;
	}
	else if (plan == "gold" && hpm > 20)
	{
		cout << "your bill will be " << (14.95 + (hpm - 20)) << " this month." << endl;
	}
	else if (plan == "platinum")
	{
		cout << "Your bill is always 19.95 every month! Why do you bother checking?" << endl;
	}
	else {
		cout << "What are you? Some sort of wise guy?" << endl;
		return 0;
	}

	//loop for yes or no
ynloop:

	cout << "Please type y or n: " << endl << endl;
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
		goto ynloop;
	}

	return 0;
}