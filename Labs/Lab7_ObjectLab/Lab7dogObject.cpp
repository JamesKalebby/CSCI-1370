#include "stdafx.h"

#include<iostream>
#include<string>
using namespace std;

class dog
{
public:
	string name;
	double weight;
	string breed;

	//default
	dog()
	{
		breed = "mutt";
	}

	//name and weight
	dog(string b, double w)
	{
		breed = b;
		weight = w;
	}

	//weight
	dog(double w)
	{
		breed = "mutt";
		weight = w;
	}

	//breed
	void setBreed(string newBreed)
	{
		breed = newBreed;
	}

	//weight
	void setWeight(double w)
	{
		if (w < 0)
			weight = 0;
		else
			weight = w;
	}

	void speak()
	{
		cout << "I'm a " << weight << " lbs " << breed << endl;
	}

	void switchBodies(dog &n)
	{
		//weight switch
		double weight1 = n.weight; //fido
		double weight2 = weight; //bonnie
		weight = weight1;
		n.weight = weight2;

		//breed switch
		string b1 = breed;
		string b2 = n.breed;
		breed = b2;
		n.breed = b1;

	}

	dog mateWith(dog &n)
	{
		dog puppy;
		puppy.breed = breed + "-" + n.breed;
		puppy.weight = (weight + n.weight) / 2;
		return puppy;
	}

	void bite(dog &n)
	{
		weight = weight + 10;
		n.weight = n.weight - 10;
	}

	void operator++(int unused)
	{
		int result = weight = weight + 100;
	}

};



int main()
{
	//step 1: set up dog class, implement default constructors
	dog bonny;
	dog wimpy;

	//step 2: set two different parameterized constructors
	dog fido("rottweiler", 200);
	dog snuffles(15);

	//step 3: create "set" methods
	bonny.setBreed("pit bull");
	bonny.setWeight(500);

	//Make your "set" method such that
	//you can't set the dog's weight to be negative.
	wimpy.setWeight(-300);

	//step 4: create a speak method
	bonny.speak(); //I'm a 500 lbs pit bull
	wimpy.speak(); //I'm a 0 lbs mutt
	fido.speak();  //I'm a 200 lbs rottweiler
	snuffles.speak(); //I'm a 15 lbs mutt

					  //step 5: switch bodies!
	bonny.switchBodies(fido);

	bonny.speak(); //I'm a 200 lbs rottweiler
	fido.speak();  //I'm a 500 lbs pit bull

				   //step 6: love is in the air
	dog puppy;
	puppy = fido.mateWith(wimpy);

	puppy.speak(); //I'm a 250 lbs pit bull-mutt

				   //step 7: uh oh, they're fighting...
	puppy.bite(fido);
	puppy.speak(); //I'm a 260 lbs pit bull-mutt
	fido.speak();  //I'm a 490 lbs pit bull


				   //Advanced stuff (for students seeking an A)
				   //step 8: let's feed that puppy
	puppy++;
	puppy.speak(); //I'm a 360 lbs pit bull-mutt

	return 0;
}