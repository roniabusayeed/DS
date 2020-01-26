#include "linkedlist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


// Creates a linked list with just one node with given data (argument passed)
Node* Create(int number)
{
    Node* node = malloc(sizeof(Node));

    // Check if we've run out of memory, though unlikely
    if(!node)
    {
        printf("Couldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    node->number = number;
    node->next = NULL;
    return node;
}

// Searches a linked list to find a node with matching data (second argument passed).
// Returns true if found a match, false otherwise.
bool Search(const Node* list, int number)
{
    for (const Node* cursor = list; cursor != NULL; cursor = cursor->next)
    {
        if (cursor->number == number)
        {
            return true;
        }
    }
    return false;
}

// Inserts a new node with given data (second argument passed) at the start of the linked list.
// Returns pointer to newly created linked list with added node.
Node* Insert(Node* list, int number)
{
    Node* node = malloc(sizeof(Node));

    // Check if we've run out of memory, though unlikely
    if(!node)
    {
        printf("Couldn't allocate memory\n");
        exit(EXIT_FAILURE);
    }

    node->number = number;
    node->next = list;
    return node;
}

// Removes the first occurrence of the node with matching data (second argument passed).
// Changes nothing if there is no occurrence of the node with matching data.
// Returns pointer to the linked list with removed node.
Node* Remove(Node* list, int number)
{
    // Handle empty list
    if (!list) return NULL;

    // Take care of the first node separately because we will be looking ahead afterwards.
    if (list->number == number)
    {
        Node* temp = list->next;
        free(list);
        return temp;
    }

    // Look one step ahead (of the cursor) for a node with matching data so that when the desired
    // node is found (if at all) the cursor is not too far gone to come back to stitch together the
    // two pieces of linked list after removing the node.
    for (Node* cursor = list; cursor->next != NULL; cursor = cursor->next)
    {
        if (cursor->next->number == number)
        {
            Node* temp = cursor->next->next;
            free(cursor->next);
            cursor->next = temp;

            break;  // Don't wanna keep deleting every other occurrences that might exist.
        }
    }
    return list;
}

// Deletes the entire linked list. Returns pointer to the (now) empty list.
Node* Destroy(Node* list)
{
    while (list)
    {
        Node* temp = list->next;
        free(list);
        list = temp;
    }
    return NULL;
}
