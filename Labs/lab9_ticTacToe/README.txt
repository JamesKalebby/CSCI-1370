//Tic tac toe lab.  Topics:  2D arrays, classes.


// Part 1
//Implement the following specifications for a tic tac toe game object:

class tictactoeGame
{
    public:

        char boardConfig[3][3];   // two dimensional array stores current board configuration    
   
   	// Constructor:
        // set  boardConfig[i][j] to be ' ' (the space character)
        // for 0<= i <= 2, 0<= j <= 2   
        tictactoeGame(){}   

	//put an 'X' character at the given location          
        bool placeX(int x, int y){}

  	//put an 'O' character at the given location         
        bool placeO(int x, int y){}

	//set all positions to character ' '.
        void clear();

        // Return true if there are 3 'X' marks placed in a single
        // column, row, or diagnol.  Return false otherwise.
        bool xWins(){}

        // Return true if there are 3 'O' marks placed in a single
        // column, row, or diagnol.  Return false otherwise.      
        bool oWins(){}

        // Return true if there are either 3 'X' marks or 3 'O' marks
        // placed in a single column, row, or diagnol, or if the board is full.
 	// Return false otherwise.
        bool gameOver(){}

        // cout a nice looking picture of the board configuration 
        void display(){}


};


//Here is an example main program to give an idea how the above class is supposed to work.

int main()
{
    tictactoeGame mygame;
    
    mygame.placeX(1,1);
    mygame.placeO(2,1);
    mygame.placeX(0,2);
    mygame.placeO(2,2);
    
    mygame.display();
}

This should display something like:
   |   | X
-----------
   | X |  
-----------
   | O | O


// Part 2
Once you have implemented the tictactoeGame class, write a main program that uses a tictactoeGame to implement a game in which two players (you and a friend) take turns placing X’s and O’s onto the board.  After each turn, the current board configuration should be displayed, and once a player connects three of a kind, the game should end declaring that player the winner.

