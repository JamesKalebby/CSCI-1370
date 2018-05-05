// hwk1csci137003.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	//print answers to the provided questions to screen

	cout << "Hello, I'm Joey Aleman";
	cout << endl;
	cout << endl;
	cout << "The most advanced math course I have taken was pre-cal - if memory serves me right. " << endl;
	cout << "I did not like it at the time and eventually dropped it mostly because the " << endl;
	cout << "instructor did not show me why it would be exciting or important.";
	cout << endl;
	cout << endl;
	cout << "A Computer Scientist is, to me, a person with many titles built into one. " << endl;
	cout << "They understand the workings of existing hardware and software and strive to improve on them and make entirely new ones" << endl;
	cout << "To me, a Computer Scientist should be a Philosopher as well " << endl;
	cout << "Taking care to think deeply about the implications a bit of new hard/software has built into it. ";
	cout << endl;
	cout << endl;
	cout << "My interest in Computer Science comes from many different angles. I have always been interested in technology. " << endl;
	cout << "As a kid, to my mothers dismay, I use to take apart my radios, cd players, desktops, etc. " << endl;
	cout << "Anything I could get my hands on would have its guts exposed, experimented on, and be mostly put back together. " << endl;
	cout << "My most recent interest, however, comes from new found fascination with the human brain, AGI, and topics like" << endl;
	cout << "The Uncanny Valley and free will. " << endl;
	cout << "I hope to get involved in the study of Cognitive Nueroscience from the perspective of a Computer Scientist.";
	cout << endl;
	cout << endl;
	cout << "A thing that people find interesting about me is that I speak Japanese at a pretty good level all while not speaking any spanish.";
	cout << endl;
	cout << endl;

	//start of loop
	loop:
	cout << "OK, enough about me - Let do some math! "<< endl;
	cout << "Give me a circles radius and I will give you it's area: ";

	//End of answers/Beginning of Math section

	double radius;
	double area;
	string yn;
    cin >> radius;
	area = ((radius * radius)*3.14159265359);
	cout << endl << "Easy! The area of this circle is: " << area << endl << endl;

	cout << endl << "Would you like to try another circle?" << endl;

	//loop for yes or no added here
	ynloop:

	cout <<"Please type y or n: " << endl << endl;
	cin >> yn;
	if (yn == "y")
	{
		goto loop;
	}
	else if (yn == "n")
	{
		return 0;
	}
	else {
		cout << endl << "I said type y or n. " << yn << " is not an option." << endl;
		goto ynloop;
	}

    return 0;
}

