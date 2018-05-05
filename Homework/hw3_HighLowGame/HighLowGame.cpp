// HighLowGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;


int main()
{
	//Declaration of Variable-pendence
	srand(time(0));
	int rangeEnd;
	int userGuess;
	int guessCounter = 1;
	string username;
	

	//get username
	//generate a range of numbers that the user determines
	cout << "Hello, U$ER!" << " What can I call you by?" << endl;
	cin >> username;
	cout << "OK, " << username << "!" << endl;
	cout << "I wanna play a game!" << endl;
	
start:
	cout << "Give me a number, any number" << endl;
	cin >> rangeEnd;
	if (!cin)
	{
		cin.clear();
		cin.ignore();
		goto start;
	}

	//ask the user to guess the number
	cout << "Ok, awesome!" << endl << "I'm thinking of a number from 1 - " << rangeEnd << "!" << endl << "Let's see how many guesses it takes you!" << endl;
	
	//Calculate the random number between user selected range
	int guessMe = rand() % rangeEnd + 1;
	//cout << guessMe << endl;

	userGuessErr:
	cin >> userGuess;
	if (!cin)
	{
		cin.clear();
		cin.ignore();
		cout << "Whoops that isn't a valid number. Please try again: " << endl;
		goto userGuessErr;
	}

	//if the user is right the game ends
	// if the user is too high or too low, the program informs the user of that fact and asks for another guess
	//repeat until the user gets the number correct.

	while (userGuess != guessMe)
	{
		if (userGuess > guessMe)
		{
			cout << "Too High!" << endl;
			guessCounter++;
		}
		else if (userGuess < guessMe)
		{
			cout << "Too Low!" << endl;
			guessCounter++;
		}
		cin >> userGuess;
	}
		//Tell user what their score was and how well they did
	if (guessCounter == 1)
	{
		cout << "No -- Freaking -- Way! Only one guess!?!?" << endl << "is " << username << " your hacker alias?" << endl;
	}
	else if (guessCounter > 1 && guessCounter <= 4)
	{
		cout << "Wow! Impressive! it only took you " << guessCounter << " tries!" << endl;
	}
	else if (guessCounter == 5 || guessCounter == 6)
	{
		cout << "It only took you " << guessCounter << " guesses! That's a pretty good score!" << endl;
	}
	else if (guessCounter == 7 || guessCounter == 8)
	{
		cout << guessCounter << ", Not too bad, but I think you can do better.." << endl;
	}
	else if (guessCounter == 9 || guessCounter == 10)
	{
		cout << guessCounter << " tries! You can do better than that!" << endl;
	}
	else if (guessCounter > 10)
	{
		cout << guessCounter << " guesses? What a terrible score!" << endl << endl;
	}
	
	//ask user to play again
	string yn;
	cout << endl << "Would you like to try again, " << username << "? please type y or n:" << endl;
	ynErr:
	cin >> yn;
	if (yn == "y")
	{
		guessCounter = 1;
		goto start;
	}
	else if (yn == "n")
	{
		return 0;
	}
	else
	{
		cout << "Please type y or n: " << endl;
		cin.clear();
		cin.ignore();
		goto ynErr;
	}

    return 0;
}

