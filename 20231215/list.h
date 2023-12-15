#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>      // Library for malloc, free, rand
#include <stdio.h>       // Library for printf

// Define the data structure node
// that contains an integer value
// and a link to the next node in the list
// that is a pointer to struct Node
// (if NULL is the last node of the list)
typedef struct Node
{
    int value;		    // data
    struct Node *next;	// link
} Node;

// Traverse the list to print the content on the screen
void print_list(struct Node *head);

// Create a new node with the value in input using dynamic allocation
struct Node* new_node(int value);

// Delete the list to free the allocated memory
void delete_list(struct Node* head);

// Insert a node in the head of the list
struct Node* insert_head(struct Node* head, int value);

// Insert a node after the node in input
void insert_after(struct Node* prev, int value);

// Insert a node in the tail of the list
struct Node* insert_tail(struct Node * head, int value);

/////////////////////// ADDITIONAL FUNCTIONS //////////////////////////
/////////////////////// FOR THE ORDERED LIST //////////////////////////

// Find the node before the value in input in the ordered list
struct Node* insert_sorted(struct Node *head, int value);

// Insert a node in the ordered list
struct Node* find_prev(struct Node *head, int value);

#endif // __LIST_H__