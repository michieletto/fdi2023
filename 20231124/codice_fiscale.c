// codice_fiscale.c
// Include the necessary libraries
#include <stdio.h>      // Input/output
#include <stdbool.h>    // Boolean
#include <ctype.h>      // Character functions

#define FISCAL_CODE_LEN 16    // The last character of the input string

/**
 * Check if the input string is in a valid format
 * for an Italian fiscal code (codice fiscale)
 * @param [in] input the input string
 * @return true if the input string is valid, false otherwise
**/
bool is_valid(char input[]) {
    // Loop over each character in the string
    for (int i = 0; i < FISCAL_CODE_LEN; i++) {
        // Check if the character should be a letter according to the pattern
        if (i < 6 || i == 8 || i == 11 || i == 15) {
            // If the character is not a letter
            if (input[i] < 'A' || input[i] > 'Z') {
                return false;
            }
        // otherwise, if the character should be a number according to the pattern
        } else {
            // If the character is not a digit
            if (input[i] < '0' || input[i] > '9') {
                return false;
            }
        }
    }
    return true;
}

// Main function
int main() {
    // Declare a character array to hold the input string
    char input[FISCAL_CODE_LEN+1];

    // Prompt the user to enter a string
    // we suppose that the user will enter  a string of the correct length
    // that will contain only uppercase letters and numbers
    printf("Enter a string: ");
    scanf("%s", input);

    // Check if the input string is valid
    // and print the result accordingly
    if (!is_valid(input)) {
        printf("Invalid\n");
    } else {
        printf("Valid\n");
    }

    return 0;
}