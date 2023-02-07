//<Devin_Miller_Bag_Assignment> -- Program that implements a dictionary using a bag. Able to add items, remove items, etc. from the bag.
//CSIS 215-<D02>
//<Citations if necessary> -- 
//Debuging help from:
//https://stackoverflow.com/questions/22724064/error-c2679-binary-no-operator-found-which-takes-a-right-hand-operand-of
//https://stackoverflow.com/questions/26825194/c-error-object-of-abstract-class-type-is-not-allowed-pure-virtual-function-h
//https://www.youth4work.com/Talent/Core-Java/Forum/118627-why-we-cant-create-an-object-for-abstract-class

#include <string>
#include <sstream>
#include "ABag.h"
#include "BDictionary.h"

using namespace std;

const size_t DICTIONARY_SIZE = 20;

void PauseScreen(); //Used to pause screen output

/*
* Tests BDictionary with int and string objects only.
*/
int main(int argc, char** argv) {

	cout << "Devin Miller -- CSIS 215 Programming Assignment 1 -- Bag Dictionary" << endl << endl;

	BDictionary<int, string> myIntStrDict(DICTIONARY_SIZE);
	BDictionary<string, int> myStrIntDict(DICTIONARY_SIZE);

	// myIntStrDict tests
	// INSERT: myIntStrDict
	cout << "Testing dictionary with <int, string> KV Pair\n";
	for (int i = 1; i <= DICTIONARY_SIZE; i++) {
		stringstream sn;
		sn << "Beth " << i * 10;
		myIntStrDict.insert(i * 10, sn.str());
	}
	cout << "INSERT: Size of myIntStrDict is " << myIntStrDict.size() << endl;

	// REMOVEANY: myIntStrDict
	string strData;
	if (myIntStrDict.removeAny(strData) == true) {
		cout << "REMOVEANY: My string data is " << strData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";

	// FIND: test for myIntStrDict.find
	int intKey = 40;
	if (myIntStrDict.find(intKey, strData) == true) {
		cout << "FIND: My data at key==" << intKey << " is: " << strData << "\n";
		cout << "Size of myIntStrDict is " << myIntStrDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << intKey << "\n";
	}

	// REMOVE: myIntStrDict
	intKey = 60;
	if (myIntStrDict.remove(intKey, strData) == true) {
		cout << "REMOVE: Removed key " << intKey << " which was " << strData << "\n";
	}
	else {
		cout << "Could not find key " << intKey << "\n";
	}
	cout << "Size of my dictionary is " << myIntStrDict.size() << "\n";

	// CLEAR: myIntStrDict
	myIntStrDict.clear();
	cout << "CLEAR: Size of myIntStrDict is " << myIntStrDict.size() << "\n\n";

	/* end myIntStrDict tests ---------------------------------------------*/

	// myStrIntDict tests
	// INSERT: myStrIntDict
	cout << "Testing dictionary with <string, int> KV Pair\n";
	myStrIntDict.insert("Terri", 57);
	myStrIntDict.insert("Beth", 53);
	myStrIntDict.insert("Jeremy", 19);
	myStrIntDict.insert("Nathan", 17);
	myStrIntDict.insert("Zipper", 2);
	myStrIntDict.insert("Button", 1);
	myStrIntDict.insert("Kiwi", 7);
	myStrIntDict.insert("Masoala", 10);

	cout << "INSERT: Size of myStrIntDict is " << myStrIntDict.size() << endl;

	// REMOVEANY: myStrIntDict
	int intData;
	if (myStrIntDict.removeAny(intData) == true) {
		cout << "REMOVEANY: My int data is " << intData << endl;
	}
	else {
		cout << "RemoveAny() failed -- dictionary is empty.\n";
	}
	cout << "Size of myIntStrDict is " << myStrIntDict.size() << "\n";

	// FIND: myStrIntDict.find
	string strKey = "Kiwi";
	if (myStrIntDict.find(strKey, intData) == true) {
		cout << "FIND: " << strKey << "\'s age is " << intData << endl;
		cout << "Size of myStrIntDict is " << myStrIntDict.size() << "\n";
	}
	else {
		cout << "Could not find a record at " << strKey << "\n";
	}

	// REMOVE: myStrIntDict
	strKey = "Button";
	if (myStrIntDict.remove(strKey, intData) == true) {
		cout << "REMOVE: Removed key " << strKey << " which was " << intData << "\n";
	}
	else {
		cout << "Could not find key " << strKey << "\n";
	}
	cout << "Size of my dictionary is " << myStrIntDict.size() << "\n";

	// CLEAR: myStrIntDict
	myStrIntDict.clear();
	cout << "CLEAR: Size of myStrIntDict is " << myStrIntDict.size() << "\n\n";

	/* end myStrIntDict tests ---------------------------------------------*/

	/* Demonstrate any Bag functions that were not used/demonstrated in the implemention 
	of your BDictionary and ABag using a Bag of KVpairs<int, string>. */

	ABag<KVpair<int, string>> myBag; //Used to test bag functions not previously demonstrated
	KVpair<int, string> pair1, pair2, pair3;
	pair1 = KVpair<int, string>(18, "Devin");
	pair2 = KVpair<int, string>(17, "Aidan");
	pair3 = KVpair<int, string>(16, "Regan");
	
	cout << "Testing my bag with KVpair<int, string>." << endl;
	cout << "Size of my bag is: " << myBag.size() << endl;
	if (myBag.addItem(pair1) == true) {
		cout << "ADD ITEM: After adding an item my bag size is: " << myBag.size() << endl;
	}
	else
		cout << "ADD ITEM: Failed" << endl;
	if (myBag.find(pair1) == true) {
		cout << "FIND: pair has been found" << endl;
	}
	else
		cout << "FIND: Failed" << endl;
	if (myBag.inspectTop(pair1) == true) {
		cout << "INSPECT TOP: Item found" << endl;
	}
	else 
	cout << "INSPECT TOP: Failed" << endl;

	cout << "ADD ITEM: Adding two more items to the bag." << endl;
	myBag.addItem(pair2);
	myBag.addItem(pair3);

	if (myBag.remove(pair2) == true) {
		cout << "REMOVE: Removed the second item from the bag." << endl;
	}
	else
		cout << "REMOVE: Failed" << endl;
	if (myBag.removeTop(pair1) == true) {
		cout << "REMOVE TOP: Removed the top item from the bag." << endl;
	}
	else
		cout << "REMOVE TOP: Failed" << endl;



	PauseScreen();

	return 0;
}

//Used to pause the screen wherever desired
void PauseScreen()
{
	char ch;
	cout << "\nPress the Enter key to continue ... ";
	cin.get(ch);
}