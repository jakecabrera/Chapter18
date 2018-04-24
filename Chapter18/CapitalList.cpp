#include "CapitalList.h"

using namespace std;

// Constructor
CapitalList::CapitalList()
{
	head = nullptr;
}

// Destructor
CapitalList::~CapitalList()
{
	CapListNode *nodePtr;
	CapListNode *nextNode;

	nodePtr = head;

	// Delete all elements in the list
	while (nodePtr) {
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

// *********************************************************
// name:		append
// called by:	nobody
// passed:		char as the letter to append
// returns:		nothing
// calls:		nothing
// The append function will take a given character and add
// it to the end of the list.
// *********************************************************

void CapitalList::append(char c)
{
	CapListNode *newNode;
	CapListNode *nodePtr;

	// Allocate a new node and store the character
	newNode = new CapListNode(c);

	// If the list is empty, make newNode the first node
	if (!head) {
		head = newNode;
	}
	else {
		// Point to the beginning of the list
		nodePtr = head;

		// Go to the last node
		while (nodePtr->next) nodePtr = nodePtr->next;

		// append new node to the list
		nodePtr->next = newNode;
	}

	// update number of elements in the list
	numElements++;
}

// *********************************************************
// name:		insert
// called by:	nobody
// passed:		int as index to insert at 
//				char as letter to be inserted
// returns:		int as the result of the operation
// calls:		size
// The insert function will insert a capital letter at the
// specified index. Returns a 0 if operation was successful
// and a -1 otherwise.
// *********************************************************

int CapitalList::insert(int index, char c)
{
	// If the index is out of bounds, return from the function immediately
	if (size() != 0 && (index < 0 || index >= size())) return -1;

	CapListNode *newNode;
	CapListNode *nodePtr;
	CapListNode *previousNode;

	// Allocate new node with c
	newNode = new CapListNode(c);

	// character is to be inserted as the first element
	if (index == 0) {
		newNode->next = head;
		head = newNode;
	}
	// character is to be inserted somewhere further in the list
	else {
		nodePtr = head;
		previousNode = nullptr;

		// Traverse the list till you reach the correct position
		for (int i = 0; i < index; i++) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Insert new node
		previousNode->next = newNode;
		newNode->next = nodePtr;
	}

	// Update count of elements in the list
	numElements++;

	return 0;
}

// *********************************************************
// name:		remove
// called by:	nobody
// passed:		int as index to remove a letter from the list
// returns:		int as the result of the operation
// calls:		size
// The remove function deletes the node at the given index
// Returns a 0 if operation was successful and a -1 
// otherwise.
// *********************************************************

int CapitalList::remove(int index)
{
	// If the index is out of bounds, return from the function
	if (index < 0 || index >= size()) return -1;

	CapListNode *nodePtr;
	CapListNode *previousNode;

	// Point to the first node
	nodePtr = head;
	previousNode = nullptr;

	// Node to be removed is the first node
	if (index == 0) {
		head = head->next;
		delete nodePtr;
	}
	// Node to be removed is somewhere further in the list
	else {
		// Traverse the list to the given index
		for (int i = 0; i < index; i++) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Remove the node from the list
		previousNode->next = nodePtr->next;
		delete nodePtr;
	}

	// Update the count of elements in the list
	numElements--;

	return 0;
}

// *********************************************************
// name:		search
// called by:	nobody
// passed:		char as letter to get the position of
// returns:		int as the position of a searched letter
// calls:		size
// The search function traverses the list and checks for the
// given letter. If found, it returns the index where the
// letter was first found. Else, it returns -1.
// *********************************************************

int CapitalList::search(char c)
{
	// Start at the beginning of the list
	CapListNode *nodePtr = head;

	// traverse the list
	for (int i = 0; i < size(); i++) {
		// found c in the list. Return index found
		if (nodePtr->letter == c) return i;
		// c isn't here, keep on moving
		else nodePtr = nodePtr->next;		
	}

	// Didn't find c in the list
	return -1;
}

// *********************************************************
// name:		reverse
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		nothing
// The reverse function reverses the order of the list 
// *********************************************************

void CapitalList::reverse()
{
	CapListNode *nodePtr;
	CapListNode *nextNode;
	CapListNode *previousNode;

	// if the list is empty, do nothing
	if (!head) {
		return;
	}
	// Otherwise reverse the list
	else {
		nodePtr = head;
		nextNode = head->next;
		previousNode = nullptr;

		// Point the current node to the node before it
		nodePtr->next = previousNode;

		// traverse the list and point each node to the node
		// before it until all nodes are traversed
		while (nextNode) {
			previousNode = nodePtr;
			nodePtr = nextNode;
			nextNode = nextNode->next;

			nodePtr->next = previousNode;
		}

		// The nodePtr is now pointing to the end of the old list.
		// Point the head here to finish reversing the list.
		head = nodePtr;
	}
}

// *********************************************************
// name:		displayList
// called by:	nobody
// passed:		nothing
// returns:		nothing
// calls:		nothing
// The print function will print the contents of the list
// in order to the console
// *********************************************************

void CapitalList::print() const
{
	CapListNode *nodePtr = head;	// point to the beginning of the list

	// Traverse the list and print each letter
	while (nodePtr) {
		cout << "[" << nodePtr->letter << "] ";
		nodePtr = nodePtr->next;
	}

	cout << endl;
}

// *********************************************************
// name:		size
// called by:	get
//				search
//				remove
//				insert
// passed:		nothing
// returns:		int as the number of elements in the list
// calls:		nothing
// The size function returns the amount of elements stored
// in the list.
// *********************************************************

int CapitalList::size() const
{
	return numElements;
}

// *********************************************************
// name:		get
// called by:	nobody
// passed:		int as index of wanted element
// returns:		char as element in list
// calls:		size
// The get function will retrieve the Letter at the specified
// index of the list. If out of bounds, it returns a null char
// *********************************************************

char CapitalList::get(int index) const
{
	// If the index is out of bounds, return from the function
	if (index < 0 || index >= size()) return 0;

	// Traverse list to the specified element
	CapListNode *nodePtr = head;

	for (int i = 0; i < index; i++) {
		nodePtr = nodePtr->next;
	}

	// return the letter at the index given
	return nodePtr->letter;
}
