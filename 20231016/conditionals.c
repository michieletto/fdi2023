// Include the standard boolean library
#include <stdbool.h>
// Include the standard input/output library
#include <stdio.h>

// Define a function is_zero that 
// checks if an integer n is equal to zero
// or not and returns a boolean:
// - true if n is equal to zero
// - false if n is not equal to zero
bool is_zero(int n) {
    // Return if n is equal to zero
    return n == 0;
}

// Main function
int main() {
    // Define an integer variable a 
    // and assign it the value 2
    int a = 2;

    // Call the function is_zero to
    // check if a is equal to zero
    if (is_zero(a)) {
        // Print that a is equal to zero
        printf("a == 0\n");
    }
    // otherwise
    else {
        // Print that a is not equal to zero
        printf("a != 0\n");
    }

    // Return 0 to indicate success
    return 0;
}