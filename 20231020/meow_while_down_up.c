// Include the standard input/output library
#include <stdio.h>

// Main function
int main() {
    // Define a counter variable
    // to store the number of repetitions
    int i = 0;

    // The while loop checks the condition
    // at each iteration and repeats the code
    // until the condition is false
    while (i < 3)
    {
        // Make the cat meow
        printf("meow!\n");
        // Increase the counter
        i = i + 1;
    }

    // Return 0 to indicate success
    return 0;
}