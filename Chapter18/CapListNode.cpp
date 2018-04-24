#include "CapListNode.h"

using namespace std;

// Default constructor
CapListNode::CapListNode()
{
	letter = 0; // Empty character
	next = nullptr;
}

// Constructor to create a node with a capital letter
// or die trying.
CapListNode::CapListNode(char c)
{
	// Make sure we initialize this node with a capital letter
	if (!isupper(c)) {
		cout << "ERROR! Input is not a capital letter. Press [ENTER] to exit...";
		cin.ignore();
		cin.get();
		exit(EXIT_FAILURE);
	}

	// Capital letter guaranteed
	letter = c;
	next = nullptr;
}
