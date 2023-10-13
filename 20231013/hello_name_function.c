// Include the standard input/output library
#include <stdio.h>

// Prototype of the function to say hello to the user
void hello_name();

int main(void)
{
    // Call the function to say hello to the user
    hello_name();

    // Return 0 to indicate success
    return 0;
}

// Implementation of the function to say hello to the user
void hello_name()
{
    // Define the variable to save the user's name
    char name[100];
    // Ask the user to input his/her name
    printf("What's your name?\n");
    scanf("%s", name);
    // Print the greeting message to the user
    printf("Hello, %s\n", name);
}