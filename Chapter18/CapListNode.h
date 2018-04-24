#pragma once
#include <stdlib.h>
#include <iostream>
#include <cctype>

class CapListNode
{
public:
	char letter;		// Value to hold
	CapListNode *next;	// Pointer to the next node

	// Constructors
	CapListNode();

	CapListNode(char);
};

