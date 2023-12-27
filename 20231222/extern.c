#include <stdio.h>       // Library for printf

// Define a generic function that prints the value of val
int f() {
    // This function has no access to the global variable val
    // because it is not defined yet at this point
    // to access the global variable val we need to declare it
    // as extern in this function so that the compiler knows
    // that it is defined somewhere else and we want to use it
    extern int val;
    printf("f() %d\n",val);
}

// Define a global variable
// This variable is accessible from all functions
// in this file after this point and possibly in other files
int val = 10;

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
