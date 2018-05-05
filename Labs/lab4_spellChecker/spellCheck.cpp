
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function that loops through an array to check if there is a match

string spellCheck(string word1, string dictArray1[])
{
	for (int i = 0; i <= 203839; i++)
	{
		if (word1 == dictArray1[i])
		{
			return "That is spelled Correctly!";
		}
	}
	return "Bad User! That's incorrect!";
}

int main()
{
	//open .txt file and create an array from it's contents
	string * dictArray = new string[203839];
	ifstream dictionary;
	dictionary.open("largedictionary.txt");
	
	for (int i = 0; i < 203839; i++)
	{
		dictionary >> dictArray[i];
	}

	

	//welcome user to program
	cout << "Welcome to Spell Check Max Ultra!!!" << endl;
	cout << "You may exit this program at any point by typing 'exit' (which is how you spell exit)" << endl << endl;

	loop:
	//get a word from the user
	string word;
	cout << endl << "Enter a word you would like checked:" << endl << ">";
	cin >> word;
	if (word == "exit")
	{
		return 0;
	}

	//call spellCheck function to check for a match inside an if function
	cout << spellCheck(word, dictArray) << endl;

	goto loop;
return 0;
}