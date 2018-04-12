/**************************************
 *	Author: Jake Cabrera
 *	Date: 4/6/2018
 *	Programming Assignment Chapter 18
 **************************************/

#include <string>
#include <iostream>
#include "CapitalList.h"

using namespace std;

// Function prototypes
char getCapitalLetter();
int getIndex(CapitalList&);
void displayMenu();
int getMenuChoice();
void append(CapitalList&);
void insert(CapitalList&);
void remove(CapitalList&);
void search(CapitalList&);
void reverse(CapitalList&);
void display(CapitalList&);

int main() {
	CapitalList list;
	bool finished = false;

	// The menu and it's handling
	while (!finished) {
		displayMenu();
		switch (getMenuChoice())
		{
		case 1:
			append(list);
			break;
		case 2:
			insert(list);
			break;
		case 3:
			remove(list);
			break;
		case 4:
			search(list);
			break;
		case 5:
			reverse(list);
			break;
		case 6:
			display(list);
			break;
		case 7:
			finished = true;
			break;
		}
	}

	cout << "Program finished. Press [ENTER] to exit..." << endl;
	cin.get();

	return 0;
}

// *********************************************************
// name:		getCapitalLetter
// called by:	append
//				insert
//				search
// passed:		nothing
// returns:		char as a capital letter
// calls:		nothing
// The getCapitalLetter function asks for a capital letter
// until it receives a capital letter which it returns.
// *********************************************************

char getCapitalLetter() {
	bool validInput = false;
	char c;
	string input;

	// keep asking for input until given valid input
	do {
		// get input
		cout << "Enter a capital letter: " << flush;
		getline(cin, input);

		// check if only 1 character was entered
		if (input.length() == 1) {
			c = input[0];

			// check if the single character is a capital letter
			if (isupper(c)) {
				validInput = true;
			}
		}

		// Show error message if input is not valid
		if (!validInput) {
			cout << "ERROR! Input must be a single capital letter. Please try again..." << endl << endl;
		}
	} while (!validInput);

	return c;
}

// *********************************************************
// name:		getIndex
// called by:	insert
//				remove
// passed:		CapitalList
// returns:		int as a index within the given lists bounds
// calls:		CapitalList::size
// The getIndex function asks for, retrieves, and returns an
// integer that represents an index within the given list.
// *********************************************************

int getIndex(CapitalList &list) {
	// If the list is empty or of size 1, the only valid index
	// to return would be 0
	if (list.size() == 0 || list.size() == 1) {
		cout << "The only valid index to use here is 0, so we will use that." << endl;
		return 0;
	}

	bool validInput = false;
	int index;

	// keep asking for input until given valid input
	do {
		// get input
		cout << "Enter an index as an integer for the operation to be performed at: " << flush;
		cin >> index;

		// Validate input
		if (cin.good()) {
			// We got a valid integer, now let's check
			// if it's in our list's boundaries
			if (index >= 0 && index < list.size()) validInput = true;
			else cout << "ERROR! Input is out of the list bounds. Enter an integer between 0 and " << list.size() << "..." << endl << endl;
		}
		// Input wasn't able to fit into var index
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR! Input must be an integer. Please try again..." << endl << endl;
		}
	} while (!validInput);

	return index;
}

// *********************************************************
// name:		displayMenu
// called by:	main
// passed:		nothing
// returns:		nothing
// calls:		nothing
// The displayMenu function will display the list of options
// that the user can input to use the program.
// *********************************************************

void displayMenu() {
	cout << "Operations:" << endl;
	cout << "1. Append element" << endl;
	cout << "2. Insert element" << endl;
	cout << "3. Remove element" << endl;
	cout << "4. Search for element" << endl;
	cout << "5. Reverse list" << endl;
	cout << "6. Display list" << endl;
	cout << "7. Exit" << endl << endl;
}

// *********************************************************
// name:		getMenuChoice
// called by:	main
// passed:		nothing
// returns:		int as menu choice
// calls:		nothing
// The getMenuChoice function asks for, retrieves, and returns
// an integer representing a choice from the menu.
// *********************************************************

