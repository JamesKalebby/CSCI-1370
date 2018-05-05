
Topics: Conditionals, Loops, File IO

Write a program that computes the phone bills for a list of customers from a file.  Write a report of the bill to an output file.  Your bill is based on the number of hours of phone use, along with your package.  Here are the different packages:

--------------------------------------------------------------------------
Basic package:  For $9.95 per month 10 hours of access are provided.  Additional hours are $2.00 per hour.

Gold package: For $14.95 per month 20 hours of access are provided.  Additional hours are $1.00 per hour.

Platinum package:  For $19.95 per month unlimited access is provided.
--------------------------------------------------------------------------


Write a program that reads from a file called "customers.txt".  The first line of the file will be a number stating how many customers are listed in the file.  Each subsequent line will consist of a name, followed by a package type, followed by a number of phone hours used by that customer.  Here is an example:

5
Schweller gold 19
Garret platinum 59
Kolter platinum 12
Schwarzeneger basic 237
Hansen gold 23
 
As output, write to a file “billing.txt” a list of each customer followed by their total bill for the month.  For the above file, the corresponding output file should contain:
 
Schweller $14.95
Garret $19.95
Kolter $19.95
Schwarzeneger $463.95
Hansen $17.95