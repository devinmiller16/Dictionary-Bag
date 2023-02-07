/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your Dictionary
*
* <Devin_Miller_Bag_Assignment> -- Program that implements a dictionary using a bag. Able to add items, remove items, etc. from the bag.
* CSIS 215-<D02>
* <Citations if necessary> --
* Debuging help from:
* https://stackoverflow.com/questions/22724064/error-c2679-binary-no-operator-found-which-takes-a-right-hand-operand-of
* https://stackoverflow.com/questions/26825194/c-error-object-of-abstract-class-type-is-not-allowed-pure-virtual-function-h
* https://www.youth4work.com/Talent/Core-Java/Forum/118627-why-we-cant-create-an-object-for-abstract-class
*/

#ifndef BDICTIONARY_H
#define	BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:
	//Default constructor
	BDictionary() {};

	//Constructor with parameters
	BDictionary(const size_t size) {
		dictionary = new ABag<KVpair<Key, E>>(size);
	};

	//Function that return the size of the dictionary by using the size funciton in ABag
	int size() {
		return dictionary->size();
	}

	//Function that deletes all the items in the bag
	void clear() {
		dictionary->emptyBag(); //Has the dictionary point to the empty bag funciton
	}; 

	//Function that inserts a key and its value
	bool insert(const Key& k, const E& e) { //Passes in the key and corresponding value
		KVpair<Key, E> pair(k, e); //Creates an object pair of type KVpair
		if (dictionary->addItem(pair)) { //Adds this object via the add item function in ABag
			return true;
		}
		else {
			return false;
		}
	} 

	//Removes an item from the dictionary
	bool remove(const Key& k, E& rtnVal) { //Passes in the key an value to be returned
		KVpair<Key, E> pair(k, rtnVal); //Creates an object pair of type KVpair
		if (dictionary->remove(pair)) { //Removes this item via the remove function in ABag
			rtnVal = pair.value(); //Sets the return value equal to the item removed
			return true;
		}
		else {
			return false;
		}
	} 

	//Removes an item from the bag at random
	bool removeAny(E& returnValue) { //Passes in the return value to be removed
		KVpair<Key, E> pair; //Creates an object of type KVpair
		if (dictionary->removeTop(pair)) { //Removes the top item in the bag via the remove top funciton in ABag
			returnValue = pair.value(); //Sets the return value equal to the value that was deleted from the bag
			return true;
		}
		else {
			return false;
		}
	} 

	//Function that finds a specific item in the bag
	bool find(const Key& k, E& returnValue) const { //Passes in the key and value
		KVpair<Key, E> pair(k, returnValue); //Creates an object using these items of type KVpair
		if (dictionary->find(pair)) { //Uses the find function in ABag to find the object
			returnValue = pair.value(); //Sets the return value equal to the value that the value function in kvpair returns
			return true;
		}
		else {
			return false;
		}
	} 

	//Default destructor
	~BDictionary() {};

private:
	//Pointer to a ABag object.  You'll need to instantiate the bag in your constructor:
	// dictionary = new ABag<KVpair<Key, E>>(size) or something similar depending on how
	// you've implemented your ABag constructor(s).
	//This pointer gives you access to the bag which stores your data and provides the 
	//functions you need to build your dictionary.
	ABag<KVpair<Key, E>>* dictionary;
};


#endif	/* BDICTIONARY_H */

