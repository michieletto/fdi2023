// Include the standard input/output library
// Include the standard input/output library
#include <stdio.h>
// Include the standard boolean library
#include <stdbool.h>
// Include the standard character library
#include <ctype.h>

// Function to check if a character is a vowel
bool is_vocal(char c) {
    // Switch statement to check if the character is a vowel
    // the toupper function is used to convert the character to uppercase
    switch (toupper(c))
    {
    // the cases are the vowels
    // and they are all return true
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        return true;
    }
    // if the character is not a vowel 
    // (the function did not return yet),
    // then return false
    return false;
}

// Function to remove the vocals from a string
void remove_vocals(char s[]) {
    // Index to traverse the string
    int index = 0;
    // Index to store the position of the next non-vocal character
    int no_vocal_index = 0;
    // Traverse the string
    // until the end of the string ('\0') is reached
    while(s[index] != '\0') {
        // If the current character is not a vowel
        if (!is_vocal(s[index])) {
            // Store the current character in the position
            // of the next non-vocal character
            s[no_vocal_index] = s[index];
            // Increment the index of the next non-vocal character
            no_vocal_index++;
        }
        // In any case, increment the index of the current character
        index++;
    }
    // Add the end of string character ('\0') at the end of the string
    s[no_vocal_index]='\0';
}

// Main function
int main() {
    // Define a string to store the user input
    char s[256];
    // Ask the user for a string
    printf("Input: ");
    // Wait for the user input (no spaces in the string)
    scanf("%s", s);

    // Remove the vocals from the string
    remove_vocals(s);

    // Print the result
    printf("Output: %s\n", s);

    // Return 0 to indicate success
    return 0;
}