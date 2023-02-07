/*
* File:   ABag.h
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your ABag. 
*
* <Devin_Miller_Bag_Assignment> -- Program that implements a dictionary using a bag. Able to add items, remove items, etc. from the bag.
* CSIS 215-<D02>
* <Citations if necessary> -- 
* Debuging help from:
* https://stackoverflow.com/questions/22724064/error-c2679-binary-no-operator-found-which-takes-a-right-hand-operand-of
* https://stackoverflow.com/questions/26825194/c-error-object-of-abstract-class-type-is-not-allowed-pure-virtual-function-h
* https://www.youth4work.com/Talent/Core-Java/Forum/118627-why-we-cant-create-an-object-for-abstract-class
*/
#ifndef ABAG_H
#define	ABAG_H

#include "book.h"
#include "bagADT.h"

template <typename E>
class ABag : public Bag<E> {
public:
	//Default constructor
	ABag() {
		capacity = 10; //Sets the capacity equal to 10 by default
		data = array; //Sets the pointer object equal to an array of 20 items
		used = 0; //Initiates used to be zero since there are no items in the bag
	};

	//Constructor with parameters
	ABag(const size_t size) {
		capacity = size; //Passes in the size from main
		data = array; //Sets the pointer object equal to an array of 20 items
		used = 0; //Initiates used to be zero since there are no items in the bag
	};

	//Checks how many items are currently in the bag
	int size() const {
		return used; //Returns the amount of items in the bag
	};

	//Empties all the items in the bag
	void emptyBag() {
		used = 0; //Sets used equal to zero
	};

	//Function that checks how many items can fit in the bag
	int bagCapacity() const {
		return capacity; //Returns the capacity
	};
	
	//Function to add an item to the bag
	bool addItem(const E& item) { 
		if (used < capacity) //Checks if there is room in the bag
		{
			data[used] = item; //Puts the item in the bag at the correct position
			used++; //Updates the amount of items in the bag
			return true;
		}
		else {
			return false;
		}
	};

	//Function that removes an item from the bag
	bool remove(E& item) {
		for (int i = 0; i < used; i++) { //Loop to get to the correct item
			if (data[i] == item) { //Compares the data in the array with the item
				item = data[i]; 
				used--; //Updates the amount in the bag
				return true;
			}
		}
		return false;
	};

	//Function that removes the top item from the bag
	bool removeTop(E& returnValue) {
		if (used > 0) { //Checks that there are items in the bag
			used--; //Updates the amount of items in the bag
			returnValue = data[used];
			return true;
		}
		return false;
	}; 

	//Function that finds a specific item in the bag
	bool find(E& returnValue) const { 
		for (int i = 0; i < used; i++) { //Loops through the bag until the item is found
			if (data[i] == returnValue) { //If the item is found 
				returnValue = data[i];
				return true; //Return true if the item is found
			}
		}
		return false;
	}; 

	//Function that checks the top element in the bag
	bool inspectTop(E& item) const { 
		if (used > 0) { //Checks to make sure there are elements in the bag
			for (int i = 0; i < used; i++) { //Loops through the items
				item = data[i];
			}
			return true; //Returns true when the correct item is found
		}
		else {
			return false;
		}
	};

	//Overload function that adds items to the bag
	bool operator+=(const E& addend) {
		if (addItem(addend)) { //Uses the add item function to add an item
			return true; //Returns true if the item was added to the bag
		}
		else {
			return false;
		}
	}; 

	//Default destructor
	~ABag() {};

private:
	E *data;		 // an array of items
	int used; 	 // number of items the data array currently holds
	int capacity;    // the number of items the bag can hold (size of array)
	E array[20];
};

#endif	/* ABAG_H */

