// Include the standard input/output library
#include <stdio.h>

// Prototype of the common function to greet the user
// We now have 2 input parameters: name and greeting
// so we can select the greeting message
// and pass the user's name to the function
void greeting_name(char name[], char greeting[]);

// Main function
int main() {
    // Define the variable to save the user's name
    char name[100];
    // Ask the user to input his/her name
    printf("What's your name?\n");
    scanf("%s", name);

    // Call the function to say hello to the user
    greeting_name(name, "Hello");
    // Pretend to do some fundamental work for the user
    printf("I am doing some work for you...\n");
    // Call the function to say goodbye to the user
    greeting_name(name, "Goodbye");

    // Return 0 to indicate success
    return 0;
}

// Implementation of the common function to greet the user
void greeting_name(char name[], char greeting[]) {
    // Print the greeting message to the user
    printf("%s, %s\n", greeting, name);
}