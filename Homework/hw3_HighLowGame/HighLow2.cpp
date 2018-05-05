// HighLow2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <Windows.h>
using namespace std;



int aiGuess(int lowGuess, int highGuess)
{
	int guess = rand() % (highGuess - lowGuess + 1) + lowGuess;

	if (lowGuess == highGuess - 2)
	{
		guess = highGuess - 1;
	}
	else if (lowGuess == highGuess - 1)
	{
		guess = highGuess;
	}

	else if (guess == lowGuess || guess == highGuess)
	{
		while (guess == lowGuess || guess == highGuess)
		{
			guess = rand() % (highGuess - lowGuess + 1) + lowGuess;
		}
	}
		
	return guess;
}

int main()
{
	system("Color 02");
	srand(time(0));
	string username;
	int rangeBegin;
	int rangeEnd;
	string hlc;
	int counter = 1;

	cout << "Hello, U$ER!" << endl << "What can I call you by?" << endl;
	cin >> username;
	start:
	cout << "OK, " << username << " let's play a game!" << endl;

rangeErr:
	cout << "Pick a number, any number!" << endl;

rangeErr2:
	cin >> rangeBegin;
	if (!cin)
	{
		cin.clear();
		cin.ignore();
		goto rangeErr;
	}

	cout << "Awesome! Now give me an even bigger number: " << endl;

	rangeErr3:
	cin >> rangeEnd;

	if (!cin)
	{
		cin.clear();
		cin.ignore();
		goto rangeErr;
	}
	else if (rangeEnd == rangeBegin || rangeEnd == rangeBegin + 1 || rangeEnd < rangeBegin)
	{
		cout << "Try picking a bigger number:" << endl;
		goto rangeErr3;
	}
	cout << "OK now think of a number between " << rangeBegin << " and " << rangeEnd << " and I will try to guess it!" << endl;
	cout << "You can tell me if my guess is too high by typing 'high' and too low by typing 'low'" << endl;
	cout << "If I guess the right number please type 'correct'" << endl;
	cout << "Ready?" << endl;
	system("PAUSE");
	int highGuess = rangeEnd;
	int lowGuess = rangeBegin;

	//Guess within range
	int guess = aiGuess(lowGuess, highGuess);
	cout << "Is the number you are thinking of " << guess << endl;
	cin >> hlc;

	while (hlc != "correct")
	{
		if (hlc == "high")
		{
			highGuess = guess;
		}
		else if (hlc == "low")
		{
			lowGuess = guess;
		}
		else {
			cout << "Please type high, low, or correct" << endl;
			goto error;
		}
		counter++;
		guess = aiGuess(lowGuess, highGuess);
		cout << "Is the number you are thinking of " << guess << endl;
		error:
		cin >> hlc;
	}
	cout << "Woo! I knew I could do it, " << username << endl;
	if (counter == 1)
	{
		cout << "And it only took me 1 guess to get it right!" << endl;
	}
	else if (counter > 1)
	{
		cout << "And it only took me " << counter << " guesses to get it right!" << endl;
	}
	string yn;
	cout << endl << "Would you like to play again, " << username << "? Please type y or n: " << endl;
	ynError:
	cin >> yn;

	if (yn == "y")
	{
		counter = 1;
		goto start;
	}
	else if (yn == "n")
	{
		return 0;
	}
	else
	{
		cout << "Please type y or n" << endl;
		goto ynError;
	}

    return 0;
}

