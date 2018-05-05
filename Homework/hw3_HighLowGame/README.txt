CSCI/CMPE 1370

Homework #3

Due date: start of class.

 

Hand in:

Turn in a printout of your source code along with a printout of sample runs showing that your program works.

                                                            

HiLo Guessing Game

 

This assignment utilizes:

- random numbers

- loops

- conditional statements

- basic input/output

 

 

Write a program to play the Hi-Lo guessing game!  In particular, your program should:

 

·         Generate a random number from 1 to 100.

·         Ask the user to guess the number

·         If the user is right, the game ends

·         If the user's guess is too high or too low, the program informs the user of that fact and asks for another guess.

·         This repeats until the user gets the number correct.

 

Further, your program should keep track of how many guesses the user takes to get the number right.  An appropriate insult/compliment should then be issued to the user.  For example:

        11 or more "What a terrible score!..."

        9-10       "Not too shabby, but not too good either...

        7-8        "That's pretty good but you can do better..."

        5-6        "That's a very good score..."

        0-4        "Amazing! Or was it luck?"

 

Here is a sample run:

 

    Let’s play a Number Guessing Game!

    Guess a number between 1 and 100

    40

    Too low!!

    Guess a number between 1 and 100

    90

    Too high!!

    Guess a number between 1 and 100

    60

    Too high!!

    Guess a number between 1 and 100

    50

    Too low!!

    Guess a number between 1 and 100

    55

    Too low!!

    Guess a number between 1 and 100

    56

    You win!!

    It took you 6 guesses.

    That's a very good score...

 

 

Some Help (random numbers):  To generate a random number from 1-10 in c++, do the following:

First, “seed” the random number generator.  To do this, add #include <ctime> to the top of your program, and add the following command:

srand(time(0));

 

Now use “rand()” to generate “pseudo random numbers”.  Each call to rand() will generate a giant random number.  Take the result and get the remainder of this giant number modulus 10 using ‘rand() % 10’.  The remainder of any number when divided by 10 will be a number from 0 to 9.  Take the result and add 1 to it to get a number from 1-10:

srand(time(0));

int x1 = rand() % 10 + 1;   //will be something like 4

                int x2 = rand() % 10 + 1;   //will be something like 1

int x3 = rand() % 10 + 1;   //will be something like 6

 

 

Extra Credit 1 (10 extra points)

(This is easy, you might as well do it!)

 

Make the following improvements to your program:

 

·         Instead of always guessing from 1-100, ask the user to input the range of numbers to guess between.

·         Before playing, request some personal information about the user.  Then, during the game, have the program spew random comments at the user based on this information.

·         Make your program do something cool other than what is already listed.

 

 

Extra Credit 2 (50 extra points)

·         Write a second version of the Hi-Lo game, except that instead of the user guessing the number, the computer tries to guess a number the user is thinking of. That is, the computer makes a guess, and the user tells the program if the guess is too high or too low.

·         To get points for this version, your program should always guess the number within, say, 10 guesses.

 

 

 