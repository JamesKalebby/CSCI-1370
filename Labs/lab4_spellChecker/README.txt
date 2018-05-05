 

Implement a spell checker.

Topics: Files, loops, functions, arrays

Write a program that repeatedly asks the user to enter a word.  After each word is entered, the program tells the user if the word is correctly spelled or not.

Sample run:

Welcome to the spell checker!  Please enter a word:

> apple

 

The word apple is spelled correctly!

Enter another word:

> snake

 

The word snake is spelled correctly!

Enter another word:

> compooter

 

WHOA!  compooter isn’t a word!  Bad human! Learn to spell!

> dinosore

 

WHOA! dinosore isn’t a word!  Bad human!  Learn to spell!

 

To solve this problem:  Download the following text file to your program directory.  This file is a dictionary listing ALL THE WORDS IN THE ENGLISH LANGUAGE:  largedictionary.txt

This file contains exactly 202,412 words (you may use this number to decide how big to make your array, if you like).

 

Suggestion:  Break the problem down into steps.  For example, you might implement the following “pseudo code”:

1)      Create a giant array.  Read each word in from the dictionary file and store the word in the array.

2)      Enter a loop in which you ask the user to enter a word.

a)       Check if the word entered is in your giant array of words. 

i)        If so, congratulate the user.

ii)       If not, berate the user for their flawed spelling.

 