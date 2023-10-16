// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
    // Define two integer variables
    int a, b;

    // Ask the user to input a
    printf("What's a?\n");
    scanf("%d", &a);

    // Ask the user to input b
    printf("what's b?\n");
    scanf("%d", &b);

    // Check if a is less than b
    if(a < b) {
        // Print that a is less than b
        printf("a<b\n");
    }
    // Check if a is greater than b
    if (a>b) {
        // Print that a is greater than b
        printf("a>b\n");
    }
    // Check if a is equal to b
    if (a==b) {
        // Print that a is equal to b
        printf("a==b\n");
    }
    
    // Return 0 to indicate success
    return 0;
}