// camel.c
// Include the necessary libraries
#include <stdio.h>      // Input/output
#include <stdbool.h>    // Boolean
#include <ctype.h>      // Character functions

// Main function
int main() {
    // Declare a character array to hold the camel string
    char camel[100];
    // Declare a character array to hold the snake string
    char snake[200];

    // Prompt the user to enter a camel string
    printf("Enter a camel case string: ");
    scanf("%s", camel);

    // Declare a variable to hold the index of the snake string
    int snake_index = 0;
    // Loop over each character in the camel string
    for (int camel_index = 0; camel[camel_index] != '\0'; camel_index++) {
        // If the character is uppercase
        if (isupper(camel[camel_index])) {
            // If it is not the first character
            if (camel_index != 0) {
                // Add an underscore to the snake string
                snake[snake_index] = '_';
                // Increment the index of the snake string
                snake_index++;
            }
        }
        // Add the lower case version of the character to the snake string
        snake[snake_index] = tolower(camel[camel_index]);
        // Increment the index of the snake string
        snake_index++;
    }
    // Add the null character at the end of the snake string
    snake[snake_index] = '\0';

    // Print the snake string
    printf("Snake case string: %s\n", snake);
    
    // Return 0 to indicate success
    return 0;
}