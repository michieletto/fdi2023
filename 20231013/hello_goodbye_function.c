// Include the standard input/output library
#include <stdio.h>

// Prototype of the functions to greet the user
// Hello
void hello_name(char name[]);
// Goodbye
void goodbye_name(char name[]);

// Main function
int main() {
    // Define the variable to save the user's name
    char name[100];
    // Ask the user to input his/her name
    printf("What's your name?\n");
    scanf("%s", name);

    // Call the function to say hello to the user
    hello_name(name);
    // Pretend to do some fundamental work for the user
    printf("I am doing some work for you...\n");
    // Call the function to say goodbye to the user
    goodbye_name(name);

    // Return 0 to indicate success
    return 0;
}

// Implementation of the function to say hello to the user
void hello_name(char to[]) 
{
    // Print the greeting message to the user
    printf("Hello, %s\n", to);
}

// Implementation of the function to say goodbye to the user
void goodbye_name(char name[]) 
{
    // Print the goodbye message to the user
    printf("Goodbye, %s\n", name);
}