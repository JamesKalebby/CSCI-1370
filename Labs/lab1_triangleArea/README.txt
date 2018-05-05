 

Topics: Input, Output, Math functions, Conditional statements.

 

Problem:

Part 1: The area of a triangle with sides of length a, b, and c, can be computed by the formula



where  s = (a + b + c)/2.  Write a program in C++ which will ask for the lengths of the three sides of a triangle, and output the area of the triangle.

 

The outline of the program looks like this:

 

     // Opening comments that describe the program

 

     #include <iostream>

     using namespace std;

 

     int main()

     {

           // declaration of variables

           // prompt for and read the lengths of the sides

           // compute the semiperimeter and area

           // display the input values and the resulting area

 

           return 0;

     }

 

For example, if you entered 7, 14, and 16 as the lengths, the program should compute 48.9228 as the area.  The output of the program should look similar to the following:

 


 The area of the triangle with sides  7, 14, and 16  is  48.9228

 

Test your program with the following data:

                        3,  4,  5           (answer is 6.0)

                        5, 12, 13        (answer is 30.0)

                        7, 14, 16        (answer above)

 

and 3 more of your own choosing.

 

Part 2:  Extend your program in the following way:  If the triangle is an Isoceles triangle, tell the user so.  If the triangle is is a “right” triangle, tell the user so.  If the triangle is equailateral, tell the user so.

 

 