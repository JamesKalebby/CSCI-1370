
Binary Search Tree Lab
Topics:  Binary Search Trees (insertion, in-order traversal), File I/O

Input:  A text file with some words.  For simplicity you may assume the text is all in lowercase, and there is no punctuation.

Output:  An output file with a report displaying each distinct word occurring in the input file, in alphabetical order, along with the number of occurrences of each word.

Requirements:  You must implement this program using a binary search tree.  In particular, read in each word and insert it into a binary search tree.  If the word is found to already be present in the tree, then increment the “count” for the respective tree node.

Example input file text:

once upon a time there where three little pigs who lived in the big scary woods the pigs lived happily in their poorly built houses until one day a big bad wolf came along and blew up their houses and ate the three little pigs the end

Example output file text:

a : 2
along : 1
and : 2  
ate : 1
bad : 1
...etc...
pigs : 3
...etc...