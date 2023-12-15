// Include the header file with the function prototypes
#include "list.h"        // Library to use the lists

// Main function
int main() {
    // Define the head of the list
    struct Node* head = NULL;
    
    // Insert a node in the head of the list
    head = insert_head(head, 30);
    // Insert a node in the head of the list
    head = insert_head(head, 20);
    // Insert a node in the head of the list
    head = insert_head(head, 10);

    // Insert a node after the second node
    insert_after(head->next, 25);
    
    // Print the list
    print_list(head);

    // Delete the list
    delelte_list(head);

    // Return 0 to indicate success
    return 0;
}