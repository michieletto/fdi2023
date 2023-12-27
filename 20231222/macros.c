#include <stdio.h>       // Library for printf

// Define a macro to square a number
// First version: multiply a by a directly
# define SQUARE_1(a) (a*a)
// Second version: use the parentheses to avoid errors
# define SQUARE_2(a) ((a)*(a))

// Main function
int main() {
    // Define two numbers
    int n1 = 1;
    int n2 = 2;

    // A first test of the macros
    printf("a = n1\n");
    // Print the output of the two versions
    printf("First version output is: %d\n", SQUARE_1(n1));  // 1 * 1 = 1
    printf("Second version output is: %d\n", SQUARE_2(n1)); // (1) * (1) = 1
    
    // A second test of the macros
    printf("\na = n1 + n2\n");
    // Print the output of the two versions
    printf("First version output is: %d\n", SQUARE_1(n1+n2)); // 1 + 2 * 1 + 2 = 5
    printf("Second version output is: %d\n", SQUARE_2(n1+n2));  // (1 + 2) * (1 + 2) = 9

    // Return 0 to indicate success
    return 0;
}