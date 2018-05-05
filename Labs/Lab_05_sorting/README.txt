int main()
{
	int numbers[] = { 52, 17, 38, 58, 1238, 4, 13, 53, 12 ,85, 11, 388, 3, 0, 19 };

	//locate smallest should return the index
	//of the smallest number in the array
	//between the given range (inclusive)
	cout << locateSmallest(numbers, 0, 14) << endl; // 13
	cout << locateSmallest(numbers, 5, 8) << endl; // 5


	//print items in array
	printItems(numbers, 15); //should print 52, 17, 38...etc.

	//sort given array
	sort(numbers, 15);

	printItems(numbers, 15); //should print 0, 3, 4, ...etc.

	return 0;
}