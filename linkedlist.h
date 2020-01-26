#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdbool.h>


// Defines a single node in a linked list
typedef struct Node
{
	int number;	// Use any arbitrary data here.
	struct Node* next;
} Node;


// Interface of linked list data structure:


// Creates a linked list with just one node with given data (argument passed)
Node* Create(int number);

// Searches a linked list to find a node with matching data (second argument passed).
// Returns true if found a match, false otherwise.
bool Search(const Node* list, int number);

// Inserts a new node with given data (second argument passed) at the start of the linked list.
// Returns pointer to newly created linked list with added node.
Node* Insert(Node* list, int number);

// Removes the first occurrence of the node with matching data (second argument passed).
// Changes nothing if there is no occurrence of the node with matching data.
// Returns pointer to the linked list with removed node.
Node* Remove(Node* list, int number);

// Deletes the entire linked list. Returns pointer to the (now) empty list.
Node* Destroy(Node* list);


#endif // LINKED_LIST
