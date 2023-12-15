// Include the header file with the function prototypes
#include "list.h"        // Library to use the lists

/**
 * Traverse the list to print the content on the screen
 * @param [in] head pointer to the head of the list
*/
void print_list(struct Node *head) {
    // Iteration over the list
    // While the pointer to the node is different from NULL
    while (head != NULL) {
        // Print the value of the node
        printf("%d -> ", head->value);
        // and update the pointer to the next node
        head = head->next;
    }
    // Print NULL to indicate the end of the list
    printf("NULL\n");
}

/**
 * Create a new node with the value in input using dynamic allocation
 * @param [in] value value to insert in the node
 * @return pointer to the new node
**/
struct Node* new_node(int value) {
    // Dynamic allocation of the memory for the node
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    // If the allocation is successful
    if (node != NULL) {      
        node->value = value; // Set the value
        node->next = NULL;   // and the pointer to the next node
    }
    // Return the pointer to the new node
    return node;
}

/**
 * Delete the list to free the allocated memory
 * @param [in] head pointer to the head of the list
**/
void delete_list(struct Node *head) {
    // Create a pointer to the node to delete
    struct Node *current = NULL;
    // Iteration over the list
    while (head != NULL) {
        // Set the pointer to the node to delete
        current = head;
        // Update the pointer to the next node
        head = head->next;
        // Free the memory of the current node
        free(current);
    }
}

/**
 * Insert a node in the head of the list
 * @param [in] head pointer to the head of the list
 * @param [in] value value to insert in the node
 * @return pointer to the new head of the list
**/
struct Node* insert_head(struct Node* head, int value) {
    // Create a new node with the value in input
    struct Node* temp = new_node(value);
    // Set the pointer to the next node to the current head
    temp->next = head;
    // Return the pointer to the new head of the list
    return temp;
}

/**
 * Insert a node after the node in input
 * @param [in] prev pointer to the previous node in the list
 * @param [in] value value to insert in the node
 * if the node in input is NULL, exit without operations
**/
void insert_after(struct Node* prev, int value) {
    // If the node in input is NULL, exit without operations
    if (prev == NULL) {
        return;
    }
    // Create a new node with the value in input
    struct Node* temp = new_node(value);
    // Set the pointer to the next node to the next of the previous node
    temp->next = prev->next;
    // Set the pointer to the next of the previous node to the new node
    prev->next = temp;
}

/**
 * Insert a node in the tail of the list
 * @param [in] head pointer to the head of the list
 * @param [in] value value to insert in the node
 * @return pointer to the new head of the list
**/
struct Node* insert_tail(struct Node * head, int value) {
    // If the list is empty, insert in the head
    if (head == NULL) {
        // Just call the function to insert in the head
        return insert_head(head, value);
    }

    // Otherwise, I have to find the last node
    struct Node *last  = head;
    // the last node is the one that has the next node equal to NULL
    while (last->next != NULL) {
        // traverse the list until finding the last node
        last = last->next;
    }
    // Then, I can insert the new node after the last node
    insert_after(last, value);
    // Return the pointer to the head of the list
    return head;
}

/////////////////////// ADDITIONAL FUNCTIONS //////////////////////////
/////////////////////// FOR THE ORDERED LIST //////////////////////////

/**
 * Find the node before the value in input in the ordered list
 * @param [in] head pointer to the head of the ordered list
 * @param [in] value value to search in the ordered list
 * @return pointer to the node before the value in input
 * if the list is empty or the value is less than the value in the head, return NULL
**/
struct Node* find_prev(struct Node *head, int value) {
    // Define a pointer to the node to return, initialized to the head
    struct Node *prev = head;
    // If the list is empty or the value in input is less than
    // the value in the head, return NULL
    if ((prev == NULL) || (prev->value >= value))
        return NULL;
    // Otherwise, I have to find the node before the value in input in the list
    while ((prev->next != NULL) && (prev->next->value < value)) {
        // traverse the list until finding the node before the value in input
        prev = prev->next;
    }
    // Return the pointer to the node before the value in input (or NULL)
    return prev;
}

/**
 * Insert a node in the ordered list
 * @param [in] head pointer to the head of the ordered list
 * @param [in] value value to insert in the node
 * @return pointer to the new head of the ordered list
**/
struct Node* insert_sorted(struct Node *head, int value) {
    // Find the node before the value in input
    struct Node* prev = find_prev(head, value);
    // We have to distinguish two cases:
    if (prev == NULL) {
        // Insert in the head
        head = insert_head(head, value);
    } else {
        // Insert after the node before the value in input
        insert_after(prev, value);
    }
    // Return the pointer to the head of the list
    return head;
}