int getMenuChoice() {
	int choice;
	bool validInput = false;

	// keep asking for input until given valid input
	do {
		// get input
		cout << "Enter an option: " << flush;
		cin >> choice;

		// Validate input
		if (cin.good()) {
			if (choice > 0 && choice <= 7) validInput = true;
			else cout << "ERROR! Input must be an integer 1-7. Please try again..." << endl << endl;
		}
		// Input wasn't able to fit into var choice
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR! Input must be an integer 1-7. Please try again..." << endl << endl;
		}
	} while (!validInput);

	cin.ignore();
	cout << endl;

	return choice;
}

// *********************************************************
// name:		append
// called by:	main
// passed:		CapitalList
// returns:		nothing
// calls:		getCapitalLetter
//				CapitalList::append
// The append function asks for input from the user, validates
// input, and appends valid input to the end of the given list.
// *********************************************************

void append(CapitalList &list) {
	cout << "You have chosen to append a capital letter to the end of the list." << endl;
	char c = getCapitalLetter();

	// Append valid input to the list
	list.append(c);

	cout << "Letter '" << c << "' was added to the end of the list." << endl << endl;
}

// *********************************************************
// name:		insert
// called by:	main
// passed:		nothing
// returns:		nothing
// calls:		getIndex
//				getCapitalLetter
//				CapitalList::insert
// The insert function takes a given list and inserts a
// specified capital letter at a specified index within the
// list.
// *********************************************************

void insert(CapitalList &list) {
	cout << "You have chosen to insert a capital letter into the list." << endl;
	
	int index = getIndex(list);
	char c = getCapitalLetter();

	list.insert(index, c);

	cout << "Letter '" << c << "' was inserted at index " << index << endl << endl;
}

// *********************************************************
// name:		remove
// called by:	main
// passed:		CapitalList
// returns:		nothing
// calls:		getIndex
//				CapitalList::get
//				CapitalList::size
//				CapitalList::remove
// The remove function removes a Capital letter from the given
// list at a specified index.
// *********************************************************

void remove(CapitalList &list) {
	cout << "You have chosen to remove a capital letter from the list." << endl;

	// If the list is empty, then there's nothing to be done
	if (list.size() == 0) {
		cout << "However, the list is empty and there is nothing to remove..." << endl << endl;
		return;
	}

	int index = getIndex(list);

	cout << "Letter '" << list.get(index) << "' at index " << index << " will be removed from the list." << endl << endl;

	list.remove(index);
}

// *********************************************************
// name:		search
// called by:	main
// passed:		CapitalList
// returns:		nothing
// calls:		getCapitalLetter
//				CapitalList::search
// The search function will take a given list and tell the
// user the index of the first character found that matches
// the specified character to search for.
// *********************************************************

void search(CapitalList &list) {
	cout << "You have chosen to search the list for a capital letter." << endl;

	char c = getCapitalLetter();

	int index = list.search(c);

	if (index == -1) {
		cout << "The letter '" << c << "' was not found in the list..." << endl << endl;
	}
	else {
		cout << "The letter '" << c << "' was found at index " << index << endl << endl;
	}
}

// *********************************************************
// name:		search
// called by:	main
// passed:		CapitalList
// returns:		nothing
// calls:		CapitalList::reverse
// The reverse function will take a given list and reverse
// the order of its elements.
// *********************************************************

void reverse(CapitalList &list) {
	cout << "You have chosen to reverse the order of elements in the list." << endl;
	
	list.reverse();

	cout << "The list has successfully been reversed." << endl << endl;
}

// *********************************************************
// name:		display
// called by:	main
// passed:		nothing
// returns:		nothing
// calls:		CapitalList::print
// The display function displays the contents of the given
// list.
// *********************************************************

void display(CapitalList &list) {
	cout << "Below is the contents of the list:" << endl << endl;
	list.print();
	cout << endl;
}