// Lab2csci137003.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	//Declare Variables
	int customerCounter;
	string name;
	string plan;
	int hpm;

	//Welcome User
	cout << "Welcome U$ER!" << endl;

	//Get names plans and hours from customers.txt
	ifstream inputFile;
	inputFile.open("customers.txt");

	ofstream outFile;
	outFile.open("billing.txt");

	//read number of customers into customerCounter from customers.txt
	inputFile >> customerCounter;

	while (customerCounter > 0)
	{
		//set up billing.txt
		
		inputFile >> name;
		inputFile >> plan;
		inputFile >> hpm;

		if (plan == "basic" && hpm <= 10)
		{
			outFile << name << " $9.95" << endl;
		}
		else if (plan == "basic" && hpm > 10)
		{
			outFile << name << " $" << " " << (9.95 + ((hpm - 10) * 2)) << endl;
		}
		else if (plan == "gold" && hpm <= 20)
		{
			outFile << name << " $14.94" << endl;
		}
		else if (plan == "gold" && hpm > 20)
		{
			outFile << name << " " << (14.95 + (hpm - 20)) << endl;
		}
		else if (plan == "platinum")
		{
			outFile << name << " $19.95" << endl;
		}
		else
		{
			cout << "error has occured" << endl;
		}
		customerCounter--;
	}
	
	cout << "task completed." << endl;
    return 0;
}