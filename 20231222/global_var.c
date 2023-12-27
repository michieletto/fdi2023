#include <stdio.h>       // Library for printf

// Define a global variable
// This variable is accessible from all functions
// in this file and possibly in other files
int val = 10;

// Define a generic function that prints the value of val
void f() {
    // This function has access to the global variable val
    printf("f() %d\n",val);
}

// Main function
int main()
{
    // The main function has also access to the global variable val
    printf("main() %d\n",val);
    // Calling the function f() defined above we use the global variable val
    f();

    // Return 0 to indicate success
    return 0;
}
