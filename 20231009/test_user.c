// Include the standard input/output library
#include <stdio.h>

// Main function
void main() {
    // Define the variable to save the user's name
    char name[30];
    // Ask the user to input his/her name
    printf("What's your name?\n");
    scanf("%s", name);
    // Print the user's name
    printf("Hello, %s\n", name);
}