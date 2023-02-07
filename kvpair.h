// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

/*
* <Devin_Miller_Bag_Assignment> --Program that implements a dictionary using a bag.Able to add items, remove items, etc.from the bag.
* CSIS 215 - <D02>
* <Citations if necessary> --
* Debuging help from :
* https://stackoverflow.com/questions/22724064/error-c2679-binary-no-operator-found-which-takes-a-right-hand-operand-of
* https://stackoverflow.com/questions/26825194/c-error-object-of-abstract-class-type-is-not-allowed-pure-virtual-function-h
* https://www.youth4work.com/Talent/Core-Java/Forum/118627-why-we-cant-create-an-object-for-abstract-class
*/

#ifndef KVPAIR_H
#define KVPAIR_H

// Container for a key-value pair
// Key object must be an object for which the == operator is defined.
// For example, int and string will work since they both have == defined,
// but Int will not work since it does not have == defined.
template <typename Key, typename E>
class KVpair {
private:
	Key k;
	E e;
public:
	// Constructors
	KVpair() {}
	KVpair(Key kval, E eval)
	{
		k = kval; e = eval;
	}
	KVpair(const KVpair& o)  // Copy constructor
	{
		k = o.k; e = o.e;
	}

	void operator =(const KVpair& o) // Assignment operator
	{
		k = o.k; e = o.e;
	}

	bool operator==(const KVpair& o) const {
		if (o.k == k) {
			return true;
		}
		return false;
	}
	
	// Data member access functions
	Key key() { return k; }
	void setKey(Key ink) { k = ink; }
	E value() { return e; }
};


#endif