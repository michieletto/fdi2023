// Include the header file with the function prototypes
#include "list.h"        // Library to use the lists

// Main function
int main() {
    // Create three nodes statically
    struct Node n1;
    struct Node n2;
    struct Node n3;

    // Set the value and pointer for the first node
    n1.value = 10;
    n1.next = &n2;

    // Set the value and pointer for the second node
    n2.value = 20;
    n2.next = &n3;

    // Set the value and pointer for the third node
    n3.value = 30;
    n3.next = NULL;

    // Print the list
    print_list(&n1);

    // Return 0 to indicate success
    return 0;
}