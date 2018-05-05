#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;

int main()
{
	//open text file
	ifstream inputFile;
	inputFile.open("storyTime.txt");

	//create bst to hold words and output file
	bst storyTree;
	ofstream outputFile;
	outputFile.open("wordCount.txt");

	//insert words from file into bst
	string x;
	while (!inputFile.eof())
	{
		inputFile >> x;
		storyTree.insert(x);
	}

	//output the data
	storyTree.write(outputFile);





	return 0;
}